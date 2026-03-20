/****************************************************************************
 * semidrive/chips/e3650/e3650_allocateheap.c
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
#include <sys/types.h>
#include <debug.h>
#include <nuttx/arch.h>
#include <nuttx/sched.h>
#include <nuttx/board.h>

extern uint8_t _core0_heap_start[];
extern uint8_t _core0_heap_end[];
extern uint8_t _core1_heap_start[];
extern uint8_t _core1_heap_end[];
extern uint8_t _core2_heap_start[];
extern uint8_t _core2_heap_end[];
extern uint8_t _core3_heap_start[];
extern uint8_t _core3_heap_end[];

/****************************************************************************
 * Name: up_allocate_heap
 *
 * Description:
 *   This function will be called to dynamically set aside the heap region.
 *
 *   For the kernel build (CONFIG_BUILD_KERNEL=y) with both kernel- and
 *   user-space heaps (CONFIG_MM_KERNEL_HEAP=y), this function provides the
 *   size of the unprotected, user-space heap.
 *
 *   If a protected kernel-space heap is provided, the kernel heap must be
 *   allocated (and protected) by an analogous up_allocate_kheap().
 *
 ****************************************************************************/


void up_allocate_heap(void **heap_start, size_t *heap_size)
{
  int cpu = up_cpu_index();

  switch (cpu)
  {
    case 0:
      *heap_start = (void *)_core0_heap_start;
      *heap_size = (size_t)_core0_heap_end - (size_t)_core0_heap_start;
      break;

    case 1:
      *heap_start = (void *)_core1_heap_start;
      *heap_size = (size_t)_core1_heap_end - (size_t)_core1_heap_start;
      break;

    case 2:
      *heap_start = (void *)_core2_heap_start;
      *heap_size = (size_t)_core2_heap_end - (size_t)_core2_heap_start;
      break;

    case 3:
      *heap_start = (void *)_core3_heap_start;
      *heap_size = (size_t)_core3_heap_end - (size_t)_core3_heap_start;
      break;

    default:
        break;
  }
}
