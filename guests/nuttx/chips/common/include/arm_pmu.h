/****************************************************************************
 * vendor/semidrive/chips/common/include/arm_pmu.h
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

#ifndef __CHIPS_E3650_COMMON_ARM_PMU_H
#define __CHIPS_E3650_COMMON_ARM_PMU_H

#include <stdint.h>
#include <nuttx/irq.h>
#include "sctlr.h"

/* Definition of PMUv3 events */

typedef enum pmu_event
{
    /* Software increment. The register is incremented only on writes to
     * the Software Increment Register (PMSWINC).
     */

    PMU_EVENT_SW_INCR                      = 0x000,

    /* L1 instruction cache refill */

    PMU_EVENT_L1I_CACHE_REFILL             = 0x001,

    /* L1 data cache refill */

    PMU_EVENT_L1D_CACHE_REFILL             = 0x003,

    /* L1 data cache access */

    PMU_EVENT_L1D_CACHE                    = 0x004,

    /* Instruction architecturally executed,
     * condition check pass - load.
     */

    PMU_EVENT_LD_RETIRED                   = 0x006,

    /* Instruction architecturally executed,
     * condition check pass - store.
     */

    PMU_EVENT_ST_RETIRED                   = 0x007,

    /* Instruction architecturally executed. */

    PMU_EVENT_INST_RETIRED                 = 0x008,

    /* Exception taken. */

    PMU_EVENT_EXC_TAKEN                    = 0x009,

    /* Instruction architecturally executed, condition code check pass,
     * exception return.
     */

    PMU_EVENT_EXC_RETURN                   = 0x00A,

    /* Instruction architecturally executed,
     * condition code check pass, write to CONTEXTIDR.
     */

    PMU_EVENT_CID_WRITE_RETIRED            = 0x00B,

    /* Instruction architecturally executed, condition check pass,
     * software change of the PC.
     */

    PMU_EVENT_PC_WRITE_RETIRED             = 0x00C,

    /* Instruction architecturally executed, immediate branch. */

    PMU_EVENT_BR_IMMED_RETIRED             = 0x00D,

    /* Instruction architecturally executed, condition code check pass,
     * procedure return.
     */

    PMU_EVENT_BR_RETURN_RETIRED            = 0x00E,

    /* Instruction architecturally executed, condition code check pass,
     * unaligned load or store.
     */

    PMU_EVENT_UNALIGNED_LDST_RETIRED       = 0x00F,

    /* Mispredicted or not predicted branch speculatively executed. */

    PMU_EVENT_BR_MIS_PRED                  = 0x010,

    /* Cycle */

    PMU_EVENT_CPU_CYCLES                   = 0x011,

    /* Predictable branch speculatively executed. */

    PMU_EVENT_BR_PRED                      = 0x012,

    /* Data memory access. */

    PMU_EVENT_MEM_ACCESS                   = 0x013,

    /* L1 instruction cache access. */

    PMU_EVENT_L1I_CACHE                    = 0x014,

    /* AXIM, Flash, or LLPP bus access. */

    PMU_EVENT_BUS_ACCESS                   = 0x019,

    /* Local memory error (instruction cache, data cache,
     * ATCM, BTCM, CTCM, or Flash).
     */

    PMU_EVENT_MEMORY_ERROR                 = 0x01A,

    /* Operation speculatively executed. */

    PMU_EVENT_INST_SPEC                    = 0x01B,

    /* Bus cycle (AXIM). */

    PMU_EVENT_BUS_CYCLES                   = 0x01D,

    /* For odd-numbered counters, increments the count by one for
     * each overflow of the preceding even-numbered counter.
     * For even-numbered counters, there is no increment.
     */

    PMU_EVENT_CHAIN                        = 0x01E,

    /* Instruction architecturally executed, branch. */

    PMU_EVENT_BR_RETIRED                   = 0x021,

    /* Instruction architecturally executed, mispredicted branch. */

    PMU_EVENT_BR_MIS_PRED_RETIRED          = 0x022,

    /* No operation issued due to the front end. */

    PMU_EVENT_STALL_FRONTEND               = 0x023,

    /* No operation issued due to the back end. */

    PMU_EVENT_STALL_BACKEND                = 0x024,

    /* Bus access - Read (AXIM, Flash, or LLPP). */

    PMU_EVENT_BUS_ACCESS_RD                = 0x060,

    /* Bus access - Write (AXIM, Flash, or LLPP). */

    PMU_EVENT_BUS_ACCESS_WR                = 0x061,

    /* Exception taken, supervisor call. */

    PMU_EVENT_EXC_SVC                      = 0x082,

    /* Exception taken, IRQ. */

    PMU_EVENT_EXC_IRQ                      = 0x086,

    /* Exception taken, FIQ. */

    PMU_EVENT_EXC_FIQ                      = 0x087,

    /* Exception taken, Hypervisor Call. */

    PMU_EVENT_EXC_HVC                      = 0x08A,

    /* Exception taken, IRQ not taken locally. */

    PMU_EVENT_EXC_TRAP_IRQ                 = 0x08E,

    /* Exception taken, FIQ not taken locally. */

    PMU_EVENT_EXC_TRAP_FIQ                 = 0x08F,

    /* External memory request, AXIM read. */

    PMU_EVENT_KITE_AXI_READ                = 0x0C0,

    /* External memory request, AXIM write. */

    PMU_EVENT_KITE_AXI_WRITE               = 0x0C1,

    /* External memory request, Flash (read-only). */

    PMU_EVENT_KITE_FLASH_READ              = 0x0C2,

    /* External memory request, LLPP read. */

    PMU_EVENT_KITE_LLPP_READ               = 0x0C3,

    /* External memory request, LLPP write. */

    PMU_EVENT_KITE_LLPP_WRITE              = 0x0C4,

    /* Non-cacheable external memory request, AXIM read. */

    PMU_EVENT_KITE_NC_AXI_READ             = 0x0C5,

    /* Non-cacheable external memory request, AXIM write. */

    PMU_EVENT_KITE_NC_AXI_WRITE            = 0x0C6,

    /* Non-cacheable external memory request, Flash (read-only). */

    PMU_EVENT_KITE_NC_FLASH_READ           = 0x0C7,

    /* L1 data cache refill because of prefetch (AXIM only). */

    PMU_EVENT_KITE_REFILL_PF_AXI           = 0x0C8,

    /* L1 data cache refill because of load or store, AXIM. */

    PMU_EVENT_KITE_REFILL_LS_AXI           = 0x0C9,

    /* L1 data cache refill because of load or store, Flash. */

    PMU_EVENT_KITE_REFILL_LS_FLASH         = 0x0CA,

    /* L1 data cache access in a way reserved for AXIM. */

    PMU_EVENT_KITE_DC_ACCESS_AXI           = 0x0CB,

    /* L1 data cache access in a way reserved for Flash. */

    PMU_EVENT_KITE_DC_ACCESS_FLASH         = 0x0CC,

    /* L1 instruction cache access in a way reserved for AXIM. */

    PMU_EVENT_KITE_IC_ACCESS_AXI           = 0x0CD,

    /* L1 instruction cache access in a way reserved for Flash. */

    PMU_EVENT_KITE_IC_ACCESS_FLASH         = 0x0CE,

    /* Non-cacheable external memory request because of
     * load was hinted, AXIM.
     */

    PMU_EVENT_KITE_NC_LS_HINTED_AXI        = 0x0CF,

    /* Non-cacheable external memory request because of
     * load was hinted, Flash.
     */

    PMU_EVENT_KITE_NC_LS_HINTED_FLASH_READ = 0x0D0,

    /* L1 Instruction cache refill, AXIM. */

    PMU_EVENT_KITE_REFILL_IC_AXI           = 0x0D1,

    /* L1 Instruction cache refill, Flash. */

    PMU_EVENT_KITE_REFILL_IC_FLASH         = 0x0D2,

    /* Non-cacheable external memory request because of load, AXIM. */

    PMU_EVENT_KITE_NC_LS_AXI_READ          = 0x0D3,

    /* Non-cacheable external memory request because of load, Flash. */

    PMU_EVENT_KITE_NC_LS_FLASH_READ        = 0x0D4,

    /* Conditional branch executed. */

    PMU_EVENT_KITE_COND_BR_RETIRED         = 0x0D5,

    /* Conditional branch mispredicted. */

    PMU_EVENT_KITE_MIS_PRED_COND_BR        = 0x0D6,

    /* BTAC branch executed. */

    PMU_EVENT_KITE_BTAC_BR_RETIRED         = 0x0D7,

    /* Conditional branch mispredicted. */

    PMU_EVENT_KITE_MIS_PRED_BTAC_BR        = 0x0D8,

    /* Instruction architecturally executed, MCR to VSCTLR. */

    PMU_EVENT_KITE_VSCTLR_CHANGED          = 0x0D9,

    /* Instruction architecturally executed, strong DSB, DFB. */

    PMU_EVENT_KITE_DSB_ALL_RETIRED         = 0x0DA,

    /* Simultaneous accesses from instruction side and
     * data side to AXIM (causing contention).
     */

    PMU_EVENT_KITE_SIMULT_ACCESS_AXI       = 0x0DB,

    /* Simultaneous accesses from instruction side and
     * data side to Flash (causing contention)
     */

    PMU_EVENT_KITE_SIMULT_ACCESS_FLASH     = 0x0DC,

    /* Exception taken to EL2 (hyp mode entry), excluding reset. */

    PMU_EVENT_KITE_EL2_ENTERED             = 0x0DD,

    /* Implementation defined event. CRS branch executed. */

    PMU_EVENT_KITE_CRS_BR_RETIRED          = 0x0DE,

    /* CRS branch mispredicted. */

    PMU_EVENT_KITE_MIS_PRED_CRS_BR         = 0x0DF,

    /* Correctable memory error occurred from any source
     *(L1 instruction cache, L1 data cache, ATCM, BTCM, CTCM, or flash).
     */

    PMU_EVENT_KITE_COR_ERR_MEM             = 0x0F0,

    /* Fatal memory error occurred from any source
     * (ATCM, BTCM, CTCM, or Flash).
     */

    PMU_EVENT_KITE_FAT_ERR_MEM             = 0x0F1,

    /* Correctable data payload bus error occurred from any source
     * (AXIM or LLPP).
     */

    PMU_EVENT_KITE_BUS_COR_DATA            = 0x0F2,

    /* Fatal non-protocol bus error (payload errors, except data)
     * occurred from any source (AXIM, Flash, or LLPP).
     */

    PMU_EVENT_KITE_BUS_FAT_OTHER           = 0x0F3,

    /* Fatal protocol bus error (LEN, ID, LAST, READY, and
     * interconnect protection errors) occurred from any source
     * (AXIM, Flash, or LLPP).
     */

    PMU_EVENT_KITE_BUS_PROTOCOL_ANY        = 0x0F4,

    /* Counts every cycle that the DPU IQ is empty and that is not
     * because of a recent instruction cache miss in any cache way.
     */

    PMU_EVENT_KITE_IQ_EMPTY_NO_MISS        = 0x100,

    /* Counts every cycle that the DPU IQ is empty and there is an
     * instruction cache miss being processed for a cache way
     * reserved for AXI Master.
     */

    PMU_EVENT_KITE_IQ_EMPTY_AXI_MISS       = 0x101,

    /* Counts every cycle that the DPU IQ is empty and there is an
     * instruction cache miss being processed for a cache way
     * reserved for Flash.
     */

    PMU_EVENT_KITE_IQ_EMPTY_FLASH_MISS     = 0x102,

    /* Counts every cycle there is an interlock that is not because of
     * an Advanced SIMD or floating-point instruction, and not because of a
     * load/store instruction waiting for data to calculate the address in the
     * AGU. Stall cycles because of a stall in Wr, typically awaiting load data,
     * are excluded.
     */

    PMU_EVENT_KITE_INTERLOCK_OTHER         = 0x103,

    /* Counts every cycle there is an interlock that is because of
     * a load/store instruction waiting for data to calculate the address
     * in the AGU. Stall cycles because of a stall in Wr,
     * typically awaiting load data, are excluded.
     */

    PMU_EVENT_KITE_INTERLOCK_AGU           = 0x104,

    /* Counts every cycle there is an interlock that is because of an
     * Advanced SIMD or floating-point instruction. Stall cycles because of
     * a stall in the Wr stage, typically waiting load data, are excluded.
     */

    PMU_EVENT_KITE_INTERLOCK_FPASIMD       = 0x105,

    /* Counts every cycle there is a stall in the Wr stage
     * because of a load miss from the AXIM.
     */

    PMU_EVENT_KITE_LOAD_STALL_AXI          = 0x106,

    /* Counts every cycle there is a stall in the Wr stage
     * because of a load miss from Flash.
     */

    PMU_EVENT_KITE_LOAD_STALL_FLASH        = 0x107,

    /* Counts every cycle there is a stall in the Wr stage
     * because of a store.
     */

    PMU_EVENT_KITE_WR_STALL_STORE          = 0x108,

    /* Store stalled because the AXIM part of the store buffer was full. */

    PMU_EVENT_KITE_WR_STALL_AXI_STB_FULL   = 0x109,

    /* Store stalled because the TCM part of the store buffer was full. */

    PMU_EVENT_KITE_WR_STALL_TCM_STB_FULL   = 0x10A,

    /* Store stalled because the LLPP part of the store buffer was full. */

    PMU_EVENT_KITE_WR_STALL_LLPP_STB_FULL  = 0x10B,

    /* Barrier stalled because store buffer was busy with another barrier. */

    PMU_EVENT_KITE_BARRIER_STALL_BARRIER   = 0x10C,

    /* Barrier stalled because it was waiting for a write to
     * complete on the AXIM bus.
     */
    PMU_EVENT_KITE_BARRIER_STORE_AXIWRITE  = 0x10D,

    /* L1 instruction cache way tracker hit. */

    PMU_EVENT_KITE_IC_WT_HIT               = 0x200,

    /* L1 data cache way tracker hit. */

    PMU_EVENT_KITE_DC_WT_HIT               = 0x201,

    /* Instruction side micro MPU hit. */

    PMU_EVENT_KITE_I_UMPU_HIT              = 0x202,

    /* Data side micro MPU hit. This can also be counted on
     * a pipeline stall.
     */

    PMU_EVENT_KITE_D_UMPU_HIT              = 0x203,

    /* L1 instruction cache hit. */

    PMU_EVENT_KITE_IC_CACHE_HIT            = 0x204,

    /* L1 instruction cache linefill buffer hit. */

    PMU_EVENT_KITE_IC_LFB_HIT              = 0x205,

    /* L1 instruction cache hit on BIU response. */

    PMU_EVENT_KITE_IC_BIU_HIT              = 0x206,

    /* L1 instruction cache hint request sent. */

    PMU_EVENT_KITE_IC_HINT_REQ             = 0x207

} pmu_event_t;

