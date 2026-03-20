/* Copyright (c) 2025 Beijing Semidrive Technology Corporation
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef REGS_BASE_E3650_H
#define REGS_BASE_E3650_H

/*------------------------------------------------------
 * ADC & DAC
 *------------------------------------------------------*/

/* Analog Digital Converter 1 */
#define APB_ADC1_BASE (0xF8490000UL)

/* Analog Digital Converter 2 */
#define APB_ADC2_BASE (0xF84A0000UL)

/* Analog Digital Converter 3 */
#define APB_ADC3_BASE (0xF84B0000UL)

/* Analog Digital Converter 4 */
#define APB_ADC4_BASE (0xF8110000UL)

/* Analog Digital Converter 5 */
#define APB_ADC5_BASE (0xF8120000UL)

/* Analog Digital Converter 6 */
#define APB_ADC6_BASE (0xF8130000UL)

/* Analog Digital Converter 7 */
#define APB_ADC7_BASE (0xF0490000UL)

/* Analog Control */
#define APB_ANALOG_CTRL_BASE (0xF8450000UL)


/*------------------------------------------------------
 * Peripherals
 *------------------------------------------------------*/

/* Asychronous Wakeup Interrupt Controller (AWIC) */
#define APB_AWIC_BASE (0xF0090000UL)

/* CAN with Flexible Data rate (CANFD) 1 */
#define APB_CANFD1_BASE (0xF0580000UL)

/* CAN with Flexible Data rate (CANFD) 2 */
#define APB_CANFD2_BASE (0xF0590000UL)

/* CAN with Flexible Data rate (CANFD) 3 */
#define APB_CANFD3_BASE (0xF8500000UL)

/* CAN with Flexible Data rate (CANFD) 4 */
#define APB_CANFD4_BASE (0xF8230000UL)

/* CAN with Flexible Data rate (CANFD) 5 */
#define APB_CANFD5_BASE (0xF8510000UL)

/* CAN with Flexible Data rate (CANFD) 6 */
#define APB_CANFD6_BASE (0xF8240000UL)

/* CAN with Flexible Data rate (CANFD) 7 */
#define APB_CANFD7_BASE (0xF8520000UL)

/* CAN with Flexible Data rate (CANFD) 8 */
#define APB_CANFD8_BASE (0xF8250000UL)

/* CAN with Flexible Data rate (CANFD) 9 */
#define APB_CANFD9_BASE (0xF8530000UL)

/* CAN with Flexible Data rate (CANFD) 10 */
#define APB_CANFD10_BASE (0xF8260000UL)

/* CAN with Flexible Data rate (CANFD) 11 */
#define APB_CANFD11_BASE (0xF8540000UL)

/* CAN with Flexible Data rate (CANFD) 12 */
#define APB_CANFD12_BASE (0xF8270000UL)

/* CAN with Flexible Data rate (CANFD) 13 */
#define APB_CANFD13_BASE (0xF8550000UL)

/* CAN with Flexible Data rate (CANFD) 14 */
#define APB_CANFD14_BASE (0xF8280000UL)

/* CAN with Flexible Data rate (CANFD) 15 */
#define APB_CANFD15_BASE (0xF8560000UL)

/* CAN with Flexible Data rate (CANFD) 16 */
#define APB_CANFD16_BASE (0xF8290000UL)

/* Ethernet (ENET) 1 */
#define APB_ETNERNET1_BASE (0xF90C0000UL)

/* Ethernet (ENET) 2 */
#define APB_ETNERNET2_BASE (0xF90D0000UL)

/* LP Domain General Porpose Intput Output (GPIO) */
#define APB_GPIO_LP_BASE (0xF04B0000UL)

/* SF Domain General Porpose Intput Output (GPIO) 1 */
#define APB_GPIO_SAFETY1_BASE (0xF81E0000UL)

/* SF Domain General Porpose Intput Output (GPIO) 2 */
#define APB_GPIO_SAFETY2_BASE (0xF81F0000UL)

/* Inter-Integrated Circuit (I2C) 1 */
#define APB_I2C1_BASE (0xF04C0000UL)

/* Inter-Integrated Circuit (I2C) 2 */
#define APB_I2C2_BASE (0xF8860000UL)

