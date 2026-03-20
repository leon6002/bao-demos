/****************************************************************************
 * semidrive/chips/e3650/e3650_irq.c
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

#include <stdint.h>
#include <sys/types.h>
#include <assert.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <nuttx/irq.h>

#include "arm_internal.h"

#include "arm_gic.h"

#define GICV3_PRIO_SHIF 3UL

#if defined(CONFIG_SMP)
#  define E3650_IRQ_NCPUS CONFIG_SMP_NCPUS
#elif defined(CONFIG_BMP)
#  define E3650_IRQ_NCPUS CONFIG_BMP_NCPUS
#else
#  define E3650_IRQ_NCPUS 1
#endif

#define INTSTACK_ALLOC (E3650_IRQ_NCPUS * INTSTACK_SIZE)

#if (defined(CONFIG_SMP) || defined(CONFIG_BMP)) && CONFIG_ARCH_INTERRUPTSTACK > 7
/* In the SMP configuration, we will need custom IRQ and FIQ stacks.
 * These definitions provide the aligned stack allocations.
 */

static uint64_t g_irqstack_alloc[INTSTACK_ALLOC >> 3];
static uint64_t g_fiqstack_alloc[INTSTACK_ALLOC >> 3];

/* These are arrays that point to the top of each interrupt stack */

const uintptr_t g_irqstack_top[E3650_IRQ_NCPUS] = { (uintptr_t)g_irqstack_alloc + INTSTACK_SIZE,
#if E3650_IRQ_NCPUS > 1
						   (uintptr_t)g_irqstack_alloc + (2 * INTSTACK_SIZE),
#endif
#if E3650_IRQ_NCPUS > 2
						   (uintptr_t)g_irqstack_alloc + (3 * INTSTACK_SIZE),
#endif
#if E3650_IRQ_NCPUS > 3
						   (uintptr_t)g_irqstack_alloc + (4 * INTSTACK_SIZE)
#endif
};

const uintptr_t g_fiqstack_top[E3650_IRQ_NCPUS] = { (uintptr_t)g_fiqstack_alloc + INTSTACK_SIZE,
#if E3650_IRQ_NCPUS > 1
						   (uintptr_t)g_fiqstack_alloc + 2 * INTSTACK_SIZE,
#endif
#if E3650_IRQ_NCPUS > 2
						   (uintptr_t)g_fiqstack_alloc + 3 * INTSTACK_SIZE,
#endif
#if E3650_IRQ_NCPUS > 3
						   (uintptr_t)g_fiqstack_alloc + 4 * INTSTACK_SIZE
#endif
};

#endif

/****************************************************************************
 * Name: up_get_intstackbase
 *
 * Description:
 *   Return a pointer to the "alloc" the correct interrupt stack allocation
 *   for the current CPU.
 *
 ****************************************************************************/

#if (defined(CONFIG_SMP) || defined(CONFIG_BMP)) && CONFIG_ARCH_INTERRUPTSTACK > 7
uintptr_t up_get_intstackbase(int cpu)
{
	return g_irqstack_top[cpu] - INTSTACK_SIZE;
}
#endif

/****************************************************************************
 * Name: up_init_irq
 *
 * Description:
 *   Init the IRQ specified by 'irq'
 *
 ****************************************************************************/

void up_init_irq(int irq, int irq_prio)
{
#ifdef CONFIG_BAO_GUEST
  /* In Bao guest mode, allow guest-visible SPI priority programming through
   * the virtual GIC distributor, but leave physical interrupt routing and
   * trigger ownership to Bao.
   */
#ifdef CONFIG_ARCH_IRQPRIO
	up_prioritize_irq(irq, irq_prio << GICV3_PRIO_SHIF);
#else
  (void)irq;
  (void)irq_prio;
#endif
#else
#ifdef CONFIG_ARCH_IRQPRIO
	up_prioritize_irq(irq, irq_prio << GICV3_PRIO_SHIF);
#endif
#endif
}

/****************************************************************************
 * Name: up_irq_is_enabled
 *
 * Description:
 *   Determine if an IRQ is enabled.
 *
 ****************************************************************************/

bool up_irq_is_enabled(int irq)
{
	return arm_gic_irq_is_enabled(irq);
}

#ifdef CONFIG_SMP
int up_send_smp_sched(int cpu)
{
  up_trigger_irq(GIC_SMP_SCHED, (cpu_set_t)1 << cpu);
  return OK;
}

void up_send_smp_call(cpu_set_t cpuset)
{
  up_trigger_irq(GIC_SMP_CALL, cpuset);
}
#endif

/****************************************************************************
 * Name: up_clear_irq
 *
 * Description:
 *   Clear the pending IRQ.
 *
 ****************************************************************************/

void up_clear_irq(int irq)
{
#ifdef CONFIG_BAO_GUEST
	/* Bao owns the physical GIC pending state for guest VMs. */
	(void)irq;
#else
	uint32_t index;
	uint32_t offset;
	uint32_t base;

	if (GIC_IS_SPI(irq)) {
		index = irq / GIC_NUM_INTR_PER_REG;
		offset = irq % GIC_NUM_INTR_PER_REG;
		modifyreg32(ICPENDR(CONFIG_GICD_BASE, index),
				 0, (1 << offset));
	} else {
		base = CONFIG_GICR_BASE + up_cpu_index() * CONFIG_GICR_OFFSET + GICR_SGI_BASE_OFF;
			modifyreg32(ICPENDR(base, 0), 0, (1 << irq));
		}
#endif
}
