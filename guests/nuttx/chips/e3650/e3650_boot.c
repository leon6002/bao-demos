/****************************************************************************
 * semidrive/chips/e3650/e3650_boot.c
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#include <nuttx/config.h>
#include <nuttx/arch.h>
#include <nuttx/init.h>
#include <nuttx/irq.h>
#include <stdint.h>
#include "arm_internal.h"
#include "arm_tcm.h"
#include "arch/chip/chip.h"
#include "chip.h"

#define WDT9_REGBASE (0xF00B0000ul)
#define WDT_CTRL_WDT_EN ((uint32_t)0x01U << 1U)
#define WDT_CTRL_WDT_EN_SRC ((uint32_t)0x01U << 8U)

extern uint8_t _load_data_start[];
extern uint8_t _data_start[];
extern uint8_t _data_end[];

extern uint8_t _dma_buffer_start[];
extern uint8_t _dma_buffer_end[];

#ifdef CONFIG_BAO_GUEST
/* Per-CPU task/context storage for Bao guest mode.
 * Replaces CP15 TPIDRPRW, which is not accessible in guest VMs.
 */

uint32_t g_current_task_bao[CONFIG_SMP_NCPUS] = {0};

static inline void e3650_guest_init(void)
{
}

static inline void e3650_guest_start_core(uint32_t cpu, uint32_t addr)
{
  (void)cpu;
  (void)addr;
}
#endif

#if defined(CONFIG_BMP) || defined(CONFIG_SMP)
static void e3650_boot_puts(const char *str)
{
  while (*str != '\0')
    {
      up_putc(*str++);
    }
}

static void e3650_boot_log_cpu_up(int cpu)
{
  e3650_boot_puts("NX cpu ");
  up_putc('0' + cpu);
  e3650_boot_puts(" up\n");
}
#endif

#if defined(CONFIG_BMP)
extern void _sys_vector_start(void);
extern uint8_t _core0_percpu_data_start[];
extern uint8_t _core0_percpu_data_end[];
extern uint8_t _core0_percpu_bss_start[];
extern uint8_t _core0_percpu_bss_end[];
#if (CONFIG_NR_CPUS > 1)
extern uint8_t _core1_percpu_reserve_start[];
#endif
#if (CONFIG_NR_CPUS > 2)
extern uint8_t _core2_percpu_reserve_start[];
#endif
#if (CONFIG_NR_CPUS > 3)
extern uint8_t _core3_percpu_reserve_start[];
#endif
const unsigned long g_per_cpu_ram_base_addr[CONFIG_NR_CPUS] = {
	(unsigned long)_core0_percpu_data_start,
#if (CONFIG_NR_CPUS > 1)
	(unsigned long)_core1_percpu_reserve_start,
#endif
#if (CONFIG_NR_CPUS > 2)
	(unsigned long)_core2_percpu_reserve_start,
#endif
#if (CONFIG_NR_CPUS > 3)
	(unsigned long)_core3_percpu_reserve_start,
#endif
};
#endif

static inline_function void arm_custom_bss_init(void)
{
#if defined(CONFIG_BMP)
	uint32_t per_cpu_bss_start_offset = (uintptr_t)_core0_percpu_bss_start - (uintptr_t)_core0_percpu_data_start;
	uint32_t per_cpu_bss_len = (uintptr_t)_core0_percpu_bss_end - (uintptr_t)_core0_percpu_bss_start;
	uint32_t per_cpu_bss_end_offset = (uintptr_t)per_cpu_bss_start_offset + (uintptr_t)per_cpu_bss_len;

	memset(_core0_percpu_bss_start, 0, (uintptr_t)_core0_percpu_bss_end - (uintptr_t)_core0_percpu_bss_start);
#if (CONFIG_NR_CPUS > 1)
	memset((void *)((uintptr_t)_core1_percpu_reserve_start +
				(uintptr_t)per_cpu_bss_start_offset), 0, per_cpu_bss_len);
	up_flush_dcache((uintptr_t)_core1_percpu_reserve_start + (uintptr_t)per_cpu_bss_start_offset,
			(uintptr_t)_core1_percpu_reserve_start + per_cpu_bss_end_offset);
#endif
#if (CONFIG_NR_CPUS > 2)
	memset((void *)((uintptr_t)_core2_percpu_reserve_start +
				(uintptr_t)per_cpu_bss_start_offset), 0, per_cpu_bss_len);
	up_flush_dcache((uintptr_t)_core2_percpu_reserve_start + (uintptr_t)per_cpu_bss_start_offset,
			(uintptr_t)_core2_percpu_reserve_start + per_cpu_bss_end_offset);
#endif
#if (CONFIG_NR_CPUS > 3)
	memset((void *)((uintptr_t)_core3_percpu_reserve_start +
				(uintptr_t)per_cpu_bss_start_offset), 0, per_cpu_bss_len);
	up_flush_dcache((uintptr_t)_core3_percpu_reserve_start + (uintptr_t)per_cpu_bss_start_offset,
			(uintptr_t)_core3_percpu_reserve_start + per_cpu_bss_end_offset);
#endif
#endif /* CONFIG_BMP  */

	memset(_dma_buffer_start, 0, (uintptr_t)_dma_buffer_end - (uintptr_t)_dma_buffer_start);
	up_flush_dcache((uintptr_t)_dma_buffer_start, (uintptr_t)_dma_buffer_end);
}