/* Inter-Integrated Circuit (I2C) 3 */
#define APB_I2C3_BASE (0xF8C50000UL)

/* Inter-Integrated Circuit (I2C) 4 */
#define APB_I2C4_BASE (0xF8C60000UL)

/* Single-Edge Nibble Transmission (SENT) */
#define APB_SENT_BASE (0xF8810000UL)

/* Serial Peripheral Interface (SPI) 1 */
#define APB_SPI1_BASE (0xF0500000UL)

/* Serial Peripheral Interface (SPI) 2 */
#define APB_SPI2_BASE (0xF0510000UL)

/* Serial Peripheral Interface (SPI) 3 */
#define APB_SPI3_BASE (0xF8C70000UL)

/* Serial Peripheral Interface (SPI) 4 */
#define APB_SPI4_BASE (0xF8880000UL)

/* Serial Peripheral Interface (SPI) 5 */
#define APB_SPI5_BASE (0xF8C80000UL)

/* Serial Peripheral Interface (SPI) 6 */
#define APB_SPI6_BASE (0xF8890000UL)

/* Serial Peripheral Interface (SPI) 7 */
#define APB_SPI7_BASE (0xF8C90000UL)

/* Serial Peripheral Interface (SPI) 8 */
#define APB_SPI8_BASE (0xF88A0000UL)

/* Serial Peripheral Interface (SPI) 9 */
#define APB_SPI9_BASE (0xF8CA0000UL)

/* Serial Peripheral Interface (SPI) 10 */
#define APB_SPI10_BASE (0xF88B0000UL)

/* Serial Peripheral Interface (SPI) 11 */
#define APB_SPI11_BASE (0xF8CB0000UL)

/* Serial Peripheral Interface (SPI) 12 */
#define APB_SPI12_BASE (0xF88C0000UL)

/* Serial Peripheral Interface (SPI) 13 */
#define APB_SPI13_BASE (0xF8CC0000UL)

/* Serial Peripheral Interface (SPI) 14 */
#define APB_SPI14_BASE (0xF88D0000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 1 */
#define APB_UART1_BASE (0xF0540000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 2 */
#define APB_UART2_BASE (0xF0550000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 3 */
#define APB_UART3_BASE (0xF8D00000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 4 */
#define APB_UART4_BASE (0xF8900000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 5 */
#define APB_UART5_BASE (0xF8D10000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 6 */
#define APB_UART6_BASE (0xF8910000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 7 */
#define APB_UART7_BASE (0xF8D20000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 8 */
#define APB_UART8_BASE (0xF8920000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 9 */
#define APB_UART9_BASE (0xF8D30000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 10 */
#define APB_UART10_BASE (0xF8930000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 11 */
#define APB_UART11_BASE (0xF8D40000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 12 */
#define APB_UART12_BASE (0xF8940000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 13 */
#define APB_UART13_BASE (0xF8D50000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 14 */
#define APB_UART14_BASE (0xF8950000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 15 */
#define APB_UART15_BASE (0xF8D60000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 16 */
#define APB_UART16_BASE (0xF8960000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 17 */
#define APB_UART17_BASE (0xF8D70000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 18 */
#define APB_UART18_BASE (0xF8970000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 19 */
#define APB_UART19_BASE (0xF8D80000UL)

/* Universal Asynchronous Receiver/Transmitter (UART) 20 */
#define APB_UART20_BASE (0xF8980000UL)

/*------------------------------------------------------
 * Bus Inter-Connect
 *------------------------------------------------------*/

/* Configuration Register for AXI Cross-Bar LP */
#define APB_AXB_LP_BASE (0xF07F0000UL)

/* Configuration Register for AXI Cross-Bar Cortex-R52 A */
#define APB_AXB_R52A_REG_BASE (0xF87C0000UL)

/* Configuration Register for AXI Cross-Bar Cortex-R52 B */
#define APB_AXB_R52B_REG_BASE (0xF87B0000UL)

/* Configuration Register for AXI Cross-Bar SE */
#define APB_GPV_AE_BASE (0xF20F0000UL)

/* Configuration Register for Network on Chip (NOC) AP Fabric */
#define APB_GPV_AP_BASE (0xF90F0000UL)

