/*
 * AM65X_SR2 Devices Info
 *
 * Copyright (C) 2020 Texas Instruments Incorporated - https://www.ti.com/
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <tisci.h>
#include <socinfo.h>

struct ti_sci_devices_info am65x_sr2_devices_info[] = {
	{0, "AM6_DEV_MCU_ADC0"},
	{1, "AM6_DEV_MCU_ADC1"},
	{2, "AM6_DEV_CAL0"},
	{3, "AM6_DEV_CMPEVENT_INTRTR0"},
	{5, "AM6_DEV_MCU_CPSW0"},
	{6, "AM6_DEV_CPT2_AGGR0"},
	{7, "AM6_DEV_MCU_CPT2_AGGR0"},
	{8, "AM6_DEV_STM0"},
	{9, "AM6_DEV_DCC0"},
	{10, "AM6_DEV_DCC1"},
	{11, "AM6_DEV_DCC2"},
	{12, "AM6_DEV_DCC3"},
	{13, "AM6_DEV_DCC4"},
	{14, "AM6_DEV_DCC5"},
	{15, "AM6_DEV_DCC6"},
	{16, "AM6_DEV_DCC7"},
	{17, "AM6_DEV_MCU_DCC0"},
	{18, "AM6_DEV_MCU_DCC1"},
	{19, "AM6_DEV_MCU_DCC2"},
	{20, "AM6_DEV_DDRSS0"},
	{21, "AM6_DEV_DEBUGSS_WRAP0"},
	{22, "AM6_DEV_WKUP_DMSC0"},
	{23, "AM6_DEV_TIMER0"},
	{24, "AM6_DEV_TIMER1"},
	{25, "AM6_DEV_TIMER10"},
	{26, "AM6_DEV_TIMER11"},
	{27, "AM6_DEV_TIMER2"},
	{28, "AM6_DEV_TIMER3"},
	{29, "AM6_DEV_TIMER4"},
	{30, "AM6_DEV_TIMER5"},
	{31, "AM6_DEV_TIMER6"},
	{32, "AM6_DEV_TIMER7"},
	{33, "AM6_DEV_TIMER8"},
	{34, "AM6_DEV_TIMER9"},
	{35, "AM6_DEV_MCU_TIMER0"},
	{36, "AM6_DEV_MCU_TIMER1"},
	{37, "AM6_DEV_MCU_TIMER2"},
	{38, "AM6_DEV_MCU_TIMER3"},
	{39, "AM6_DEV_ECAP0"},
	{40, "AM6_DEV_EHRPWM0"},
	{41, "AM6_DEV_EHRPWM1"},
	{42, "AM6_DEV_EHRPWM2"},
	{43, "AM6_DEV_EHRPWM3"},
	{44, "AM6_DEV_EHRPWM4"},
	{45, "AM6_DEV_EHRPWM5"},
	{46, "AM6_DEV_ELM0"},
	{47, "AM6_DEV_MMCSD0"},
	{48, "AM6_DEV_MMCSD1"},
	{49, "AM6_DEV_EQEP0"},
	{50, "AM6_DEV_EQEP1"},
	{51, "AM6_DEV_EQEP2"},
	{52, "AM6_DEV_ESM0"},
	{53, "AM6_DEV_MCU_ESM0"},
	{54, "AM6_DEV_WKUP_ESM0"},
	{55, "AM6_DEV_FSS_MCU_0"},
	{56, "AM6_DEV_GIC0"},
	{57, "AM6_DEV_GPIO0"},
	{58, "AM6_DEV_GPIO1"},
	{59, "AM6_DEV_WKUP_GPIO0"},
	{60, "AM6_DEV_GPMC0"},
	{61, "AM6_DEV_GTC0"},
	{62, "AM6_DEV_PRU_ICSSG0"},
	{63, "AM6_DEV_PRU_ICSSG1"},
	{64, "AM6_DEV_PRU_ICSSG2"},
	{65, "AM6_DEV_GPU0"},
	{66, "AM6_DEV_CCDEBUGSS0"},
	{67, "AM6_DEV_DSS0"},
	{68, "AM6_DEV_DEBUGSS0"},
	{69, "AM6_DEV_EFUSE0"},
	{70, "AM6_DEV_PSC0"},
	{71, "AM6_DEV_MCU_DEBUGSS0"},
	{72, "AM6_DEV_MCU_EFUSE0"},
	{73, "AM6_DEV_PBIST0"},
	{74, "AM6_DEV_PBIST1"},
	{75, "AM6_DEV_MCU_PBIST0"},
	{76, "AM6_DEV_PLLCTRL0"},
	{77, "AM6_DEV_WKUP_PLLCTRL0"},
	{78, "AM6_DEV_MCU_ROM0"},
	{79, "AM6_DEV_WKUP_PSC0"},
	{80, "AM6_DEV_WKUP_VTM0"},
	{81, "AM6_DEV_DEBUGSUSPENDRTR0"},
	{82, "AM6_DEV_CBASS0"},
	{83, "AM6_DEV_CBASS_DEBUG0"},
	{84, "AM6_DEV_CBASS_FW0"},
	{85, "AM6_DEV_CBASS_INFRA0"},
	{86, "AM6_DEV_ECC_AGGR0"},
	{87, "AM6_DEV_ECC_AGGR1"},
	{88, "AM6_DEV_ECC_AGGR2"},
	{89, "AM6_DEV_MCU_CBASS0"},
	{90, "AM6_DEV_MCU_CBASS_DEBUG0"},
	{91, "AM6_DEV_MCU_CBASS_FW0"},
	{92, "AM6_DEV_MCU_ECC_AGGR0"},
	{93, "AM6_DEV_MCU_ECC_AGGR1"},
	{94, "AM6_DEV_WKUP_CBASS0"},
	{95, "AM6_DEV_WKUP_ECC_AGGR0"},
	{96, "AM6_DEV_WKUP_CBASS_FW0"},
	{97, "AM6_DEV_MAIN2MCU_LVL_INTRTR0"},
	{98, "AM6_DEV_MAIN2MCU_PLS_INTRTR0"},
	{99, "AM6_DEV_CTRL_MMR0"},
	{100, "AM6_DEV_GPIOMUX_INTRTR0"},
	{101, "AM6_DEV_PLL_MMR0"},
	{102, "AM6_DEV_MCU_MCAN0"},
	{103, "AM6_DEV_MCU_MCAN1"},
	{104, "AM6_DEV_MCASP0"},
	{105, "AM6_DEV_MCASP1"},
	{106, "AM6_DEV_MCASP2"},
	{107, "AM6_DEV_MCU_CTRL_MMR0"},
	{108, "AM6_DEV_MCU_PLL_MMR0"},
	{109, "AM6_DEV_MCU_SEC_MMR0"},
	{110, "AM6_DEV_I2C0"},
	{111, "AM6_DEV_I2C1"},
	{112, "AM6_DEV_I2C2"},
	{113, "AM6_DEV_I2C3"},
	{114, "AM6_DEV_MCU_I2C0"},
	{115, "AM6_DEV_WKUP_I2C0"},
	{116, "AM6_DEV_MCU_MSRAM0"},
	{117, "AM6_DEV_DFTSS0"},
	{118, "AM6_DEV_NAVSS0"},
	{119, "AM6_DEV_MCU_NAVSS0"},
	{120, "AM6_DEV_PCIE0"},
	{121, "AM6_DEV_PCIE1"},
	{122, "AM6_DEV_PDMA_DEBUG0"},
	{123, "AM6_DEV_PDMA0"},
	{124, "AM6_DEV_PDMA1"},
	{125, "AM6_DEV_MCU_PDMA0"},
	{126, "AM6_DEV_MCU_PDMA1"},
	{127, "AM6_DEV_MCU_PSRAM0"},
	{128, "AM6_DEV_PSRAMECC0"},
	{129, "AM6_DEV_MCU_ARMSS0"},
	{130, "AM6_DEV_RTI0"},
	{131, "AM6_DEV_RTI1"},
	{132, "AM6_DEV_RTI2"},
	{133, "AM6_DEV_RTI3"},
	{134, "AM6_DEV_MCU_RTI0"},
	{135, "AM6_DEV_MCU_RTI1"},
	{136, "AM6_DEV_SA2_UL0"},
	{137, "AM6_DEV_MCSPI0"},
	{138, "AM6_DEV_MCSPI1"},
	{139, "AM6_DEV_MCSPI2"},
	{140, "AM6_DEV_MCSPI3"},
	{141, "AM6_DEV_MCSPI4"},
	{142, "AM6_DEV_MCU_MCSPI0"},
	{143, "AM6_DEV_MCU_MCSPI1"},
	{144, "AM6_DEV_MCU_MCSPI2"},
	{145, "AM6_DEV_TIMESYNC_INTRTR0"},
	{146, "AM6_DEV_UART0"},
	{147, "AM6_DEV_UART1"},
	{148, "AM6_DEV_UART2"},
	{149, "AM6_DEV_MCU_UART0"},
	{150, "AM6_DEV_WKUP_UART0"},
	{151, "AM6_DEV_USB3SS0"},
	{152, "AM6_DEV_USB3SS1"},
	{153, "AM6_DEV_SERDES0"},
	{154, "AM6_DEV_SERDES1"},
	{155, "AM6_DEV_WKUP_CTRL_MMR0"},
	{156, "AM6_DEV_WKUP_GPIOMUX_INTRTR0"},
	{157, "AM6_DEV_BOARD0"},
	{159, "AM6_DEV_MCU_ARMSS0_CPU0"},
	{161, "AM6_DEV_WKUP_DMSC0_CORTEX_M3_0"},
	{163, "AM6_DEV_NAVSS0_CPTS0"},
	{164, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER0"},
	{165, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER1"},
	{166, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER2"},
	{167, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER3"},
	{168, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER4"},
	{169, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER5"},
	{170, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER6"},
	{171, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER7"},
	{172, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER8"},
	{173, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER9"},
	{174, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER10"},
	{175, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER11"},
	{176, "AM6_DEV_NAVSS0_MCRC0"},
	{177, "AM6_DEV_NAVSS0_PVU0"},
	{178, "AM6_DEV_NAVSS0_PVU1"},
	{179, "AM6_DEV_NAVSS0_UDMASS_INTA0"},
	{180, "AM6_DEV_NAVSS0_MODSS_INTA0"},
	{181, "AM6_DEV_NAVSS0_MODSS_INTA1"},
	{182, "AM6_DEV_NAVSS0_INTR_ROUTER_0"},
	{183, "AM6_DEV_NAVSS0_TIMER_MGR0"},
	{184, "AM6_DEV_NAVSS0_TIMER_MGR1"},
	{185, "AM6_DEV_NAVSS0_PROXY0"},
	{187, "AM6_DEV_NAVSS0_RINGACC0"},
	{188, "AM6_DEV_NAVSS0_UDMAP0"},
	{189, "AM6_DEV_MCU_NAVSS0_INTR_AGGR_0"},
	{190, "AM6_DEV_MCU_NAVSS0_INTR_ROUTER_0"},
	{191, "AM6_DEV_MCU_NAVSS0_PROXY0"},
	{193, "AM6_DEV_MCU_NAVSS0_MCRC0"},
	{194, "AM6_DEV_MCU_NAVSS0_UDMAP0"},
	{195, "AM6_DEV_MCU_NAVSS0_RINGACC0"},
	{196, "AM6_DEV_COMPUTE_CLUSTER_MSMC0"},
	{197, "AM6_DEV_COMPUTE_CLUSTER_PBIST0"},
	{198, "AM6_DEV_COMPUTE_CLUSTER_CPAC0"},
	{199, "AM6_DEV_COMPUTE_CLUSTER_CPAC_PBIST0"},
	{200, "AM6_DEV_COMPUTE_CLUSTER_CPAC1"},
	{201, "AM6_DEV_COMPUTE_CLUSTER_CPAC_PBIST1"},
	{202, "AM6_DEV_COMPUTE_CLUSTER_A53_0"},
	{203, "AM6_DEV_COMPUTE_CLUSTER_A53_1"},
	{204, "AM6_DEV_COMPUTE_CLUSTER_A53_2"},
	{205, "AM6_DEV_COMPUTE_CLUSTER_A53_3"},
	{206, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVSRAMLO_4"},
	{207, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_FSS_S1_3"},
	{208, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_EXPORT_SLV_0"},
	{209, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVSRAMHI_3"},
	{210, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_SRAM_SLV_1"},
	{211, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVDDRHI_5"},
	{212, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVDDRLO_6"},
	{213, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_CAL0_0"},
	{214, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_DSS_2"},
	{215, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_FSS_S0_2"},
	{216, "AM6_DEV_OLDI_TX_CORE_MAIN_0"},
	{217, "AM6_DEV_K3_ARM_ATB_FUNNEL_3_32_MCU_0"},
	{218, "AM6_DEV_ICEMELTER_WKUP_0"},
	{219, "AM6_DEV_K3_LED_MAIN_0"},
	{220, "AM6_DEV_VDC_DATA_VBUSM_32B_REF_WKUP2MCU"},
	{221, "AM6_DEV_VDC_DATA_VBUSM_32B_REF_MCU2WKUP"},
	{222, "AM6_DEV_VDC_DATA_VBUSM_64B_REF_MAIN2MCU"},
	{223, "AM6_DEV_VDC_DATA_VBUSM_64B_REF_MCU2MAIN"},
	{224, "AM6_DEV_VDC_DMSC_DBG_VBUSP_32B_REF_DBG2DMSC"},
	{225, "AM6_DEV_VDC_INFRA_VBUSP_32B_REF_WKUP2MAIN_INFRA"},
	{226, "AM6_DEV_VDC_INFRA_VBUSP_32B_REF_MCU2MAIN_INFRA"},
	{227, "AM6_DEV_VDC_SOC_FW_VBUSP_32B_REF_FWWKUP2MCU"},
	{228, "AM6_DEV_VDC_SOC_FW_VBUSP_32B_REF_FWMCU2MAIN"},
	{229, "AM6_DEV_VDC_MCU_DBG_VBUSP_32B_REF_DBGMAIN2MCU"},
	{230, "AM6_DEV_VDC_NAV_PSIL_128B_REF_MAIN2MCU"},
	{231, "AM6_DEV_GS80PRG_SOC_WRAP_WKUP_0"},
	{232, "AM6_DEV_GS80PRG_MCU_WRAP_WKUP_0"},
	{233, "AM6_DEV_MX_WAKEUP_RESET_SYNC_WKUP_0"},
	{234, "AM6_DEV_MX_EFUSE_MAIN_CHAIN_MAIN_0"},
	{235, "AM6_DEV_MX_EFUSE_MCU_CHAIN_MCU_0"},
	{236, "AM6_DEV_DUMMY_IP_LPSC_WKUP2MCU_VD"},
	{237, "AM6_DEV_DUMMY_IP_LPSC_WKUP2MAIN_INFRA_VD"},
	{238, "AM6_DEV_DUMMY_IP_LPSC_DEBUG2DMSC_VD"},
	{239, "AM6_DEV_DUMMY_IP_LPSC_DMSC_VD"},
	{240, "AM6_DEV_DUMMY_IP_LPSC_MCU2MAIN_INFRA_VD"},
	{241, "AM6_DEV_DUMMY_IP_LPSC_MCU2MAIN_VD"},
	{242, "AM6_DEV_DUMMY_IP_LPSC_MCU2WKUP_VD"},
	{243, "AM6_DEV_DUMMY_IP_LPSC_MAIN2MCU_VD"},
	{244, "AM6_DEV_DUMMY_IP_LPSC_EMIF_DATA_VD"},
	{245, "AM6_DEV_MCU_ARMSS0_CPU1"},
	{246, "AM6_DEV_MCU_FSS0_FSAS_0"},
	{247, "AM6_DEV_MCU_FSS0_HYPERBUS0"},
	{248, "AM6_DEV_MCU_FSS0_OSPI_0"},
	{249, "AM6_DEV_MCU_FSS0_OSPI_1"},
};