static inline_function void arm_custom_data_load(void)
{
	if ((uintptr_t)_load_data_start != (uintptr_t)_data_start) {
		memcpy(_data_start, _load_data_start, (uintptr_t)_data_end - (uintptr_t)_data_start);
	}
}

static void e3650_wdt9_disable(void)
{
#ifndef CONFIG_BAO_GUEST
	/* Turn off WDT9 for default open in system01 */
	uint32_t regVal = getreg32(WDT9_REGBASE);

	putreg32(regVal & ~WDT_CTRL_WDT_EN, WDT9_REGBASE);
	modifyreg32(WDT9_REGBASE, 0, WDT_CTRL_WDT_EN_SRC);
#endif
}

/****************************************************************************
 * Name: arm_el_init
 *
 * Description:
 *   The function called from arm_head.S at very early stage for these
 * platform, it's use to:
 *   - Handling special hardware initialize routine which is need to
 *     run at high ELs
 *   - Initialize system software such as hypervisor or security firmware
 *     which is need to run at high ELs
 *
 ****************************************************************************/

void arm_el_init(void)
{
#ifndef CONFIG_BAO_GUEST
#ifdef CONFIG_ARCH_CHIP_E3650_TCM_ENABLE
	arm_tcm_init();
	arm_tcm_load();
#endif
#endif
	__asm__ __volatile__ ("isb" : : : "memory");
}

/****************************************************************************
 * Name: arm_boot
 *
 * Description:
 *   Complete boot operations started in arm_head.S
 *
 ****************************************************************************/

/* ISP R52 FREQ = 600M */
#define CPU_COUNTER_FREQUENCE (600000000U)

void arm_boot(void)
{
	int cpu = up_cpu_index();

#ifdef CONFIG_BMP
	int index;
	uint32_t percpu_data_size = (uint32_t)_core0_percpu_data_end - (uint32_t)_core0_percpu_data_start;
#endif

	e3650_wdt9_disable();

	if (cpu == 0) {
		arm_custom_data_load();
		arm_custom_bss_init();
	}

#ifndef CONFIG_BAO_GUEST
	e3650_init();
#else
  e3650_guest_init();
#endif

#ifdef CONFIG_ARCH_PERF_EVENTS
#ifndef CONFIG_BAO_GUEST
	up_perf_init((void *)CPU_COUNTER_FREQUENCE);
#endif
#endif

#ifndef CONFIG_BAO_GUEST
	up_enable_icache();
	/* TODO: memamp is not ready yet, disable d cache temporarily */
	// up_enable_dcache();
#endif

	if (cpu == 0) {
#ifdef CONFIG_BMP
		for (index = 1; index < CONFIG_BMP_NCPUS; index++) {
			memcpy((void *)(g_per_cpu_ram_base_addr[index]), (void *)(g_per_cpu_ram_base_addr[0]),
			       percpu_data_size);
		}

		for (index = 1; index < CONFIG_BMP_NCPUS; index++) {
#ifndef CONFIG_BAO_GUEST
			e3650_start_core(index, (uint32_t)_sys_vector_start);
#else
      e3650_guest_start_core(index, (uint32_t)_sys_vector_start);
#endif
		}
#endif
	}
#ifdef USE_EARLYSERIALINIT
	/* Perform early serial initialization if we are going to use the serial
   * driver.
   */

	arm_earlyserialinit();
#endif

#if defined(CONFIG_BMP) || defined(CONFIG_SMP)
	e3650_boot_log_cpu_up(cpu);
#endif
}