/* Configuration Register for APB Network on Chip (NOC) LP Fabric */
#define APB_GPV_LP_BASE (0xF0560000UL)

/* Configuration Register for Cross-Bar SF Fabric */
#define APB_GPV_MX_BASE (0xF8010000UL)

/* Configuration Register for Network on Chip (NOC) SF Fabric */
#define APB_GPV_SAFETY_BASE (0xF90E0000UL)

/* Configuration Register for Cross-Bar SE Fabric */
#define APB_GPV_XE_BASE (0xF20E0000UL)

/* Configuration Register for Cross-Bar LP Fabric */
#define APB_GPV_XL_BASE (0xF07E0000UL)


/*------------------------------------------------------
 * Timers
 *------------------------------------------------------*/

/* Basic Timer ModULe (BTM) 1 */
#define APB_BTM1_BASE (0xF04E0000UL)

/* Basic Timer ModULe (BTM) 2 */
#define APB_BTM2_BASE (0xF04F0000UL)

/* Basic Timer ModULe (BTM) 3 */
#define APB_BTM3_BASE (0xF2020000UL)

/* Basic Timer ModULe (BTM) 4 */
#define APB_BTM4_BASE (0xF8190000UL)

/* Basic Timer ModULe (BTM) 5 */
#define APB_BTM5_BASE (0xF8600000UL)

/* Basic Timer ModULe (BTM) 6 */
#define APB_BTM6_BASE (0xF81A0000UL)

/* Basic Timer ModULe (BTM) 7 */
#define APB_BTM7_BASE (0xF8610000UL)

/* Basic Timer ModULe (BTM) 8 */
#define APB_BTM8_BASE (0xF81B0000UL)

/* Basic Timer ModULe (BTM) 9 */
#define APB_BTM9_BASE (0xF8620000UL)

/* Basic Timer ModULe (BTM) 10 */
#define APB_BTM10_BASE (0xF81C0000UL)

/* Basic Timer ModULe (BTM) 11 */
#define APB_BTM11_BASE (0xF8630000UL)

/* Basic Timer ModULe (BTM) 12 */
#define APB_BTM12_BASE (0xF81D0000UL)

/* Energy PULse-Width ModULator 1 */
#define APB_EPWM1_BASE (0xF87D0000UL)

/* Energy PULse-Width ModULator 2 */
#define APB_EPWM2_BASE (0xF80D0000UL)

/* Energy PULse-Width ModULator 3 */
#define APB_EPWM3_BASE (0xF87E0000UL)

/* Energy PULse-Width ModULator 4 */
#define APB_EPWM4_BASE (0xF80E0000UL)

/* Energy Timer 1 */
#define APB_ETMR1_BASE (0xF8580000UL)

/* Energy Timer 2 */
#define APB_ETMR2_BASE (0xF8140000UL)

/* Energy Timer 3 */
#define APB_ETMR3_BASE (0xF8590000UL)

/* Energy Timer 4 */
#define APB_ETMR4_BASE (0xF8150000UL)

/* Real Time Clock 1 */
#define APB_RTC1_BASE (0xF0010000UL)

/* Real Time Clock 2 */
#define APB_RTC2_BASE (0xF0020000UL)

/* System Counter Read-Write Base */
#define APB_SYS_CNT_BASE (0xF8C20000UL)

/* System Counter Read-Only Base */
#define APB_SYS_CNT_READ_BASE (0xF8C30000UL)

/* Watch Dog(WDT) 1 */
#define APB_WDT1_BASE (0xF05F0000UL)

/* Watch Dog(WDT) 2 */
#define APB_WDT2_BASE (0xF2030000UL)

/* Watch Dog(WDT) 3 */
#define APB_WDT3_BASE (0xF84D0000UL)

/* Watch Dog(WDT) 4 */
#define APB_WDT4_BASE (0xF84E0000UL)

/* Watch Dog(WDT) 5 */
#define APB_WDT5_BASE (0xF84F0000UL)

/* Watch Dog(WDT) 6 */
#define APB_WDT6_BASE (0xF83C0000UL)

/* Watch Dog(WDT) 8 */
#define APB_WDT8_BASE (0xF83D0000UL)

/* Watch Dog(WDT) 9 */
#define APB_WDT9_BASE (0xF00B0000UL)

