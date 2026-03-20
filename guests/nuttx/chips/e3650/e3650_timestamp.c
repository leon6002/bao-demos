/****************************************************************************
 * chips/e3650/e3650_timestamp.c
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

#include <stdbool.h>
#include <stdint.h>

#include <nuttx/clock.h>

int up_timer_value(clock_t *ticks);

/****************************************************************************
 * Name: up_udelay
 *
 * Description:
 *   Provide a simple busy-wait delay using the platform timer value.
 *
 ****************************************************************************/

void up_udelay(uint32_t us)
{
  clock_t start;
  clock_t end;

  if (us == 0)
    {
      return;
    }

  up_timer_value(&start);
  end = start + ((clock_t)us * CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC / 1000000);

  do
    {
      up_timer_value(&start);
    }
  while (start < end);
}
