/****************************************************************************
 * vendor/semidrive/chips/e3650/include/chip.h
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

#ifndef __CHIPS_E3650_INCLUDE_CHIP_H
#define __CHIPS_E3650_INCLUDE_CHIP_H

#include <nuttx/config.h>
#include "arm_tcm.h"

/* Number of bytes in x kibibytes/mebibytes/gibibytes */

#define KB(x)           ((x) << 10)
#define MB(x)           (KB(x) << 10)
#define GB(x)           (MB(UINT64_C(x)) << 10)

#if defined(CONFIG_ARCH_CHIP_E3650)

#define CONFIG_ATCM_SIZE        TCM_SIZE_32KB
#define CONFIG_BTCM_SIZE        TCM_SIZE_32KB
#define CONFIG_CTCM_SIZE        TCM_SIZE_64KB

#define CONFIG_CPU0_ATCM_START_ADDR  (0x11000000UL)
#define CONFIG_CPU0_BTCM_START_ADDR  (0x11100000UL)
#define CONFIG_CPU0_CTCM_START_ADDR  (0x11200000UL)

#define CONFIG_CPU1_ATCM_START_ADDR  (0x11400000UL)
#define CONFIG_CPU1_BTCM_START_ADDR  (0x11500000UL)
#define CONFIG_CPU1_CTCM_START_ADDR  (0x11600000UL)

#define CONFIG_CPU2_ATCM_START_ADDR  (0x11800000UL)
#define CONFIG_CPU2_BTCM_START_ADDR  (0x11900000UL)
#define CONFIG_CPU2_CTCM_START_ADDR  (0x11A00000UL)

#define CONFIG_CPU3_ATCM_START_ADDR  (0x11C00000UL)
#define CONFIG_CPU3_BTCM_START_ADDR  (0x11D00000UL)
#define CONFIG_CPU3_CTCM_START_ADDR  (0x11E00000UL)


#define CONFIG_GICD_BASE         CONFIG_ARCH_CHIP_E3650_GICD_BASE
#define CONFIG_GICR_BASE         CONFIG_ARCH_CHIP_E3650_GICR_BASE
#define CONFIG_GICR_OFFSET       0x20000

#define MPID_TO_CLUSTER_ID(mpid)  ((mpid) & ~0xff)

#endif /* CONFIG_ARCH_CHIP_E3650 */

#endif /* __CHIPS_E3650_INCLUDE_CHIP_H */
