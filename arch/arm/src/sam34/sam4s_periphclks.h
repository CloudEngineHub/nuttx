/************************************************************************************
 * arch/arm/src/sam34/sam4s_periphclks.h
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
 ************************************************************************************/

#ifndef __ARCH_ARM_SRC_SAM34_SAM4S_PERIPHCLKS_H
#define __ARCH_ARM_SRC_SAM34_SAM4S_PERIPHCLKS_H

/************************************************************************************
 * Included Files
 ************************************************************************************/

#include <nuttx/config.h>
#include <stdint.h>
#include <arch/irq.h>
#include "hardware/sam_pmc.h"

/************************************************************************************
 * Pre-processor Definitions
 ************************************************************************************/
/* Helper macros */

#define sam_enableperiph0(s)       putreg32((1 << (s)), SAM_PMC_PCER0)
#define sam_enableperiph1(s)       putreg32((1 << ((s) - 32)), SAM_PMC_PCER1)
#define sam_disableperiph0(s)      putreg32((1 << (s)), SAM_PMC_PCDR0)
#define sam_disableperiph1(s)      putreg32((1 << ((s) - 32)), SAM_PMC_PCDR1)

#define sam_supc_enableclk()       sam_enableperiph0(SAM_PID_SUPC)
#define sam_rstc_enableclk()       sam_enableperiph0(SAM_PID_RSTC)
#define sam_rtc_enableclk()        sam_enableperiph0(SAM_PID_RTC)
#define sam_rtt_enableclk()        sam_enableperiph0(SAM_PID_RTT)
#define sam_wdt_enableclk()        sam_enableperiph0(SAM_PID_WDT)
#define sam_pmc_enableclk()        sam_enableperiph0(SAM_PID_PMC)
#define sam_eefc0_enableclk()      sam_enableperiph0(SAM_PID_EEFC0)
#define sam_eefc1_enableclk()      sam_enableperiph0(SAM_PID_EEFC1)
#define sam_uart0_enableclk()      sam_enableperiph0(SAM_PID_UART0)
#define sam_uart1_enableclk()      sam_enableperiph0(SAM_PID_UART1)
#define sam_smc_enableclk()        sam_enableperiph0(SAM_PID_SMC)
#define sam_pioa_enableclk()       sam_enableperiph0(SAM_PID_PIOA)
#define sam_piob_enableclk()       sam_enableperiph0(SAM_PID_PIOB)
#define sam_pioc_enableclk()       sam_enableperiph0(SAM_PID_PIOC)
#define sam_usart0_enableclk()     sam_enableperiph0(SAM_PID_USART0)
#define sam_usart1_enableclk()     sam_enableperiph0(SAM_PID_USART1)
#define sam_hsmci_enableclk()      sam_enableperiph0(SAM_PID_HSMCI)
#define sam_twi0_enableclk()       sam_enableperiph0(SAM_PID_TWI0)
#define sam_twi1_enableclk()       sam_enableperiph0(SAM_PID_TWI1)
#define sam_ssc_enableclk()        sam_enableperiph0(SAM_PID_SSC)
#define sam_spi0_enableclk()       sam_enableperiph0(SAM_PID_SPI0)
#define sam_tc0_enableclk()        sam_enableperiph0(SAM_PID_TC0)
#define sam_tc1_enableclk()        sam_enableperiph0(SAM_PID_TC1)
#define sam_tc2_enableclk()        sam_enableperiph0(SAM_PID_TC2)
#define sam_tc3_enableclk()        sam_enableperiph0(SAM_PID_TC3)
#define sam_tc4_enableclk()        sam_enableperiph0(SAM_PID_TC4)
#define sam_tc5_enableclk()        sam_enableperiph0(SAM_PID_TC5)
#define sam_adc12b_enableclk()     sam_enableperiph0(SAM_PID_ADC12B)
#define sam_dacc_enableclk()       sam_enableperiph0(SAM_PID_DACC)
#define sam_pwm_enableclk()        sam_enableperiph0(SAM_PID_PWM)
#define sam_crccu_enableclk()      sam_enableperiph1(SAM_PID_CRCCU)
#define sam_acc_enableclk()        sam_enableperiph1(SAM_PID_ACC)
#define sam_udp_enableclk()        sam_enableperiph1(SAM_PID_UDP)