/* Cross Trigger 1 */
#define APB_XTRG1_BASE (0xF8170000UL)

/* Cross Trigger 2 */
#define APB_XTRG2_BASE (0xF8180000UL)


/*------------------------------------------------------
 * Clock & Reset
 *------------------------------------------------------*/

/* LP Domain Clock Generator (CKGEN) */
#define APB_CKGEN_LP_BASE (0xF0440000UL)

/* SF Domain Clock Generator (CKGEN) */
#define APB_CKGEN_SAFETY_BASE (0xF8060000UL)

/* 24MHZ generation block with failsafe function(FS24M) */
#define APB_FS_24M_BASE (0xF0410000UL)

/* 32KHZ generation block with failsafe function (FS32K) */
#define APB_FS_32K_BASE (0xF0030000UL)

/* Phase Locked Loop (PLL) 1 */
#define APB_PLL1_BASE (0xF80A0000UL)

/* Phase Locked Loop (PLL) 2 */
#define APB_PLL2_BASE (0xF80B0000UL)

/* Phase Locked Loop (PLL) 3 */
#define APB_PLL3_BASE (0xF80C0000UL)

/* LP Domain Reset Generator (RSTGEN) */
#define APB_RSTGEN_LP_BASE (0xF0430000UL)

/* SF Domain Reset Generator (RSTGEN) */
#define APB_RSTGEN_SAFETY_BASE (0xF8050000UL)


/*------------------------------------------------------
 * cram
 *------------------------------------------------------*/

/* Corherent RAM 1 Controller */
#define APB_CRAM1_BASE (0xF8410000UL)

/* Corherent RAM 2 Controller */
#define APB_CRAM2_BASE (0xF8420000UL)

/* Corherent RAM 3 Controller */
#define APB_CRAM3_BASE (0xF8430000UL)

/* Corherent RAM 4 Controller */
#define APB_CRAM4_BASE (0xF8440000UL)


/*------------------------------------------------------
 * Debug
 *------------------------------------------------------*/

/* CoreSight DAP1 */
#define APB_CSSYS_DAP1_BASE (0xF0600000UL)

/* CoreSight DAP2 */
#define APB_CSSYS_DAP2_BASE (0xF0610000UL)

/* CoreSight DAP3 */
#define APB_CSSYS_DAP3_BASE (0xF0620000UL)

/* CoreSight DAP4 */
#define APB_CSSYS_DAP4_BASE (0xF0630000UL)

/* CoreSight LP1 */
#define APB_CSSYS_LP1_BASE (0xF0680000UL)

/* CoreSight LP2 */
#define APB_CSSYS_LP2_BASE (0xF0690000UL)

/* CoreSight LP3 */
#define APB_CSSYS_LP3_BASE (0xF06A0000UL)

/* CoreSight LP4 */
#define APB_CSSYS_LP4_BASE (0xF06B0000UL)

/* CoreSight R52P1 */
#define APB_CSSYS_R52P1_BASE (0xF06C0000UL)

/* CoreSight R52P2 */
#define APB_CSSYS_R52P2_BASE (0xF06D0000UL)

/* CoreSight R52P3 */
#define APB_CSSYS_R52P3_BASE (0xF06E0000UL)

/* CoreSight R52P4 */
#define APB_CSSYS_R52P4_BASE (0xF06F0000UL)

/* CoreSight SE1 */
#define APB_CSSYS_SE1_BASE (0xF0640000UL)

/* CoreSight SE2 */
#define APB_CSSYS_SE2_BASE (0xF0650000UL)

/* CoreSight SE3 */
#define APB_CSSYS_SE3_BASE (0xF0660000UL)

/* CoreSight SE4 */
#define APB_CSSYS_SE4_BASE (0xF0670000UL)


/*------------------------------------------------------
 * Power Management
 *------------------------------------------------------*/

/* Digital controller of bULk mode DC-DC converter(DCDC) */
#define APB_DCDC_BASE (0xF8200000UL)

/* Linear Mode RegULator Controller(LDO) for LP */
#define APB_LDO_LP_BASE (0xF0460000UL)

/* Linear Mode RegULator Controller(LDO) for Ultra LowPower (ULP) */
#define APB_LDO_ULP_BASE (0xF0050000UL)

