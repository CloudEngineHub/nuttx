/****************************************************************************
 * arch/arm/src/armv7-a/svcall.h
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

#ifndef __ARCH_ARM_SRC_ARMV7_A_SVCALL_H
#define __ARCH_ARM_SRC_ARMV7_A_SVCALL_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <syscall.h>

/* SYS call 2:
 *
 * void arm_switchcontext(uint32_t *saveregs, uint32_t *restoreregs);
 */

#define SYS_switch_context        (2)


#ifdef CONFIG_LIB_SYSCALL

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

/* This logic uses one system call for the syscall return.  So a minimum of
 * one syscall values must be reserved.  If CONFIG_BUILD_KERNEL is defined,
 * then four more syscall values must be reserved.
 */

#ifdef CONFIG_BUILD_KERNEL
#  ifndef CONFIG_SYS_RESERVED
#    error "CONFIG_SYS_RESERVED must be defined to have the value 7"
#  elif CONFIG_SYS_RESERVED != 7
#    error "CONFIG_SYS_RESERVED must have the value 6"
#  endif
#else
#  ifndef CONFIG_SYS_RESERVED
#    error "CONFIG_SYS_RESERVED must be defined to have the value 1"
#  elif CONFIG_SYS_RESERVED != 1
#    error "CONFIG_SYS_RESERVED must have the value 1"
#  endif
#endif

/* Cortex-A system calls ****************************************************/

/* SYS call 0:
 *
 * void arm_syscall_return(void);
 */

#define SYS_syscall_return        (0)

#ifndef CONFIG_BUILD_FLAT
#ifdef CONFIG_BUILD_KERNEL
/* SYS call 1:
 *
 * void arm_fullcontextrestore(uint32_t *restoreregs) noreturn_function;
 */

#define SYS_restore_context       (1)

/* SYS call 2:
 *
 * void up_task_start(main_t taskentry, int argc, FAR char *argv[])
 *        noreturn_function;
 */

#define SYS_task_start            (2)

/* SYS call 4:
 *
 * void signal_handler(_sa_sigaction_t sighand,
 *                     int signo, FAR siginfo_t *info,
 *                     FAR void *ucontext);
 */

#define SYS_signal_handler        (4)

/* SYS call 5:
 *
 * void signal_handler_return(void);
 */

#define SYS_signal_handler_return (5)

#endif /* !CONFIG_BUILD_FLAT */

/* SYS call 3:
 *
 * void up_pthread_start(pthread_startroutine_t startup,
 *                       pthread_startroutine_t entrypt, pthread_addr_t arg)
 *        noreturn_function
 */

#define SYS_pthread_start         (3)

/* SYS call 8:
 *
 * void up_pthread_exit(pthread_exitroutine_t exit, FAR void *exit_value)
 */

#define SYS_pthread_exit         (6)

#endif /* CONFIG_BUILD_KERNEL */

/****************************************************************************
 * Inline Functions
 ****************************************************************************/

#endif /* CONFIG_LIB_SYSCALL */
#endif /* __ARCH_ARM_SRC_ARMV7_A_SVCALL_H */
