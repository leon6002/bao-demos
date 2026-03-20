/****************************************************************************
 * chips/common/arm_tcm.c
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

#include <nuttx/compiler.h>

#include <arch/chip/chip.h>

#define CP15_IMP_ATCMREGIONR(r)  _CP15(0, r, c9, c1, 0)  /* TCM Region Registers A */
#define CP15_IMP_BTCMREGIONR(r)  _CP15(0, r, c9, c1, 1)  /* TCM Region Registers B */
#define CP15_IMP_CTCMREGIONR(r)  _CP15(0, r, c9, c1, 2)  /* TCM Region Registers C */

struct tcm_addr_s
{
  uint32_t tcma_addr;
  uint32_t tcmb_addr;
  uint32_t tcmc_addr;
};

static const struct tcm_addr_s g_tcm_addrs[4] =
{
  {
    CONFIG_CPU0_ATCM_START_ADDR,
    CONFIG_CPU0_BTCM_START_ADDR,
    CONFIG_CPU0_CTCM_START_ADDR,
  },
  {
    CONFIG_CPU1_ATCM_START_ADDR,
    CONFIG_CPU1_BTCM_START_ADDR,
    CONFIG_CPU1_CTCM_START_ADDR,
  },
  {
    CONFIG_CPU2_ATCM_START_ADDR,
    CONFIG_CPU2_BTCM_START_ADDR,
    CONFIG_CPU2_CTCM_START_ADDR,
  },
  {
    CONFIG_CPU3_ATCM_START_ADDR,
    CONFIG_CPU3_BTCM_START_ADDR,
    CONFIG_CPU3_CTCM_START_ADDR
  }
};

/****************************************************************************
 * Name: arm_tcm_ecc_init
 *
 * Description:
 *   Init TCM ECC
 *
 ****************************************************************************/
static void naked_function arm_tcm_ecc_init(unsigned long start,
                                            unsigned long end,
                                            uint32_t val0,
                                            uint32_t val1)
{
  /* The ATCM uses a 64-bit ECC chunk, while the BTCM and CTCM use
   * 32-bit ECC chunks. So init ECC with 8 bytes. */

  __asm__ __volatile__(
    "1:strd r2, [r0], #8\n"
    "cmp r0, r1 \n"
    "bne 1b \n"
    "bx lr \n"
    :::"memory", "cc"
  );
}

/****************************************************************************
 * Name: arm_tcm_init
 *
 * Description:
 *   Init TCM to enable access it
 *
 ****************************************************************************/
void arm_tcm_init(void)
{
  uint32_t regionr;
  uint32_t addr;
  int cpu;

  cpu = up_cpu_index();

#if defined(CONFIG_ATCM_SIZE) && (CONFIG_ATCM_SIZE != TCM_SIZE_NO_PRESENT)
  addr = g_tcm_addrs[cpu].tcma_addr;
  regionr = addr & TCM_BASEADDR_MASK;
  regionr |= CONFIG_ATCM_SIZE | TCM_ENABLEEL2 | TCM_ENABLEEL10;
  CP15_SET(IMP_ATCMREGIONR, regionr);
  arm_tcm_ecc_init(addr, addr + TCM_SIZE_NUM(CONFIG_ATCM_SIZE), 0, 0);
#endif /* ATCM_PRESENT */

#if defined(CONFIG_BTCM_SIZE) && (CONFIG_BTCM_SIZE != TCM_SIZE_NO_PRESENT)
  addr = g_tcm_addrs[cpu].tcmb_addr;
  regionr = addr & TCM_BASEADDR_MASK;
  regionr |= CONFIG_BTCM_SIZE | TCM_ENABLEEL2 | TCM_ENABLEEL10;
  CP15_SET(IMP_BTCMREGIONR, regionr);
  arm_tcm_ecc_init(addr, addr + TCM_SIZE_NUM(CONFIG_BTCM_SIZE), 0, 0);
#endif /* BTCM_PRESENT */

#if defined(CONFIG_CTCM_SIZE) && (CONFIG_CTCM_SIZE != TCM_SIZE_NO_PRESENT)
  addr = g_tcm_addrs[cpu].tcmc_addr;
  regionr = addr & TCM_BASEADDR_MASK;
  regionr |= CONFIG_CTCM_SIZE | TCM_ENABLEEL2 | TCM_ENABLEEL10;
  CP15_SET(IMP_CTCMREGIONR, regionr);
  arm_tcm_ecc_init(addr, addr + TCM_SIZE_NUM(CONFIG_CTCM_SIZE), 0, 0);
#endif /* CTCM_PRESENT */
}

/* Load data and text to TCM. TCM BSS loading is not necessary because
 * arm_tcm_init() clears the configured regions to zero.
 */

void arm_tcm_load(void)
{
}