/* Power Management Unit */
#define APB_PMU_CORE_BASE (0xF0060000UL)

/* Temperature Sensor for SF Domain */
#define APB_PT_SNS_SF_BASE (0xF8C40000UL)

/* System Work Mode Controller (SMC) */
#define APB_SMC_BASE (0xF0450000UL)

/* Voltage Detector for LP Domain */
#define APB_VD_LP_BASE (0xF0780000UL)

/* Voltage Detector for SF Domain */
#define APB_VD_SF_BASE (0xF8830000UL)


/*------------------------------------------------------
 * Co-Processor
 *------------------------------------------------------*/

/* SF Domain Direct Memory Access (DMA) 1 A */
#define APB_DMA_SF1A_BASE (0xF8680000UL)

/* SF Domain Direct Memory Access (DMA) 1 B */
#define APB_DMA_SF1B_BASE (0xF82A0000UL)

/* SF Domain Direct Memory Access (DMA) 2 A */
#define APB_DMA_SF2A_BASE (0xF8330000UL)

/* SF Domain Direct Memory Access (DMA) 2 B */
#define APB_DMA_SF2B_BASE (0xF8710000UL)

/* Data Package Engine (DPE) */
#define APB_DPE_BASE (0xF8020000UL)

/* Wakeup Event Sampler (WES) */
#define APB_WES_BASE (0xF07B0000UL)


/*------------------------------------------------------
 * Security
 *------------------------------------------------------*/

/* MRAM KEY */
#define APB_MRAM_KEY_BASE (0xF21F0000UL)

/* SEIP Kbuf */
#define APB_KBUF_BASE (0xF21DE000UL)

/* SEIP APBSYSTEMREG */
#define APB_APBSYSTEMREG_BASE (0xF21DD800UL)

/* SEIP AHB System Reg */
#define APB_AHBSYSTEMREG_BASE (0xF21D0000UL)

/* SEIP HFE */
#define APB_SEIP_HFE_BASE (0xF21CC000UL)

/* SEIP HKE */
#define APB_SEIP_SKE_BASE (0xF21C8000UL)

/* SEIP TRNG */
#define APB_SEIP_TRNG_BASE (0xF21C4000UL)

/* SEIP PKE */
#define APB_SEIP_PKE_BASE (0xF21C0000UL)

/* E-Fuse Controller */
#define APB_EFUSEC_BASE (0xF0420000UL)

/* Secure Storage */
#define APB_SEC_STORAGE_BASE (0xF00A0000UL)

/* Secure Element Intellectual Property */
#define APB_SEIP_BASE (0xF2010000UL)


/*------------------------------------------------------
 * FuSa
 *------------------------------------------------------*/

/* Error Injection Controller for Boot Domain */
#define APB_EIC_BOOT_BASE (0xF83F0000UL)

/* Error Injection Controller for SF Domain */
#define APB_EIC_SAF_BASE (0xF9060000UL)

/* Input/Output Consistency */
#define APB_IOC_BASE (0xF8070000UL)

/* System Error Management 1 */
#define APB_SEM1_BASE (0xF0470000UL)

/* System Error Management 2 */
#define APB_SEM2_BASE (0xF0480000UL)


/*------------------------------------------------------
 * Internal Memory Configuration
 *------------------------------------------------------*/

/* Fake Memory Map Unit (FMMU) for Cortex-R5 LP */
#define APB_FMMU_LP_BASE (0xF0530000UL)

/* Corherent RAM LP Controller */
#define APB_IRAM_LP_BASE (0xF05A0000UL)

/* IRAM1 RAM Controller */
#define APB_IRAMC1_BASE (0xF9010000UL)

/* IRAM2 RAM Controller */
#define APB_IRAMC2_BASE (0xF9020000UL)

/* IRAM3 RAM Controller */
#define APB_IRAMC3_BASE (0xF9030000UL)

/* MRAM1 Controller */
#define APB_MRAM1_BASE (0xF8640000UL)

/* MRAM2 Controller */
#define APB_MRAM2_BASE (0xF8650000UL)

/* MRAM3 Controller */
#define APB_MRAM3_BASE (0xF8660000UL)

/* MRAM4 Controller */
#define APB_MRAM4_BASE (0xF8670000UL)

