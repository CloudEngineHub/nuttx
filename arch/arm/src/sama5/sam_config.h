/****************************************************************************
 * arch/arm/src/sama5/sam_config.h
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

#ifndef __ARCH_ARM_SRC_SAMA5_SAM_CONFIG_H
#define __ARCH_ARM_SRC_SAMA5_SAM_CONFIG_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration **********************************************************/

/* If the USART is not being used as a UART, then it really isn't enabled
 * for our purposes.
 */

#ifndef CONFIG_USART0_SERIALDRIVER
#  undef CONFIG_SAMA5_USART0
#  undef CONFIG_SAMA5_FLEXCOM0_USART
#  undef CONFIG_USART0_SERIAL_CONSOLE
#endif
#ifndef CONFIG_USART1_SERIALDRIVER
#  undef CONFIG_SAMA5_USART1
#  undef CONFIG_SAMA5_FLEXCOM1_USART
#  undef CONFIG_USART1_SERIAL_CONSOLE
#endif
#ifndef CONFIG_USART2_SERIALDRIVER
#  undef CONFIG_SAMA5_USART2
#  undef CONFIG_SAMA5_FLEXCOM2_USART
#  undef CONFIG_USART2_SERIAL_CONSOLE
#endif
#ifndef CONFIG_USART3_SERIALDRIVER
#  undef CONFIG_SAMA5_USART3
#  undef CONFIG_SAMA5_FLEXCOM3_USART
#  undef CONFIG_USART3_SERIAL_CONSOLE
#endif
#ifndef CONFIG_USART4_SERIALDRIVER
#  undef CONFIG_SAMA5_USART4
#  undef CONFIG_SAMA5_FLEXCOM4_USART
#  undef CONFIG_USART4_SERIAL_CONSOLE
#endif

/* Is there a USART/USART enabled? */

#if defined(CONFIG_SAMA5_UART0) || defined(CONFIG_SAMA5_UART1) || \
    defined(CONFIG_SAMA5_UART2) || defined(CONFIG_SAMA5_UART3) || \
    defined(CONFIG_SAMA5_UART4)
#  define SAMA5_HAVE_UART
#endif

#if defined(CONFIG_SAMA5_USART0) || defined(CONFIG_SAMA5_USART1) || \
    defined(CONFIG_SAMA5_USART2) || defined(CONFIG_SAMA5_USART3) || \
    defined(CONFIG_SAMA5_USART4)
#  define SAMA5_HAVE_USART
#endif

/* Same is true for Flexcom USARTs */

#ifndef CONFIG_SAMA5_FLEXCOM
#  undef CONFIG_SAMA5_FLEXCOM_USART
#endif

#ifndef CONFIG_SAMA5_FLEXCOM_USART
#  undef CONFIG_SAMA5_FLEXCOM0_USART
#  undef CONFIG_SAMA5_FLEXCOM1_USART
#  undef CONFIG_SAMA5_FLEXCOM2_USART
#  undef CONFIG_SAMA5_FLEXCOM3_USART
#  undef CONFIG_SAMA5_FLEXCOM4_USART
#endif

#if defined(CONFIG_SAMA5_FLEXCOM0_USART) || defined(CONFIG_SAMA5_FLEXCOM1_USART) || \
    defined(CONFIG_SAMA5_FLEXCOM2_USART) || defined(CONFIG_SAMA5_FLEXCOM3_USART) || \
    defined(CONFIG_SAMA5_FLEXCOM4_USART)
#  define SAMA5_HAVE_FLEXCOM_USART
#endif

#if defined(SAMA5_HAVE_FLEXCOM_USART) && defined(SAMA5_HAVE_USART)
#  error "Cannot have both USART and Flexcom USART"
#endif

#undef SUPPRESS_CONSOLE_CONFIG
#ifdef CONFIG_SUPPRESS_UART_CONFIG
#  define SUPPRESS_CONSOLE_CONFIG 1
#endif

/* Is there a serial console?  It could be on UART0-4 or USART0-3 */

#if defined(CONFIG_SAMA5_DBGU_CONSOLE) && defined(CONFIG_SAMA5_DBGU)
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  define SAMA5_HAVE_DBGU_CONSOLE 1
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_UART0_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_UART0)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  define SAMA5_HAVE_UART_CONSOLE 1
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_UART1_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_UART1)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  define SAMA5_HAVE_UART_CONSOLE 1
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_UART2_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_UART2)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  define SAMA5_HAVE_UART_CONSOLE 1
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_UART3_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_UART3)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  define SAMA5_HAVE_UART_CONSOLE 1
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_UART4_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_UART4)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  define SAMA5_HAVE_UART_CONSOLE 1
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_USART0_SERIAL_CONSOLE) && defined(CONFIG_USART0_SERIALDRIVER)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  define SAMA5_HAVE_USART_CONSOLE 1
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_USART1_SERIAL_CONSOLE) && defined(CONFIG_USART1_SERIALDRIVER)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  define SAMA5_HAVE_USART_CONSOLE 1
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_USART2_SERIAL_CONSOLE) && defined(CONFIG_USART2_SERIALDRIVER)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  define SAMA5_HAVE_USART_CONSOLE 1
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_USART3_SERIAL_CONSOLE) && defined(CONFIG_USART3_SERIALDRIVER)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  define SAMA5_HAVE_USART_CONSOLE 1
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_USART4_SERIAL_CONSOLE) && defined(CONFIG_USART4_SERIALDRIVER)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  define SAMA5_HAVE_USART_CONSOLE 1
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#elif defined(CONFIG_USART0_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_FLEXCOM0_USART)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  define SAMA5_HAVE_FLEXCOM_CONSOLE 1
#elif defined(CONFIG_USART1_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_FLEXCOM1_USART)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  define SAMA5_HAVE_FLEXCOM_CONSOLE 1
#elif defined(CONFIG_USART2_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_FLEXCOM2_USART)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  define SAMA5_HAVE_FLEXCOM_CONSOLE 1
#elif defined(CONFIG_USART3_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_FLEXCOM3_USART)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  define SAMA5_HAVE_FLEXCOM_CONSOLE 1
#elif defined(CONFIG_USART4_SERIAL_CONSOLE) && defined(CONFIG_SAMA5_FLEXCOM4_USART)
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  define SAMA5_HAVE_FLEXCOM_CONSOLE 1
#else
#  warning "No valid CONFIG_UARTn/USARTn_SERIAL_CONSOLE Setting"
#  undef  CONFIG_SAMA5_DBGU_CONSOLE
#  undef  CONFIG_UART0_SERIAL_CONSOLE
#  undef  CONFIG_UART1_SERIAL_CONSOLE
#  undef  CONFIG_UART2_SERIAL_CONSOLE
#  undef  CONFIG_UART3_SERIAL_CONSOLE
#  undef  CONFIG_UART4_SERIAL_CONSOLE
#  undef  CONFIG_USART0_SERIAL_CONSOLE
#  undef  CONFIG_USART1_SERIAL_CONSOLE
#  undef  CONFIG_USART2_SERIAL_CONSOLE
#  undef  CONFIG_USART3_SERIAL_CONSOLE
#  undef  CONFIG_USART4_SERIAL_CONSOLE
#  undef  SAMA5_HAVE_DBGU_CONSOLE
#  undef  SAMA5_HAVE_UART_CONSOLE
#  undef  SAMA5_HAVE_USART_CONSOLE
#  undef  SAMA5_HAVE_FLEXCOM_CONSOLE
#endif

#endif /* __ARCH_ARM_SRC_SAMA5_SAM_CONFIG_H */
