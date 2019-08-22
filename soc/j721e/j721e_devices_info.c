/*
 * SoC Device Info
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

struct ti_sci_devices_info j721e_devices_info[] = {
	 [0] = {0, "J721E_DEV_MCU_ADC0"},
	 [1] = {1, "J721E_DEV_MCU_ADC1"},
	 [2] = {2, "J721E_DEV_ATL0"},
	 [3] = {3, "J721E_DEV_COMPUTE_CLUSTER_J7ES_TB_VDC_MAIN_0"},
	 [4] = {4, "J721E_DEV_A72SS0"},
	 [5] = {5, "J721E_DEV_COMPUTE_CLUSTER0_CFG_WRAP"},
	 [6] = {6, "J721E_DEV_COMPUTE_CLUSTER0_CLEC"},
	 [7] = {7, "J721E_DEV_COMPUTE_CLUSTER0_CORE_CORE"},
	 [8] = {8, "J721E_DEV_COMPUTE_CLUSTER0_DDR32SS_EMIF0_EW"},
	 [9] = {9, "J721E_DEV_COMPUTE_CLUSTER0_DEBUG_WRAP"},
	 [10] = {10, "J721E_DEV_COMPUTE_CLUSTER0_DIVH2_DIVH0"},
	 [11] = {11, "J721E_DEV_COMPUTE_CLUSTER0_DIVP_TFT0"},
	 [12] = {12, "J721E_DEV_COMPUTE_CLUSTER0_DMSC_WRAP"},
	 [13] = {13, "J721E_DEV_COMPUTE_CLUSTER0_EN_MSMC_DOMAIN"},
	 [14] = {14, "J721E_DEV_COMPUTE_CLUSTER0_GIC500SS"},
	 [15] = {15, "J721E_DEV_C71SS0"},
	 [16] = {16, "J721E_DEV_C71SS0_MMA"},
	 [17] = {17, "J721E_DEV_COMPUTE_CLUSTER0_PBIST_WRAP"},
	 [18] = {18, "J721E_DEV_MCU_CPSW0"},
	 [19] = {19, "J721E_DEV_CPSW0"},
	 [20] = {20, "J721E_DEV_CPT2_AGGR0"},
	 [21] = {21, "J721E_DEV_CPT2_AGGR1"},
	 [22] = {22, "J721E_DEV_DMSC_WKUP_0"},
	 [23] = {23, "J721E_DEV_CPT2_AGGR2"},
	 [24] = {24, "J721E_DEV_MCU_CPT2_AGGR0"},
	 [25] = {25, "J721E_DEV_CSI_PSILSS0"},
	 [26] = {26, "J721E_DEV_CSI_RX_IF0"},
	 [27] = {27, "J721E_DEV_CSI_RX_IF1"},
	 [28] = {28, "J721E_DEV_CSI_TX_IF0"},
	 [29] = {29, "J721E_DEV_STM0"},
	 [30] = {30, "J721E_DEV_DCC0"},
	 [31] = {31, "J721E_DEV_DCC1"},
	 [32] = {32, "J721E_DEV_DCC2"},
	 [33] = {33, "J721E_DEV_DCC3"},
	 [34] = {34, "J721E_DEV_DCC4"},
	 [35] = {35, "J721E_DEV_MCU_TIMER0"},
	 [36] = {36, "J721E_DEV_DCC5"},
	 [37] = {37, "J721E_DEV_DCC6"},
	 [38] = {38, "J721E_DEV_DCC7"},
	 [39] = {39, "J721E_DEV_DCC8"},
	 [40] = {40, "J721E_DEV_DCC9"},
	 [41] = {41, "J721E_DEV_DCC10"},
	 [42] = {42, "J721E_DEV_DCC11"},
	 [43] = {43, "J721E_DEV_DCC12"},
	 [44] = {44, "J721E_DEV_MCU_DCC0"},
	 [45] = {45, "J721E_DEV_MCU_DCC1"},
	 [46] = {46, "J721E_DEV_MCU_DCC2"},
	 [47] = {47, "J721E_DEV_DDR0"},
	 [48] = {48, "J721E_DEV_DMPAC_TOP_MAIN_0"},
	 [49] = {49, "J721E_DEV_TIMER0"},
	 [50] = {50, "J721E_DEV_TIMER1"},
	 [51] = {51, "J721E_DEV_TIMER2"},
	 [52] = {52, "J721E_DEV_TIMER3"},
	 [53] = {53, "J721E_DEV_TIMER4"},
	 [54] = {54, "J721E_DEV_TIMER5"},
	 [55] = {55, "J721E_DEV_TIMER6"},
	 [56] = {57, "J721E_DEV_TIMER7"},
	 [57] = {58, "J721E_DEV_TIMER8"},
	 [58] = {59, "J721E_DEV_TIMER9"},
	 [59] = {60, "J721E_DEV_TIMER10"},
	 [60] = {61, "J721E_DEV_GTC0"},
	 [61] = {62, "J721E_DEV_TIMER11"},
	 [62] = {63, "J721E_DEV_TIMER12"},
	 [63] = {64, "J721E_DEV_TIMER13"},
	 [64] = {65, "J721E_DEV_TIMER14"},
	 [65] = {66, "J721E_DEV_TIMER15"},
	 [66] = {67, "J721E_DEV_TIMER16"},
	 [67] = {68, "J721E_DEV_TIMER17"},
	 [68] = {69, "J721E_DEV_TIMER18"},
	 [69] = {70, "J721E_DEV_TIMER19"},
	 [70] = {71, "J721E_DEV_MCU_TIMER1"},
	 [71] = {72, "J721E_DEV_MCU_TIMER2"},
	 [72] = {73, "J721E_DEV_MCU_TIMER3"},
	 [73] = {74, "J721E_DEV_MCU_TIMER4"},
	 [74] = {75, "J721E_DEV_MCU_TIMER5"},
	 [75] = {76, "J721E_DEV_MCU_TIMER6"},
	 [76] = {77, "J721E_DEV_MCU_TIMER7"},
	 [77] = {78, "J721E_DEV_MCU_TIMER8"},
	 [78] = {79, "J721E_DEV_MCU_TIMER9"},
	 [79] = {80, "J721E_DEV_ECAP0"},
	 [80] = {81, "J721E_DEV_ECAP1"},
	 [81] = {82, "J721E_DEV_ECAP2"},
	 [82] = {83, "J721E_DEV_EHRPWM0"},
	 [83] = {84, "J721E_DEV_EHRPWM1"},
	 [84] = {85, "J721E_DEV_EHRPWM2"},
	 [85] = {86, "J721E_DEV_EHRPWM3"},
	 [86] = {87, "J721E_DEV_EHRPWM4"},
	 [87] = {88, "J721E_DEV_EHRPWM5"},
	 [88] = {89, "J721E_DEV_ELM0"},
	 [89] = {90, "J721E_DEV_EMIF_DATA_0_VD"},
	 [90] = {91, "J721E_DEV_MMCSD0"},
	 [91] = {92, "J721E_DEV_MMCSD1"},
	 [92] = {93, "J721E_DEV_MMCSD2"},
	 [93] = {94, "J721E_DEV_EQEP0"},
	 [94] = {95, "J721E_DEV_EQEP1"},
	 [95] = {96, "J721E_DEV_EQEP2"},
	 [96] = {97, "J721E_DEV_ESM0"},
	 [97] = {98, "J721E_DEV_MCU_ESM0"},
	 [98] = {99, "J721E_DEV_WKUP_ESM0"},
	 [99] = {100, "J721E_DEV_FSS_MCU_0"},
	 [100] = {101, "J721E_DEV_MCU_FSS0_FSAS_0"},
	 [101] = {102, "J721E_DEV_MCU_FSS0_HYPERBUS1P0_0"},
	 [102] = {103, "J721E_DEV_MCU_FSS0_OSPI_0"},
	 [103] = {104, "J721E_DEV_MCU_FSS0_OSPI_1"},
	 [104] = {105, "J721E_DEV_GPIO0"},
	 [105] = {106, "J721E_DEV_GPIO1"},
	 [106] = {107, "J721E_DEV_GPIO2"},
	 [107] = {108, "J721E_DEV_GPIO3"},
	 [108] = {109, "J721E_DEV_GPIO4"},
	 [109] = {110, "J721E_DEV_GPIO5"},
	 [110] = {111, "J721E_DEV_GPIO6"},
	 [111] = {112, "J721E_DEV_GPIO7"},
	 [112] = {113, "J721E_DEV_WKUP_GPIO0"},
	 [113] = {114, "J721E_DEV_WKUP_GPIO1"},
	 [114] = {115, "J721E_DEV_GPMC0"},
	 [115] = {116, "J721E_DEV_I3C0"},
	 [116] = {117, "J721E_DEV_MCU_I3C0"},
	 [117] = {118, "J721E_DEV_MCU_I3C1"},
	 [118] = {119, "J721E_DEV_PRU_ICSSG0"},
	 [119] = {120, "J721E_DEV_PRU_ICSSG1"},
	 [120] = {121, "J721E_DEV_C66SS0_INTROUTER0"},
	 [121] = {122, "J721E_DEV_C66SS1_INTROUTER0"},
	 [122] = {123, "J721E_DEV_CMPEVENT_INTRTR0"},
	 [123] = {124, "J721E_DEV_J7_LASCAR_GPU_WRAP_MAIN_0"},
	 [124] = {125, "J721E_DEV_GPU0_GPU_0"},
	 [125] = {126, "J721E_DEV_GPU0_GPUCORE_0"},
	 [126] = {127, "J721E_DEV_LED0"},
	 [127] = {128, "J721E_DEV_MAIN2MCU_LVL_INTRTR0"},
	 [128] = {130, "J721E_DEV_MAIN2MCU_PLS_INTRTR0"},
	 [129] = {131, "J721E_DEV_GPIOMUX_INTRTR0"},
	 [130] = {132, "J721E_DEV_WKUP_PORZ_SYNC0"},
	 [131] = {133, "J721E_DEV_PSC0"},
	 [132] = {134, "J721E_DEV_R5FSS0_INTROUTER0"},
	 [133] = {135, "J721E_DEV_R5FSS1_INTROUTER0"},
	 [134] = {136, "J721E_DEV_TIMESYNC_INTRTR0"},
	 [135] = {137, "J721E_DEV_WKUP_GPIOMUX_INTRTR0"},
	 [136] = {138, "J721E_DEV_WKUP_PSC0"},
	 [137] = {139, "J721E_DEV_AASRC0"},
	 [138] = {140, "J721E_DEV_K3_C66_COREPAC_MAIN_0"},
	 [139] = {141, "J721E_DEV_K3_C66_COREPAC_MAIN_1"},
	 [140] = {142, "J721E_DEV_C66SS0_CORE0"},
	 [141] = {143, "J721E_DEV_C66SS1_CORE0"},
	 [142] = {144, "J721E_DEV_DECODER0"},
	 [143] = {145, "J721E_DEV_WKUP_DDPA0"},
	 [144] = {146, "J721E_DEV_UART0"},
	 [145] = {147, "J721E_DEV_DPHY_RX0"},
	 [146] = {148, "J721E_DEV_DPHY_RX1"},
	 [147] = {149, "J721E_DEV_MCU_UART0"},
	 [148] = {150, "J721E_DEV_DSS_DSI0"},
	 [149] = {151, "J721E_DEV_DSS_EDP0"},
	 [150] = {152, "J721E_DEV_DSS0"},
	 [151] = {153, "J721E_DEV_ENCODER0"},
	 [152] = {154, "J721E_DEV_WKUP_VTM0"},
	 [153] = {155, "J721E_DEV_MAIN2WKUPMCU_VD"},
	 [154] = {156, "J721E_DEV_MCAN0"},
	 [155] = {157, "J721E_DEV_BOARD0"},
	 [156] = {158, "J721E_DEV_MCAN1"},
	 [157] = {160, "J721E_DEV_MCAN2"},
	 [158] = {161, "J721E_DEV_MCAN3"},
	 [159] = {162, "J721E_DEV_MCAN4"},
	 [160] = {163, "J721E_DEV_MCAN5"},
	 [161] = {164, "J721E_DEV_MCAN6"},
	 [162] = {165, "J721E_DEV_MCAN7"},
	 [163] = {166, "J721E_DEV_MCAN8"},
	 [164] = {167, "J721E_DEV_MCAN9"},
	 [165] = {168, "J721E_DEV_MCAN10"},
	 [166] = {169, "J721E_DEV_MCAN11"},
	 [167] = {170, "J721E_DEV_MCAN12"},
	 [168] = {171, "J721E_DEV_MCAN13"},
	 [169] = {172, "J721E_DEV_MCU_MCAN0"},
	 [170] = {173, "J721E_DEV_MCU_MCAN1"},
	 [171] = {174, "J721E_DEV_MCASP0"},
	 [172] = {175, "J721E_DEV_MCASP1"},
	 [173] = {176, "J721E_DEV_MCASP2"},
	 [174] = {177, "J721E_DEV_MCASP3"},
	 [175] = {178, "J721E_DEV_MCASP4"},
	 [176] = {179, "J721E_DEV_MCASP5"},
	 [177] = {180, "J721E_DEV_MCASP6"},
	 [178] = {181, "J721E_DEV_MCASP7"},
	 [179] = {182, "J721E_DEV_MCASP8"},
	 [180] = {183, "J721E_DEV_MCASP9"},
	 [181] = {184, "J721E_DEV_MCASP10"},
	 [182] = {185, "J721E_DEV_MCASP11"},
	 [183] = {186, "J721E_DEV_MLB0"},
	 [184] = {187, "J721E_DEV_I2C0"},
	 [185] = {188, "J721E_DEV_I2C1"},
	 [186] = {189, "J721E_DEV_I2C2"},
	 [187] = {190, "J721E_DEV_I2C3"},
	 [188] = {191, "J721E_DEV_I2C4"},
	 [189] = {192, "J721E_DEV_I2C5"},
	 [190] = {193, "J721E_DEV_I2C6"},
	 [191] = {194, "J721E_DEV_MCU_I2C0"},
	 [192] = {195, "J721E_DEV_MCU_I2C1"},
	 [193] = {197, "J721E_DEV_WKUP_I2C0"},
	 [194] = {199, "J721E_DEV_NAVSS512L_MAIN_0"},
	 [195] = {201, "J721E_DEV_NAVSS0_CPTS_0"},
	 [196] = {202, "J721E_DEV_A72SS0_CORE0"},
	 [197] = {203, "J721E_DEV_A72SS0_CORE1"},
	 [198] = {206, "J721E_DEV_NAVSS0_DTI_0"},
	 [199] = {207, "J721E_DEV_NAVSS0_MODSS_INTAGGR_0"},
	 [200] = {208, "J721E_DEV_NAVSS0_MODSS_INTAGGR_1"},
	 [201] = {209, "J721E_DEV_NAVSS0_UDMASS_INTAGGR_0"},
	 [202] = {210, "J721E_DEV_NAVSS0_PROXY_0"},
	 [203] = {211, "J721E_DEV_NAVSS0_RINGACC_0"},
	 [204] = {212, "J721E_DEV_NAVSS0_UDMAP_0"},
	 [205] = {213, "J721E_DEV_NAVSS0_INTR_ROUTER_0"},
	 [206] = {214, "J721E_DEV_NAVSS0_MAILBOX_0"},
	 [207] = {215, "J721E_DEV_NAVSS0_MAILBOX_1"},
	 [208] = {216, "J721E_DEV_NAVSS0_MAILBOX_2"},
	 [209] = {217, "J721E_DEV_NAVSS0_MAILBOX_3"},
	 [210] = {218, "J721E_DEV_NAVSS0_MAILBOX_4"},
	 [211] = {219, "J721E_DEV_NAVSS0_MAILBOX_5"},
	 [212] = {220, "J721E_DEV_NAVSS0_MAILBOX_6"},
	 [213] = {221, "J721E_DEV_NAVSS0_MAILBOX_7"},
	 [214] = {222, "J721E_DEV_NAVSS0_MAILBOX_8"},
	 [215] = {223, "J721E_DEV_NAVSS0_MAILBOX_9"},
	 [216] = {224, "J721E_DEV_NAVSS0_MAILBOX_10"},
	 [217] = {225, "J721E_DEV_NAVSS0_MAILBOX_11"},
	 [218] = {226, "J721E_DEV_NAVSS0_SPINLOCK_0"},
	 [219] = {227, "J721E_DEV_NAVSS0_MCRC_0"},
	 [220] = {228, "J721E_DEV_NAVSS0_TBU_0"},
	 [221] = {229, "J721E_DEV_NAVSS0_TCU_0"},
	 [222] = {230, "J721E_DEV_NAVSS0_TIMERMGR_0"},
	 [223] = {231, "J721E_DEV_NAVSS0_TIMERMGR_1"},
	 [224] = {232, "J721E_DEV_NAVSS_MCU_J7_MCU_0"},
	 [225] = {233, "J721E_DEV_MCU_NAVSS0_INTAGGR_0"},
	 [226] = {234, "J721E_DEV_MCU_NAVSS0_PROXY_0"},
	 [227] = {235, "J721E_DEV_MCU_NAVSS0_RINGACC_0"},
	 [228] = {236, "J721E_DEV_MCU_NAVSS0_UDMAP_0"},
	 [229] = {237, "J721E_DEV_MCU_NAVSS0_INTR_ROUTER_0"},
	 [230] = {238, "J721E_DEV_MCU_NAVSS0_MCRC_0"},
	 [231] = {239, "J721E_DEV_PCIE0"},
	 [232] = {240, "J721E_DEV_PCIE1"},
	 [233] = {241, "J721E_DEV_PCIE2"},
	 [234] = {242, "J721E_DEV_PCIE3"},
	 [235] = {243, "J721E_DEV_PULSAR_SL_MAIN_0"},
	 [236] = {244, "J721E_DEV_PULSAR_SL_MAIN_1"},
	 [237] = {245, "J721E_DEV_R5FSS0_CORE0"},
	 [238] = {246, "J721E_DEV_R5FSS0_CORE1"},
	 [239] = {247, "J721E_DEV_R5FSS1_CORE0"},
	 [240] = {248, "J721E_DEV_R5FSS1_CORE1"},
	 [241] = {249, "J721E_DEV_PULSAR_SL_MCU_0"},
	 [242] = {250, "J721E_DEV_MCU_R5FSS0_CORE0"},
	 [243] = {251, "J721E_DEV_MCU_R5FSS0_CORE1"},
	 [244] = {252, "J721E_DEV_RTI0"},
	 [245] = {253, "J721E_DEV_RTI1"},
	 [246] = {254, "J721E_DEV_RTI24"},
	 [247] = {255, "J721E_DEV_RTI25"},
	 [248] = {256, "J721E_DEV_RTI16"},
	 [249] = {257, "J721E_DEV_RTI15"},
	 [250] = {258, "J721E_DEV_RTI28"},
	 [251] = {259, "J721E_DEV_RTI29"},
	 [252] = {260, "J721E_DEV_RTI30"},
	 [253] = {261, "J721E_DEV_RTI31"},
	 [254] = {262, "J721E_DEV_MCU_RTI0"},
	 [255] = {263, "J721E_DEV_MCU_RTI1"},
	 [256] = {264, "J721E_DEV_SA2_UL0"},
	 [257] = {265, "J721E_DEV_MCU_SA2_UL0"},
	 [258] = {266, "J721E_DEV_MCSPI0"},
	 [259] = {267, "J721E_DEV_MCSPI1"},
	 [260] = {268, "J721E_DEV_MCSPI2"},
	 [261] = {269, "J721E_DEV_MCSPI3"},
	 [262] = {270, "J721E_DEV_MCSPI4"},
	 [263] = {271, "J721E_DEV_MCSPI5"},
	 [264] = {272, "J721E_DEV_MCSPI6"},
	 [265] = {273, "J721E_DEV_MCSPI7"},
	 [266] = {274, "J721E_DEV_MCU_MCSPI0"},
	 [267] = {275, "J721E_DEV_MCU_MCSPI1"},
	 [268] = {276, "J721E_DEV_MCU_MCSPI2"},
	 [269] = {277, "J721E_DEV_UFS0"},
	 [270] = {278, "J721E_DEV_UART1"},
	 [271] = {279, "J721E_DEV_UART2"},
	 [272] = {280, "J721E_DEV_UART3"},
	 [273] = {281, "J721E_DEV_UART4"},
	 [274] = {282, "J721E_DEV_UART5"},
	 [275] = {283, "J721E_DEV_UART6"},
	 [276] = {284, "J721E_DEV_UART7"},
	 [277] = {285, "J721E_DEV_UART8"},
	 [278] = {286, "J721E_DEV_UART9"},
	 [279] = {287, "J721E_DEV_WKUP_UART0"},
	 [280] = {288, "J721E_DEV_USB0"},
	 [281] = {289, "J721E_DEV_USB1"},
	 [282] = {290, "J721E_DEV_VPAC_TOP_MAIN_0"},
	 [283] = {291, "J721E_DEV_VPFE0"},
	 [284] = {292, "J721E_DEV_SERDES_16G0"},
	 [285] = {293, "J721E_DEV_SERDES_16G1"},
	 [286] = {294, "J721E_DEV_SERDES_16G2"},
	 [287] = {295, "J721E_DEV_SERDES_16G3"},
	 [288] = {296, "J721E_DEV_DPHY_TX0"},
	 [289] = {297, "J721E_DEV_SERDES_10G0"},
	 [290] = {298, "J721E_DEV_WKUPMCU2MAIN_VD"},
	 [291] = {299, "J721E_DEV_NAVSS0_MODSS"},
	 [292] = {300, "J721E_DEV_NAVSS0_UDMASS"},
	 [293] = {301, "J721E_DEV_NAVSS0_VIRTSS"},
	 [294] = {302, "J721E_DEV_MCU_NAVSS0_MODSS"},
	 [295] = {303, "J721E_DEV_MCU_NAVSS0_UDMASS"},
	 [296] = {304, "J721E_DEV_DEBUGSS_WRAP0"},
	 [297] = {305, "J721E_DEV_DMPAC0_SDE_0"},
};