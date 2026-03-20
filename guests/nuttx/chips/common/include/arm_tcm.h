/****************************************************************************
 * chips/common/include/arm_tcm.h
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

#ifndef __CHIPS_E3650_TCM_COMMON_TCM_H
#define __CHIPS_E3650_TCM_COMMON_TCM_H

/* IMP_ATCMREGIONR/IMP_BTCMREGIONR/IMP_CTCMREGIONR registers in the
 * Cortex-R52 TRM.
 */

#define TCM_BASEADDR_MASK   (0xFFFFE000U) /* Bits [31:13] */
#define TCM_WAITSTATES      (0x1 << 8)
#define TCM_ENABLEEL2       (0x1 << 1)
#define TCM_ENABLEEL10      (0x1 << 0)

/* TCM size IDs */

#define TCM_SIZE_NO_PRESENT    (0)
#define TCM_SIZE_8KB           (0b00100)
#define TCM_SIZE_16KB          (0b00101)
#define TCM_SIZE_32KB          (0b00110)
#define TCM_SIZE_64KB          (0b00111)
#define TCM_SIZE_128KB         (0b01000)
#define TCM_SIZE_256KB         (0b01001)
#define TCM_SIZE_512KB         (0b01010)
#define TCM_SIZE_1024KB        (0b01011)

/* Convert a TCM size ID to bytes. */

#define TCM_SIZE_NUM(size_id)  ((1 << (size_id - 1)) << 10)

/* Initialize and optionally populate TCM regions. */

void arm_tcm_init(void);
void arm_tcm_load(void);

#endif /* __CHIPS_E3650_TCM_COMMON_TCM_H */