/* MRAM5 Controller */
#define APB_MRAM5_BASE (0xF0570000UL)

/* Fake Memory Map Unit (FMMU) for Cortex-R5 SE */
#define APB_R5_SE_FMMU_BASE (0xF2080000UL)

/* Fake Memory Map Unit (FMMU) for Cortex-R52 */
#define APB_R52_FMMU_BASE (0xF87F0000UL)

/* Cortex-R52 Flash Port 0 FMMU */
#define APB_R52P_F0_FMMU_BASE (0xF87F0000UL)

/* Cortex-R52 Flash Port 1 FMMU */
#define APB_R52P_F1_FMMU_BASE (0xF87F2000UL)

/* Cortex-R52 Flash Port 2 FMMU */
#define APB_R52P_F2_FMMU_BASE (0xF87F4000UL)

/* Cortex-R52 Flash Port 3 FMMU */
#define APB_R52P_F3_FMMU_BASE (0xF87F6000UL)

/* Cortex-R52 Master Port 0 FMMU */
#define APB_R52P_M0_FMMU_BASE (0xF87F8000UL)

/* Cortex-R52 Master Port 1 FMMU */
#define APB_R52P_M1_FMMU_BASE (0xF87FA000UL)

/* Cortex-R52 Master Port 2 FMMU */
#define APB_R52P_M2_FMMU_BASE (0xF87FC000UL)

/* Cortex-R52 Master Port 3 FMMU */
#define APB_R52P_M3_FMMU_BASE (0xF87FE000UL)

/* Internal ROM Controller */
#define APB_ROMC_BASE (0xF9070000UL)


/*------------------------------------------------------
 * Access Permission Control
 *------------------------------------------------------*/

/* Inline ECC Controller */
#define APB_IECC_BASE (0xF9080000UL)

/* Memory Access Controller S0 */
#define APB_MAC_S0_BASE (0xF8840000UL)

/* Memory Access Controller S1 */
#define APB_MAC_S1_BASE (0xF8850000UL)


/*------------------------------------------------------
 * I/O Control
 *------------------------------------------------------*/

/* IO MULtiplexing Controller(IOMUXC) for SF Boot */
#define APB_IOMUXC_CPU_BASE (0xF85F0000UL)

/* IO MULtiplexing Controller(IOMUXC) for LP */
#define APB_IOMUXC_LP_BASE (0xF07A0000UL)

/* IO MULtiplexing Controller(IOMUXC) for SF Main */
#define APB_IOMUXC_MAIN_DOWN_BASE (0xF9040000UL)

/* IO MULtiplexing Controller(IOMUXC) for SF Main */
#define APB_IOMUXC_MAIN_UP_BASE (0xF9050000UL)

/* IO MULtiplexing Controller(IOMUXC) for RTC */
#define APB_IOMUXC_RTC_BASE (0xF0070000UL)

/* IO MULtiplexing Controller(IOMUXC) for SF Top */
#define APB_IOMUXC_TOP_BASE (0xF8100000UL)


/*------------------------------------------------------
 * Interrupt
 *------------------------------------------------------*/

/* IRQ Log Wrapper */
#define APB_IRQ_LOG_BASE (0xF87A0000UL)

/* Vectored Interrupt Controller (VIC) 1 Base Address, for Cortex-R5 LP Core */
#define VIC1_BASE (0xF1000000UL)

/* Vectored Interrupt Controller (VIC) 2 Base Address, for Cortex-R5 SE Core */
#define VIC2_BASE (0xF3200000UL)

/* General Interrupt Controller (GIC) Base Address, for Cortex-R52 */
#define GIC_BASE (0xF4000000UL)


/*------------------------------------------------------
 * Misc
 *------------------------------------------------------*/

/* In System Test Controller */
#define APB_ISTC_BASE (0xF04A0000UL)


/*------------------------------------------------------
 * CPU
 *------------------------------------------------------*/

/* Pre-Fetch Unit (PFU) for Cortex-R5 LP */
#define APB_PFU_LP_BASE (0xF0520000UL)

/* Pre-Fetch Unit (PFU) for Cortex-R5 SE */
#define APB_R5_SE_PFU_BASE (0xF2090000UL)