#define sam_supc_disableclk()      sam_disableperiph0(SAM_PID_SUPC)
#define sam_rstc_disableclk()      sam_disableperiph0(SAM_PID_RSTC)
#define sam_rtc_disableclk()       sam_disableperiph0(SAM_PID_RTC)
#define sam_rtt_disableclk()       sam_disableperiph0(SAM_PID_RTT)
#define sam_wdt_disableclk()       sam_disableperiph0(SAM_PID_WDT)
#define sam_pmc_disableclk()       sam_disableperiph0(SAM_PID_PMC)
#define sam_eefc0_disableclk()     sam_disableperiph0(SAM_PID_EEFC0)
#define sam_eefc1_disableclk()     sam_disableperiph0(SAM_PID_EEFC1)
#define sam_uart0_disableclk()     sam_disableperiph0(SAM_PID_UART0)
#define sam_uart1_disableclk()     sam_disableperiph0(SAM_PID_UART1)
#define sam_smc_disableclk()       sam_disableperiph0(SAM_PID_SMC)
#define sam_pioa_disableclk()      sam_disableperiph0(SAM_PID_PIOA)
#define sam_piob_disableclk()      sam_disableperiph0(SAM_PID_PIOB)
#define sam_pioc_disableclk()      sam_disableperiph0(SAM_PID_PIOC)
#define sam_usart0_disableclk()    sam_disableperiph0(SAM_PID_USART0)
#define sam_usart1_disableclk()    sam_disableperiph0(SAM_PID_USART1)
#define sam_hsmci_disableclk()     sam_disableperiph0(SAM_PID_HSMCI)
#define sam_twi0_disableclk()      sam_disableperiph0(SAM_PID_TWI0)
#define sam_twi1_disableclk()      sam_disableperiph0(SAM_PID_TWI1)
#define sam_spi0_disableclk()      sam_disableperiph0(SAM_PID_SPI0)
#define sam_ssc_disableclk()       sam_disableperiph0(SAM_PID_SSC)
#define sam_tc0_disableclk()       sam_disableperiph0(SAM_PID_TC0)
#define sam_tc1_disableclk()       sam_disableperiph0(SAM_PID_TC1)
#define sam_tc2_disableclk()       sam_disableperiph0(SAM_PID_TC2)
#define sam_tc3_disableclk()       sam_disableperiph0(SAM_PID_TC3)
#define sam_tc4_disableclk()       sam_disableperiph0(SAM_PID_TC4)
#define sam_tc5_disableclk()       sam_disableperiph0(SAM_PID_TC5)
#define sam_adc12b_disableclk()    sam_disableperiph0(SAM_PID_ADC)
#define sam_dacc_disableclk()      sam_disableperiph0(SAM_PID_DACC)
#define sam_pwm_disableclk()       sam_disableperiph0(SAM_PID_PWM)
#define sam_crccu_disableclk()     sam_disableperiph1(SAM_PID_CRCCU)
#define sam_acc_disableclk()       sam_disableperiph1(SAM_PID_ACC)
#define sam_udp_disableclk()       sam_disableperiph1(SAM_PID_UDP)

/************************************************************************************
 * Public Types
 ************************************************************************************/

/************************************************************************************
 * Inline Functions
 ************************************************************************************/

#ifndef __ASSEMBLY__

/************************************************************************************
 * Public Data
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
#define EXTERN extern "C"
extern "C"
{
#else
#define EXTERN extern
#endif

/************************************************************************************
 * Public Function Prototypes
 ************************************************************************************/

#undef EXTERN
#if defined(__cplusplus)
}
#endif

#endif /* __ASSEMBLY__ */
#endif /* __ARCH_ARM_SRC_SAM34_SAM4S_PERIPHCLKS_H */