/* Definition for pmu counter */

typedef enum pmu_counter
{
  PMU_COUNTER0 = 0,
  PMU_COUNTER1 = 1,
  PMU_COUNTER2 = 2,
  PMU_COUNTER3 = 3
} pmu_counter_t;

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/****************************************************************************
 * Name: pmu_enable
 *
 * Description:
 *   Enable performance monitor unit
 *
 ****************************************************************************/

static inline void pmu_enable(void)
{
    cp15_pmu_pmcr((PMCR_P | PMCR_C | PMCR_E));
}

/****************************************************************************
 * Name: pmu_disable
 *
 * Description:
 *   Disable performance monitor unit
 *
 ****************************************************************************/

static inline void pmu_disable(void)
{
    unsigned int pmcr = cp15_pmu_rdpmcr();
    pmcr &= ~(PMCR_P | PMCR_C | PMCR_E);
    cp15_pmu_wrpmcr(pmcr);
}

/****************************************************************************
 * Name: pmu_start_cycle_counter
 *
 * Description:
 *   Start counting the CPU cycles
 *
 ****************************************************************************/

static inline void pmu_start_cycle_counter(bool every64)
{
    unsigned int pmcr = cp15_pmu_rdpmcr();

    if (every64) {
        pmcr |= PMCR_D;
    } else {
        pmcr &= ~PMCR_D;
    }

    cp15_pmu_wrpmcr(pmcr);
    cp15_pmu_wrcesr(PMCESR_CCES);
}