/* Cortex-R5 SE core D-Cache */
#define R5_SE_CACHE_R5_SE_DCACHE_BASE (0x100E0000UL)

/* Cortex-R5 SE core I-Cache */
#define R5_SE_CACHE_R5_SE_ICACHE_BASE (0x100C0000UL)

/* Cortex-R5 SE core TCM A Address */
#define R5_SE_TCM_R5_SE_TCMA_BASE (0x10080000UL)

/* Cortex-R5 LP core D-Cache */
#define R5_LP_CACHE_R5_LP_DCACHE_BASE (0x10060000UL)

/* Cortex-R5 LP core I-Cache */
#define R5_LP_CACHE_R5_LP_ICACHE_BASE (0x10040000UL)

/* Cortex-R5 LP core TCM A Address */
#define R5_LP_TCM_R5_LP_TCMA_BASE (0x10000000UL)

/* Cortex-R52 Core 0 TCM C Address */
#define R52P_CORE0_TCM_R52_CORE0_TCMC (0x11200000UL)

/* Cortex-R52 Core 0 TCM B Address */
#define R52P_CORE0_TCM_R52_CORE0_TCMB (0x11100000UL)

/* Cortex-R52 Core 0 TCM A Address */
#define R52P_CORE0_TCM_R52_CORE0_TCMA (0x11000000UL)

/* Cortex-R52 Core 1 TCM C Address */
#define R52P_CORE1_TCM_R52_CORE1_TCMC (0x11600000UL)

/* Cortex-R52 Core 1 TCM B Address */
#define R52P_CORE1_TCM_R52_CORE1_TCMB (0x11500000UL)

/* Cortex-R52 Core 1 TCM A Address */
#define R52P_CORE1_TCM_R52_CORE1_TCMA (0x11400000UL)

/* Cortex-R52 Core 2 TCM C Address */
#define R52P_CORE2_TCM_R52_CORE2_TCMC (0x11A00000UL)

/* Cortex-R52 Core 2 TCM B Address */
#define R52P_CORE2_TCM_R52_CORE2_TCMB (0x11900000UL)

/* Cortex-R52 Core 2 TCM A Address */
#define R52P_CORE2_TCM_R52_CORE2_TCMA (0x11800000UL)

/* Cortex-R52 Core 3 TCM C Address */
#define R52P_CORE3_TCM_R52_CORE3_TCMC (0x11E00000UL)

/* Cortex-R52 Core 3 TCM B Address */
#define R52P_CORE3_TCM_R52_CORE3_TCMB (0x11D00000UL)

/* Cortex-R52 Core 3 TCM A Address */
#define R52P_CORE3_TCM_R52_CORE3_TCMA (0x11C00000UL)


/*------------------------------------------------------
 * Audio
 *------------------------------------------------------*/

/* Serial Audio Controller Interface 1 */
#define APB_SACI1_BASE (0xF8C10000UL)


/*------------------------------------------------------
 * System Control
 *------------------------------------------------------*/

/* LP Domain Status and Controller Register (SCR) */
#define APB_SCR_LP_BASE (0xF07C0000UL)

/* SF Domain Status and Controller Register (SCR) */
#define APB_SCR_SAETY_BOOT_BASE (0xF8090000UL)


/*------------------------------------------------------
 * External Memory Interface
 *------------------------------------------------------*/

/* SD/EMMC Host Controller */
#define APB_SEHC_BASE (0xF90B0000UL)

/* Extended SPI 1 Port A Control Registers */
#define APB_XSPI1A_BASE (0xF9090000UL)

/* Extended SPI 1 Port B Control Registers */
#define APB_XSPI1B_BASE (0xF90A0000UL)

/* Extended SPI1 Port A Address */
#define XSPI1_XSPI1PORTA_BASE (0x20000000UL)

/* Extended SPI1 Port B Address */
#define XSPI1_XSPI1PORTB_BASE (0x18000000UL)


/*------------------------------------------------------
 * CRAM
 *------------------------------------------------------*/

/* Corherent RAM 1 */
#define CRAM1_BASE (0x00800000UL)

/* Corherent RAM 2 */
#define CRAM2_BASE (0x00840000UL)

/* Corherent RAM 3 */
#define CRAM3_BASE (0x00880000UL)

