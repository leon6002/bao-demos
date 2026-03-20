/****************************************************************************
 * semidrive/chips/e3650/include/irq.h
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

/* This file should never be included directly but, rather,
 * only indirectly through nuttx/irq.h
 */

#ifndef __CHIPS_E3650_INCLUDE_IRQ_H
#define __CHIPS_E3650_INCLUDE_IRQ_H

#include <nuttx/config.h>
#include <arch/armv8-r/irq.h>

#define IDLE_STACK_BASE _core0_idle_stack_start
#define NR_IRQS 434U

#ifndef __ASSEMBLY__
void up_init_irq(int irq, int irq_prio);
bool up_irq_is_enabled(int irq);
void up_clear_irq(int irq);
uint32_t up_timer_freq(void);
int up_timer_value(clock_t *ticks);
uint32_t up_timer_gettickfreq(void);
#endif /* __ASSEMBLY__ */

#endif /* __CHIPS_E3650_INCLUDE_IRQ_H */