/****************************************************************************
 * Name: pmu_get_cycle_counter
 *
 * Description:
 *   Get current value of cycle counter
 *
 ****************************************************************************/

static inline unsigned int pmu_get_cycle_counter(void)
{
    return cp15_pmu_rdccr();
}

/****************************************************************************
 * Name: pmu_stop_cycle_counter
 *
 * Description:
 *   Stop counting the CPU cycles
 *
 ****************************************************************************/

static inline void pmu_stop_cycle_counter(void)
{
    cp15_pmu_wrcecr(PMCESR_CCES);
}

/****************************************************************************
 * Name: pmu_stop_cycle_counter
 *
 * Description:
 *   Clear the cycle counter to zero
 *
 ****************************************************************************/

static inline void pmu_clear_cycle_counter(void)
{
    CP15_SET(PMCCNTR, 0);
}

/****************************************************************************
 * Name: pmu_start_event_counter
 *
 * Description:
 *   Start to count specific event by specific counter
 *
 ****************************************************************************/

static inline void pmu_start_event_counter(pmu_counter_t counter,
                                           pmu_event_t event)
{
    cp15_pmu_wrecsr(counter);
    cp15_pmu_wretsr(event);
    cp15_pmu_wrcesr(1 << counter);
}

/****************************************************************************
 * Name: pmu_get_event_counter
 *
 * Description:
 *   Get current value of specific event counter
 *
 ****************************************************************************/

static inline unsigned int pmu_get_event_counter(pmu_counter_t counter)
{
    cp15_pmu_wrecsr(counter);
    return cp15_pmu_rdecr();
}

/****************************************************************************
* Name: pmu_stop_event_counter
*
* Description:
*   Stop the specific event counter
*
****************************************************************************/

static inline void pmu_stop_event_counter(pmu_counter_t counter)
{
    cp15_pmu_wrcecr(1 << counter);
}

/****************************************************************************
* Name: pmu_clear_event_counter
*
* Description:
*   Clear the specific event counter
*
****************************************************************************/

static inline void pmu_clear_event_counter(pmu_counter_t counter)
{
    cp15_pmu_wrecsr(counter);
    CP15_SET(PMXEVCNTR, 0);
}

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __CHIPS_E3650_COMMON_ARM_PMU_H */
