/*
 * J721S2 Sec Proxy Info
 *
 * Copyright (C) 2022 Texas Instruments Incorporated - https://www.ti.com/
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

struct ti_sci_sec_proxy_info j721s2_main_sp_info[] = {
	[0] = {350, "read", 18, "DM", "nonsec_high_priority_rx"},
	[1] = {349, "read", 57, "DM", "nonsec_low_priority_rx"},
	[2] = {348, "read", 18, "DM", "nonsec_notify_resp_rx"},
	[3] = {347, "write", 2, "DM", "nonsec_A72_2_notify_tx"},
	[4] = {346, "write", 22, "DM", "nonsec_A72_2_response_tx"},
	[5] = {345, "write", 2, "DM", "nonsec_A72_3_notify_tx"},
	[6] = {344, "write", 7, "DM", "nonsec_A72_3_response_tx"},
	[7] = {343, "write", 2, "DM", "nonsec_A72_4_notify_tx"},
	[8] = {342, "write", 7, "DM", "nonsec_A72_4_response_tx"},
	[9] = {341, "write", 2, "DM", "nonsec_C7X_0_1_notify_tx"},
	[10] = {340, "write", 7, "DM", "nonsec_C7X_0_1_response_tx"},
	[11] = {339, "write", 2, "DM", "nonsec_C7X_1_1_notify_tx"},
	[12] = {338, "write", 7, "DM", "nonsec_C7X_1_1_response_tx"},
	[13] = {337, "write", 2, "DM", "nonsec_GPU_0_notify_tx"},
	[14] = {336, "write", 7, "DM", "nonsec_GPU_0_response_tx"},
	[15] = {335, "write", 2, "DM", "nonsec_MAIN_0_R5_0_notify_tx"},
	[16] = {334, "write", 7, "DM", "nonsec_MAIN_0_R5_0_response_tx"},
	[17] = {333, "write", 1, "DM", "nonsec_MAIN_0_R5_2_notify_tx"},
	[18] = {332, "write", 2, "DM", "nonsec_MAIN_0_R5_2_response_tx"},
	[19] = {331, "write", 2, "DM", "nonsec_MAIN_1_R5_0_notify_tx"},
	[20] = {330, "write", 7, "DM", "nonsec_MAIN_1_R5_0_response_tx"},
	[21] = {329, "write", 1, "DM", "nonsec_MAIN_1_R5_2_notify_tx"},
	[22] = {328, "write", 2, "DM", "nonsec_MAIN_1_R5_2_response_tx"},
	[23] = {0, "read", 2, "A72_0", "notify"},
	[24] = {1, "read", 30, "A72_0", "response"},
	[25] = {2, "write", 10, "A72_0", "high_priority"},
	[26] = {3, "write", 20, "A72_0", "low_priority"},
	[27] = {4, "write", 2, "A72_0", "notify_resp"},
	[28] = {5, "read", 2, "A72_1", "notify"},
	[29] = {6, "read", 30, "A72_1", "response"},
	[30] = {7, "write", 10, "A72_1", "high_priority"},
	[31] = {8, "write", 20, "A72_1", "low_priority"},
	[32] = {9, "write", 2, "A72_1", "notify_resp"},
	[33] = {10, "read", 2, "A72_2", "notify"},
	[34] = {11, "read", 22, "A72_2", "response"},
	[35] = {12, "write", 2, "A72_2", "high_priority"},
	[36] = {13, "write", 20, "A72_2", "low_priority"},
	[37] = {14, "write", 2, "A72_2", "notify_resp"},
	[38] = {15, "read", 2, "A72_3", "notify"},
	[39] = {16, "read", 7, "A72_3", "response"},
	[40] = {17, "write", 2, "A72_3", "high_priority"},
	[41] = {18, "write", 5, "A72_3", "low_priority"},
	[42] = {19, "write", 2, "A72_3", "notify_resp"},
	[43] = {20, "read", 2, "A72_4", "notify"},
	[44] = {21, "read", 7, "A72_4", "response"},
	[45] = {22, "write", 2, "A72_4", "high_priority"},
	[46] = {23, "write", 5, "A72_4", "low_priority"},
	[47] = {24, "write", 2, "A72_4", "notify_resp"},
	[48] = {25, "read", 2, "C7X_0_0", "notify"},
	[49] = {26, "read", 7, "C7X_0_0", "response"},
	[50] = {27, "write", 2, "C7X_0_0", "high_priority"},
	[51] = {28, "write", 5, "C7X_0_0", "low_priority"},
	[52] = {29, "write", 2, "C7X_0_0", "notify_resp"},
	[53] = {30, "read", 2, "C7X_0_1", "notify"},
	[54] = {31, "read", 7, "C7X_0_1", "response"},
	[55] = {32, "write", 2, "C7X_0_1", "high_priority"},
	[56] = {33, "write", 5, "C7X_0_1", "low_priority"},
	[57] = {34, "write", 2, "C7X_0_1", "notify_resp"},
	[58] = {35, "read", 2, "C7X_1_0", "notify"},
	[59] = {36, "read", 7, "C7X_1_0", "response"},
	[60] = {37, "write", 2, "C7X_1_0", "high_priority"},
	[61] = {38, "write", 5, "C7X_1_0", "low_priority"},
	[62] = {39, "write", 2, "C7X_1_0", "notify_resp"},
	[63] = {40, "read", 2, "C7X_1_1", "notify"},
	[64] = {41, "read", 7, "C7X_1_1", "response"},
	[65] = {42, "write", 2, "C7X_1_1", "high_priority"},
	[66] = {43, "write", 5, "C7X_1_1", "low_priority"},
	[67] = {44, "write", 2, "C7X_1_1", "notify_resp"},
	[68] = {45, "read", 2, "GPU_0", "notify"},
	[69] = {46, "read", 7, "GPU_0", "response"},
	[70] = {47, "write", 2, "GPU_0", "high_priority"},
	[71] = {48, "write", 5, "GPU_0", "low_priority"},
	[72] = {49, "write", 2, "GPU_0", "notify_resp"},
	[73] = {50, "read", 2, "MAIN_0_R5_0", "notify"},
	[74] = {51, "read", 7, "MAIN_0_R5_0", "response"},
	[75] = {52, "write", 2, "MAIN_0_R5_0", "high_priority"},
	[76] = {53, "write", 5, "MAIN_0_R5_0", "low_priority"},
	[77] = {54, "write", 2, "MAIN_0_R5_0", "notify_resp"},
	[78] = {55, "read", 2, "MAIN_0_R5_1", "notify"},
	[79] = {56, "read", 7, "MAIN_0_R5_1", "response"},
	[80] = {57, "write", 2, "MAIN_0_R5_1", "high_priority"},
	[81] = {58, "write", 5, "MAIN_0_R5_1", "low_priority"},
	[82] = {59, "write", 2, "MAIN_0_R5_1", "notify_resp"},
	[83] = {60, "read", 1, "MAIN_0_R5_2", "notify"},
	[84] = {61, "read", 2, "MAIN_0_R5_2", "response"},
	[85] = {62, "write", 1, "MAIN_0_R5_2", "high_priority"},
	[86] = {63, "write", 1, "MAIN_0_R5_2", "low_priority"},
	[87] = {64, "write", 1, "MAIN_0_R5_2", "notify_resp"},
	[88] = {65, "read", 1, "MAIN_0_R5_3", "notify"},
	[89] = {66, "read", 2, "MAIN_0_R5_3", "response"},
	[90] = {67, "write", 1, "MAIN_0_R5_3", "high_priority"},
	[91] = {68, "write", 1, "MAIN_0_R5_3", "low_priority"},
	[92] = {69, "write", 1, "MAIN_0_R5_3", "notify_resp"},
	[93] = {70, "read", 2, "MAIN_1_R5_0", "notify"},
	[94] = {71, "read", 7, "MAIN_1_R5_0", "response"},
	[95] = {72, "write", 2, "MAIN_1_R5_0", "high_priority"},
	[96] = {73, "write", 5, "MAIN_1_R5_0", "low_priority"},
	[97] = {74, "write", 2, "MAIN_1_R5_0", "notify_resp"},
	[98] = {75, "read", 2, "MAIN_1_R5_1", "notify"},
	[99] = {76, "read", 7, "MAIN_1_R5_1", "response"},
	[100] = {77, "write", 2, "MAIN_1_R5_1", "high_priority"},
	[101] = {78, "write", 5, "MAIN_1_R5_1", "low_priority"},
	[102] = {79, "write", 2, "MAIN_1_R5_1", "notify_resp"},
	[103] = {80, "read", 1, "MAIN_1_R5_2", "notify"},
	[104] = {81, "read", 2, "MAIN_1_R5_2", "response"},
	[105] = {82, "write", 1, "MAIN_1_R5_2", "high_priority"},
	[106] = {83, "write", 1, "MAIN_1_R5_2", "low_priority"},
	[107] = {84, "write", 1, "MAIN_1_R5_2", "notify_resp"},
	[108] = {85, "read", 1, "MAIN_1_R5_3", "notify"},
	[109] = {86, "read", 2, "MAIN_1_R5_3", "response"},
	[110] = {87, "write", 1, "MAIN_1_R5_3", "high_priority"},
	[111] = {88, "write", 1, "MAIN_1_R5_3", "low_priority"},
	[112] = {89, "write", 1, "MAIN_1_R5_3", "notify_resp"},
};

struct ti_sci_sec_proxy_info j721s2_mcu_sp_info[] = {
	[0] = {78, "read", 13, "DM", "nonsec_high_priority_rx"},
	[1] = {77, "read", 13, "DM", "nonsec_low_priority_rx"},
	[2] = {76, "read", 5, "DM", "nonsec_notify_resp_rx"},
	[3] = {75, "write", 2, "DM", "nonsec_MCU_0_R5_0_notify_tx"},
	[4] = {74, "write", 20, "DM", "nonsec_MCU_0_R5_0_response_tx"},
	[5] = {73, "write", 1, "DM", "nonsec_MCU_0_R5_2_notify_tx"},
	[6] = {72, "write", 2, "DM", "nonsec_MCU_0_R5_2_response_tx"},
	[7] = {71, "write", 2, "DM", "nonsec_TIFS2DM_notify_tx"},
	[8] = {70, "write", 4, "DM", "nonsec_TIFS2DM_response_tx"},
	[9] = {0, "read", 2, "MCU_0_R5_0", "notify"},
	[10] = {1, "read", 20, "MCU_0_R5_0", "response"},
	[11] = {2, "write", 10, "MCU_0_R5_0", "high_priority"},
	[12] = {3, "write", 10, "MCU_0_R5_0", "low_priority"},
	[13] = {4, "write", 2, "MCU_0_R5_0", "notify_resp"},
	[14] = {5, "read", 2, "MCU_0_R5_1", "notify"},
	[15] = {6, "read", 20, "MCU_0_R5_1", "response"},
	[16] = {7, "write", 10, "MCU_0_R5_1", "high_priority"},
	[17] = {8, "write", 10, "MCU_0_R5_1", "low_priority"},
	[18] = {9, "write", 2, "MCU_0_R5_1", "notify_resp"},
	[19] = {10, "read", 1, "MCU_0_R5_2", "notify"},
	[20] = {11, "read", 2, "MCU_0_R5_2", "response"},
	[21] = {12, "write", 1, "MCU_0_R5_2", "high_priority"},
	[22] = {13, "write", 1, "MCU_0_R5_2", "low_priority"},
	[23] = {14, "write", 1, "MCU_0_R5_2", "notify_resp"},
	[24] = {15, "read", 1, "MCU_0_R5_3", "notify"},
	[25] = {16, "read", 2, "MCU_0_R5_3", "response"},
	[26] = {17, "write", 1, "MCU_0_R5_3", "high_priority"},
	[27] = {18, "write", 1, "MCU_0_R5_3", "low_priority"},
	[28] = {19, "write", 1, "MCU_0_R5_3", "notify_resp"},
	[29] = {20, "read", 2, "DM2TIFS", "notify"},
	[30] = {21, "read", 4, "DM2TIFS", "response"},
	[31] = {22, "write", 2, "DM2TIFS", "high_priority"},
	[32] = {23, "write", 2, "DM2TIFS", "low_priority"},
	[33] = {24, "write", 2, "DM2TIFS", "notify_resp"},
	[34] = {25, "read", 2, "TIFS2DM", "notify"},
	[35] = {26, "read", 4, "TIFS2DM", "response"},
	[36] = {27, "write", 2, "TIFS2DM", "high_priority"},
	[37] = {28, "write", 2, "TIFS2DM", "low_priority"},
	[38] = {29, "write", 2, "TIFS2DM", "notify_resp"},
	[39] = {30, "read", 1, "HSM", "notify"},
	[40] = {31, "read", 2, "HSM", "response"},
	[41] = {32, "write", 1, "HSM", "high_priority"},
	[42] = {33, "write", 1, "HSM", "low_priority"},
	[43] = {34, "write", 1, "HSM", "notify_resp"},
};
