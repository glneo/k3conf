/*
 * AM65X_SR2 Devices Info
 *
 * Copyright (C) 2020 Texas Instruments Incorporated - http://www.ti.com/
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
	[0] = {0, "AM6_DEV_MCU_ADC0"},
	[1] = {1, "AM6_DEV_MCU_ADC1"},
	[2] = {2, "AM6_DEV_CAL0"},
	[3] = {3, "AM6_DEV_CMPEVENT_INTRTR0"},
	[4] = {5, "AM6_DEV_MCU_CPSW0"},
	[5] = {6, "AM6_DEV_CPT2_AGGR0"},
	[6] = {7, "AM6_DEV_MCU_CPT2_AGGR0"},
	[7] = {8, "AM6_DEV_STM0"},
	[8] = {9, "AM6_DEV_DCC0"},
	[9] = {10, "AM6_DEV_DCC1"},
	[10] = {11, "AM6_DEV_DCC2"},
	[11] = {12, "AM6_DEV_DCC3"},
	[12] = {13, "AM6_DEV_DCC4"},
	[13] = {14, "AM6_DEV_DCC5"},
	[14] = {15, "AM6_DEV_DCC6"},
	[15] = {16, "AM6_DEV_DCC7"},
	[16] = {17, "AM6_DEV_MCU_DCC0"},
	[17] = {18, "AM6_DEV_MCU_DCC1"},
	[18] = {19, "AM6_DEV_MCU_DCC2"},
	[19] = {20, "AM6_DEV_DDRSS0"},
	[20] = {21, "AM6_DEV_DEBUGSS_WRAP0"},
	[21] = {22, "AM6_DEV_WKUP_DMSC0"},
	[22] = {23, "AM6_DEV_TIMER0"},
	[23] = {24, "AM6_DEV_TIMER1"},
	[24] = {25, "AM6_DEV_TIMER10"},
	[25] = {26, "AM6_DEV_TIMER11"},
	[26] = {27, "AM6_DEV_TIMER2"},
	[27] = {28, "AM6_DEV_TIMER3"},
	[28] = {29, "AM6_DEV_TIMER4"},
	[29] = {30, "AM6_DEV_TIMER5"},
	[30] = {31, "AM6_DEV_TIMER6"},
	[31] = {32, "AM6_DEV_TIMER7"},
	[32] = {33, "AM6_DEV_TIMER8"},
	[33] = {34, "AM6_DEV_TIMER9"},
	[34] = {35, "AM6_DEV_MCU_TIMER0"},
	[35] = {36, "AM6_DEV_MCU_TIMER1"},
	[36] = {37, "AM6_DEV_MCU_TIMER2"},
	[37] = {38, "AM6_DEV_MCU_TIMER3"},
	[38] = {39, "AM6_DEV_ECAP0"},
	[39] = {40, "AM6_DEV_EHRPWM0"},
	[40] = {41, "AM6_DEV_EHRPWM1"},
	[41] = {42, "AM6_DEV_EHRPWM2"},
	[42] = {43, "AM6_DEV_EHRPWM3"},
	[43] = {44, "AM6_DEV_EHRPWM4"},
	[44] = {45, "AM6_DEV_EHRPWM5"},
	[45] = {46, "AM6_DEV_ELM0"},
	[46] = {47, "AM6_DEV_MMCSD0"},
	[47] = {48, "AM6_DEV_MMCSD1"},
	[48] = {49, "AM6_DEV_EQEP0"},
	[49] = {50, "AM6_DEV_EQEP1"},
	[50] = {51, "AM6_DEV_EQEP2"},
	[51] = {52, "AM6_DEV_ESM0"},
	[52] = {53, "AM6_DEV_MCU_ESM0"},
	[53] = {54, "AM6_DEV_WKUP_ESM0"},
	[54] = {55, "AM6_DEV_FSS_MCU_0"},
	[55] = {56, "AM6_DEV_GIC0"},
	[56] = {57, "AM6_DEV_GPIO0"},
	[57] = {58, "AM6_DEV_GPIO1"},
	[58] = {59, "AM6_DEV_WKUP_GPIO0"},
	[59] = {60, "AM6_DEV_GPMC0"},
	[60] = {61, "AM6_DEV_GTC0"},
	[61] = {62, "AM6_DEV_PRU_ICSSG0"},
	[62] = {63, "AM6_DEV_PRU_ICSSG1"},
	[63] = {64, "AM6_DEV_PRU_ICSSG2"},
	[64] = {65, "AM6_DEV_GPU0"},
	[65] = {66, "AM6_DEV_CCDEBUGSS0"},
	[66] = {67, "AM6_DEV_DSS0"},
	[67] = {68, "AM6_DEV_DEBUGSS0"},
	[68] = {69, "AM6_DEV_EFUSE0"},
	[69] = {70, "AM6_DEV_PSC0"},
	[70] = {71, "AM6_DEV_MCU_DEBUGSS0"},
	[71] = {72, "AM6_DEV_MCU_EFUSE0"},
	[72] = {73, "AM6_DEV_PBIST0"},
	[73] = {74, "AM6_DEV_PBIST1"},
	[74] = {75, "AM6_DEV_MCU_PBIST0"},
	[75] = {76, "AM6_DEV_PLLCTRL0"},
	[76] = {77, "AM6_DEV_WKUP_PLLCTRL0"},
	[77] = {78, "AM6_DEV_MCU_ROM0"},
	[78] = {79, "AM6_DEV_WKUP_PSC0"},
	[79] = {80, "AM6_DEV_WKUP_VTM0"},
	[80] = {81, "AM6_DEV_DEBUGSUSPENDRTR0"},
	[81] = {82, "AM6_DEV_CBASS0"},
	[82] = {83, "AM6_DEV_CBASS_DEBUG0"},
	[83] = {84, "AM6_DEV_CBASS_FW0"},
	[84] = {85, "AM6_DEV_CBASS_INFRA0"},
	[85] = {86, "AM6_DEV_ECC_AGGR0"},
	[86] = {87, "AM6_DEV_ECC_AGGR1"},
	[87] = {88, "AM6_DEV_ECC_AGGR2"},
	[88] = {89, "AM6_DEV_MCU_CBASS0"},
	[89] = {90, "AM6_DEV_MCU_CBASS_DEBUG0"},
	[90] = {91, "AM6_DEV_MCU_CBASS_FW0"},
	[91] = {92, "AM6_DEV_MCU_ECC_AGGR0"},
	[92] = {93, "AM6_DEV_MCU_ECC_AGGR1"},
	[93] = {94, "AM6_DEV_WKUP_CBASS0"},
	[94] = {95, "AM6_DEV_WKUP_ECC_AGGR0"},
	[95] = {96, "AM6_DEV_WKUP_CBASS_FW0"},
	[96] = {97, "AM6_DEV_MAIN2MCU_LVL_INTRTR0"},
	[97] = {98, "AM6_DEV_MAIN2MCU_PLS_INTRTR0"},
	[98] = {99, "AM6_DEV_CTRL_MMR0"},
	[99] = {100, "AM6_DEV_GPIOMUX_INTRTR0"},
	[100] = {101, "AM6_DEV_PLL_MMR0"},
	[101] = {102, "AM6_DEV_MCU_MCAN0"},
	[102] = {103, "AM6_DEV_MCU_MCAN1"},
	[103] = {104, "AM6_DEV_MCASP0"},
	[104] = {105, "AM6_DEV_MCASP1"},
	[105] = {106, "AM6_DEV_MCASP2"},
	[106] = {107, "AM6_DEV_MCU_CTRL_MMR0"},
	[107] = {108, "AM6_DEV_MCU_PLL_MMR0"},
	[108] = {109, "AM6_DEV_MCU_SEC_MMR0"},
	[109] = {110, "AM6_DEV_I2C0"},
	[110] = {111, "AM6_DEV_I2C1"},
	[111] = {112, "AM6_DEV_I2C2"},
	[112] = {113, "AM6_DEV_I2C3"},
	[113] = {114, "AM6_DEV_MCU_I2C0"},
	[114] = {115, "AM6_DEV_WKUP_I2C0"},
	[115] = {116, "AM6_DEV_MCU_MSRAM0"},
	[116] = {117, "AM6_DEV_DFTSS0"},
	[117] = {118, "AM6_DEV_NAVSS0"},
	[118] = {119, "AM6_DEV_MCU_NAVSS0"},
	[119] = {120, "AM6_DEV_PCIE0"},
	[120] = {121, "AM6_DEV_PCIE1"},
	[121] = {122, "AM6_DEV_PDMA_DEBUG0"},
	[122] = {123, "AM6_DEV_PDMA0"},
	[123] = {124, "AM6_DEV_PDMA1"},
	[124] = {125, "AM6_DEV_MCU_PDMA0"},
	[125] = {126, "AM6_DEV_MCU_PDMA1"},
	[126] = {127, "AM6_DEV_MCU_PSRAM0"},
	[127] = {128, "AM6_DEV_PSRAMECC0"},
	[128] = {129, "AM6_DEV_MCU_ARMSS0"},
	[129] = {130, "AM6_DEV_RTI0"},
	[130] = {131, "AM6_DEV_RTI1"},
	[131] = {132, "AM6_DEV_RTI2"},
	[132] = {133, "AM6_DEV_RTI3"},
	[133] = {134, "AM6_DEV_MCU_RTI0"},
	[134] = {135, "AM6_DEV_MCU_RTI1"},
	[135] = {136, "AM6_DEV_SA2_UL0"},
	[136] = {137, "AM6_DEV_MCSPI0"},
	[137] = {138, "AM6_DEV_MCSPI1"},
	[138] = {139, "AM6_DEV_MCSPI2"},
	[139] = {140, "AM6_DEV_MCSPI3"},
	[140] = {141, "AM6_DEV_MCSPI4"},
	[141] = {142, "AM6_DEV_MCU_MCSPI0"},
	[142] = {143, "AM6_DEV_MCU_MCSPI1"},
	[143] = {144, "AM6_DEV_MCU_MCSPI2"},
	[144] = {145, "AM6_DEV_TIMESYNC_INTRTR0"},
	[145] = {146, "AM6_DEV_UART0"},
	[146] = {147, "AM6_DEV_UART1"},
	[147] = {148, "AM6_DEV_UART2"},
	[148] = {149, "AM6_DEV_MCU_UART0"},
	[149] = {150, "AM6_DEV_WKUP_UART0"},
	[150] = {151, "AM6_DEV_USB3SS0"},
	[151] = {152, "AM6_DEV_USB3SS1"},
	[152] = {153, "AM6_DEV_SERDES0"},
	[153] = {154, "AM6_DEV_SERDES1"},
	[154] = {155, "AM6_DEV_WKUP_CTRL_MMR0"},
	[155] = {156, "AM6_DEV_WKUP_GPIOMUX_INTRTR0"},
	[156] = {157, "AM6_DEV_BOARD0"},
	[157] = {159, "AM6_DEV_MCU_ARMSS0_CPU0"},
	[158] = {161, "AM6_DEV_WKUP_DMSC0_CORTEX_M3_0"},
	[159] = {163, "AM6_DEV_NAVSS0_CPTS0"},
	[160] = {164, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER0"},
	[161] = {165, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER1"},
	[162] = {166, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER2"},
	[163] = {167, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER3"},
	[164] = {168, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER4"},
	[165] = {169, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER5"},
	[166] = {170, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER6"},
	[167] = {171, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER7"},
	[168] = {172, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER8"},
	[169] = {173, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER9"},
	[170] = {174, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER10"},
	[171] = {175, "AM6_DEV_NAVSS0_MAILBOX0_CLUSTER11"},
	[172] = {176, "AM6_DEV_NAVSS0_MCRC0"},
	[173] = {177, "AM6_DEV_NAVSS0_PVU0"},
	[174] = {178, "AM6_DEV_NAVSS0_PVU1"},
	[175] = {179, "AM6_DEV_NAVSS0_UDMASS_INTA0"},
	[176] = {180, "AM6_DEV_NAVSS0_MODSS_INTA0"},
	[177] = {181, "AM6_DEV_NAVSS0_MODSS_INTA1"},
	[178] = {182, "AM6_DEV_NAVSS0_INTR_ROUTER_0"},
	[179] = {183, "AM6_DEV_NAVSS0_TIMER_MGR0"},
	[180] = {184, "AM6_DEV_NAVSS0_TIMER_MGR1"},
	[181] = {185, "AM6_DEV_NAVSS0_PROXY0"},
	[182] = {187, "AM6_DEV_NAVSS0_RINGACC0"},
	[183] = {188, "AM6_DEV_NAVSS0_UDMAP0"},
	[184] = {189, "AM6_DEV_MCU_NAVSS0_INTR_AGGR_0"},
	[185] = {190, "AM6_DEV_MCU_NAVSS0_INTR_ROUTER_0"},
	[186] = {191, "AM6_DEV_MCU_NAVSS0_PROXY0"},
	[187] = {193, "AM6_DEV_MCU_NAVSS0_MCRC0"},
	[188] = {194, "AM6_DEV_MCU_NAVSS0_UDMAP0"},
	[189] = {195, "AM6_DEV_MCU_NAVSS0_RINGACC0"},
	[190] = {196, "AM6_DEV_COMPUTE_CLUSTER_MSMC0"},
	[191] = {197, "AM6_DEV_COMPUTE_CLUSTER_PBIST0"},
	[192] = {198, "AM6_DEV_COMPUTE_CLUSTER_CPAC0"},
	[193] = {199, "AM6_DEV_COMPUTE_CLUSTER_CPAC_PBIST0"},
	[194] = {200, "AM6_DEV_COMPUTE_CLUSTER_CPAC1"},
	[195] = {201, "AM6_DEV_COMPUTE_CLUSTER_CPAC_PBIST1"},
	[196] = {202, "AM6_DEV_COMPUTE_CLUSTER_A53_0"},
	[197] = {203, "AM6_DEV_COMPUTE_CLUSTER_A53_1"},
	[198] = {204, "AM6_DEV_COMPUTE_CLUSTER_A53_2"},
	[199] = {205, "AM6_DEV_COMPUTE_CLUSTER_A53_3"},
	[200] = {206, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVSRAMLO_4"},
	[201] = {207, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_FSS_S1_3"},
	[202] = {208, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_EXPORT_SLV_0"},
	[203] = {209, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVSRAMHI_3"},
	[204] = {210, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_SRAM_SLV_1"},
	[205] = {211, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVDDRHI_5"},
	[206] = {212, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_NAVDDRLO_6"},
	[207] = {213, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_CAL0_0"},
	[208] = {214, "AM6_DEV_CPT2_PROBE_VBUSM_MAIN_DSS_2"},
	[209] = {215, "AM6_DEV_CPT2_PROBE_VBUSM_MCU_FSS_S0_2"},
	[210] = {216, "AM6_DEV_OLDI_TX_CORE_MAIN_0"},
	[211] = {217, "AM6_DEV_K3_ARM_ATB_FUNNEL_3_32_MCU_0"},
	[212] = {218, "AM6_DEV_ICEMELTER_WKUP_0"},
	[213] = {219, "AM6_DEV_K3_LED_MAIN_0"},
	[214] = {220, "AM6_DEV_VDC_DATA_VBUSM_32B_REF_WKUP2MCU"},
	[215] = {221, "AM6_DEV_VDC_DATA_VBUSM_32B_REF_MCU2WKUP"},
	[216] = {222, "AM6_DEV_VDC_DATA_VBUSM_64B_REF_MAIN2MCU"},
	[217] = {223, "AM6_DEV_VDC_DATA_VBUSM_64B_REF_MCU2MAIN"},
	[218] = {224, "AM6_DEV_VDC_DMSC_DBG_VBUSP_32B_REF_DBG2DMSC"},
	[219] = {225, "AM6_DEV_VDC_INFRA_VBUSP_32B_REF_WKUP2MAIN_INFRA"},
	[220] = {226, "AM6_DEV_VDC_INFRA_VBUSP_32B_REF_MCU2MAIN_INFRA"},
	[221] = {227, "AM6_DEV_VDC_SOC_FW_VBUSP_32B_REF_FWWKUP2MCU"},
	[222] = {228, "AM6_DEV_VDC_SOC_FW_VBUSP_32B_REF_FWMCU2MAIN"},
	[223] = {229, "AM6_DEV_VDC_MCU_DBG_VBUSP_32B_REF_DBGMAIN2MCU"},
	[224] = {230, "AM6_DEV_VDC_NAV_PSIL_128B_REF_MAIN2MCU"},
	[225] = {231, "AM6_DEV_GS80PRG_SOC_WRAP_WKUP_0"},
	[226] = {232, "AM6_DEV_GS80PRG_MCU_WRAP_WKUP_0"},
	[227] = {233, "AM6_DEV_MX_WAKEUP_RESET_SYNC_WKUP_0"},
	[228] = {234, "AM6_DEV_MX_EFUSE_MAIN_CHAIN_MAIN_0"},
	[229] = {235, "AM6_DEV_MX_EFUSE_MCU_CHAIN_MCU_0"},
	[230] = {236, "AM6_DEV_DUMMY_IP_LPSC_WKUP2MCU_VD"},
	[231] = {237, "AM6_DEV_DUMMY_IP_LPSC_WKUP2MAIN_INFRA_VD"},
	[232] = {238, "AM6_DEV_DUMMY_IP_LPSC_DEBUG2DMSC_VD"},
	[233] = {239, "AM6_DEV_DUMMY_IP_LPSC_DMSC_VD"},
	[234] = {240, "AM6_DEV_DUMMY_IP_LPSC_MCU2MAIN_INFRA_VD"},
	[235] = {241, "AM6_DEV_DUMMY_IP_LPSC_MCU2MAIN_VD"},
	[236] = {242, "AM6_DEV_DUMMY_IP_LPSC_MCU2WKUP_VD"},
	[237] = {243, "AM6_DEV_DUMMY_IP_LPSC_MAIN2MCU_VD"},
	[238] = {244, "AM6_DEV_DUMMY_IP_LPSC_EMIF_DATA_VD"},
	[239] = {245, "AM6_DEV_MCU_ARMSS0_CPU1"},
	[240] = {246, "AM6_DEV_MCU_FSS0_FSAS_0"},
	[241] = {247, "AM6_DEV_MCU_FSS0_HYPERBUS0"},
	[242] = {248, "AM6_DEV_MCU_FSS0_OSPI_0"},
	[243] = {249, "AM6_DEV_MCU_FSS0_OSPI_1"},
};