/* Corherent RAM 4 */
#define CRAM4_BASE (0x008C0000UL)

/* RAM for CRAM 1 ECC. Used as Corherent RAM when ECC is disabled. */
#define CRAM1_ECC_BASE (0x00918000UL)

/* RAM for CRAM 2 ECC. Used as Corherent RAM when ECC is disabled. */
#define CRAM2_ECC_BASE (0x00910000UL)

/* RAM for CRAM 3 ECC. Used as Corherent RAM when ECC is disabled. */
#define CRAM3_ECC_BASE (0x00908000UL)

/* RAM for CRAM 4 ECC. Used as Corherent RAM when ECC is disabled. */
#define CRAM4_ECC_BASE (0x00900000UL)


/*------------------------------------------------------
 * IRAM
 *------------------------------------------------------*/

/* Internal RAM 1 */
#define IRAM1_BASE (0x00A00000UL)

/* RAM for IRAM1 ECC. Used as internal RAM when ECC is disabled. */
#define IRAM1_ECC_BASE (0x00D40000UL)

/* Internal RAM 2 */
#define IRAM2_BASE (0x00B00000UL)

/* RAM for IRAM2 ECC. Used as internal RAM when ECC is disabled. */
#define IRAM2_ECC_BASE (0x00D20000UL)

/* Internal RAM 3 */
#define IRAM3_BASE (0x00C00000UL)

/* RAM for IRAM3 ECC. Used as internal RAM when ECC is disabled. */
#define IRAM3_ECC_BASE (0x00D00000UL)

/* Internal RAM LP */
#define IRAM_LP_BASE (0x00F00000UL)

/* RAM for IRAM LP ECC. Used as internal RAM when ECC is disabled. */
#define IRAM_LP_ECC_BASE (0x00F20000UL)


/*------------------------------------------------------
 * MRAM
 *------------------------------------------------------*/

/* Magnetoresistive RAM 1 Flash Port Address. ReadOnly For Cortex-R52, ReadWrite For Cortex-R5 LP and SE. */
#define MRAM1_F_BASE (0x08000000UL)

/* Magnetoresistive RAM 2 Flash Port Address. ReadOnly For Cortex-R52, ReadWrite For Cortex-R5 LP and SE. */
#define MRAM2_F_BASE (0x08400000UL)

/* Magnetoresistive RAM 3 Flash Port Address. ReadOnly For Cortex-R52, ReadWrite For Cortex-R5 LP and SE. */
#define MRAM3_F_BASE (0x08800000UL)

/* Magnetoresistive RAM 4 Flash Port Address. ReadOnly For Cortex-R52, ReadWrite For Cortex-R5 LP and SE. */
#define MRAM4_F_BASE (0x08C00000UL)

/* Magnetoresistive RAM 5 Flash Port Address. ReadOnly For Cortex-R52, ReadWrite For Cortex-R5 LP and SE. */
#define MRAM5_F_BASE (0x09000000UL)

/* Magnetoresistive RAM 1 Master Port Address. ReadWrite For Cortex-R52, Not Access For Cortex-R5 LP and SE. */
#define MRAM1_M_BASE (0x01000000UL)

/* Magnetoresistive RAM 2 Master Port Address. ReadWrite For Cortex-R52, Not Access For Cortex-R5 LP and SE. */
#define MRAM2_M_BASE (0x01400000UL)

/* Magnetoresistive RAM 3 Master Port Address. ReadWrite For Cortex-R52, Not Access For Cortex-R5 LP and SE. */
#define MRAM3_M_BASE (0x01800000UL)

/* Magnetoresistive RAM 4 Master Port Address. ReadWrite For Cortex-R52, Not Access For Cortex-R5 LP and SE. */
#define MRAM4_M_BASE (0x01C00000UL)

/* Magnetoresistive RAM 5 Master Port Address. ReadWrite For Cortex-R52, Not Access For Cortex-R5 LP and SE. */
#define MRAM5_M_BASE (0x02000000UL)


/*------------------------------------------------------
 * Mailbox
 *------------------------------------------------------*/

/* Mailbox Buffer */
#define MB_MEM_BASE (0xFA001000UL)

/* Mailbox Register */
#define MB_REG_BASE (0xFA000000UL)

#endif /* REGS_BASE_E3650_H */
