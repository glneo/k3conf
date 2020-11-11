/*
 * J7200 Sec Proxy Info
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

struct ti_sci_sec_proxy_info j7200_main_sp_info[] = {
	[0] = {148, "read", 9, "DM", "nonsec_high_priority_rx"},
	[1] = {147, "read", 36, "DM", "nonsec_low_priority_rx"},
	[2] = {146, "read", 9, "DM", "nonsec_notify_resp_rx"},
	[3] = {145, "write", 2, "DM", "nonsec_A72_2_notify_tx"},
	[4] = {144, "write", 22, "DM", "nonsec_A72_2_response_tx"},
	[5] = {143, "write", 2, "DM", "nonsec_A72_3_notify_tx"},
	[6] = {142, "write", 7, "DM", "nonsec_A72_3_response_tx"},
	[7] = {141, "write", 2, "DM", "nonsec_A72_4_notify_tx"},
	[8] = {140, "write", 7, "DM", "nonsec_A72_4_response_tx"},
	[9] = {139, "write", 2, "DM", "nonsec_MAIN_0_R5_0_notify_tx"},
	[10] = {138, "write", 7, "DM", "nonsec_MAIN_0_R5_0_response_tx"},
	[11] = {137, "write", 1, "DM", "nonsec_MAIN_0_R5_2_notify_tx"},
	[12] = {136, "write", 2, "DM", "nonsec_MAIN_0_R5_2_response_tx"},
	[13] = {0, "read", 2, "A72_0", "notify"},
	[14] = {1, "read", 30, "A72_0", "response"},
	[15] = {2, "write", 10, "A72_0", "high_priority"},
	[16] = {3, "write", 20, "A72_0", "low_priority"},
	[17] = {4, "write", 2, "A72_0", "notify_resp"},
	[18] = {5, "read", 2, "A72_1", "notify"},
	[19] = {6, "read", 30, "A72_1", "response"},
	[20] = {7, "write", 10, "A72_1", "high_priority"},
	[21] = {8, "write", 20, "A72_1", "low_priority"},
	[22] = {9, "write", 2, "A72_1", "notify_resp"},
	[23] = {10, "read", 2, "A72_2", "notify"},
	[24] = {11, "read", 22, "A72_2", "response"},
	[25] = {12, "write", 2, "A72_2", "high_priority"},
	[26] = {13, "write", 20, "A72_2", "low_priority"},
	[27] = {14, "write", 2, "A72_2", "notify_resp"},
	[28] = {15, "read", 2, "A72_3", "notify"},
	[29] = {16, "read", 7, "A72_3", "response"},
	[30] = {17, "write", 2, "A72_3", "high_priority"},
	[31] = {18, "write", 5, "A72_3", "low_priority"},
	[32] = {19, "write", 2, "A72_3", "notify_resp"},
	[33] = {20, "read", 2, "A72_4", "notify"},
	[34] = {21, "read", 7, "A72_4", "response"},
	[35] = {22, "write", 2, "A72_4", "high_priority"},
	[36] = {23, "write", 5, "A72_4", "low_priority"},
	[37] = {24, "write", 2, "A72_4", "notify_resp"},
	[38] = {25, "read", 2, "MAIN_0_R5_0", "notify"},
	[39] = {26, "read", 7, "MAIN_0_R5_0", "response"},
	[40] = {27, "write", 2, "MAIN_0_R5_0", "high_priority"},
	[41] = {28, "write", 5, "MAIN_0_R5_0", "low_priority"},
	[42] = {29, "write", 2, "MAIN_0_R5_0", "notify_resp"},
	[43] = {30, "read", 2, "MAIN_0_R5_1", "notify"},
	[44] = {31, "read", 7, "MAIN_0_R5_1", "response"},
	[45] = {32, "write", 2, "MAIN_0_R5_1", "high_priority"},
	[46] = {33, "write", 5, "MAIN_0_R5_1", "low_priority"},
	[47] = {34, "write", 2, "MAIN_0_R5_1", "notify_resp"},
	[48] = {35, "read", 1, "MAIN_0_R5_2", "notify"},
	[49] = {36, "read", 2, "MAIN_0_R5_2", "response"},
	[50] = {37, "write", 1, "MAIN_0_R5_2", "high_priority"},
	[51] = {38, "write", 1, "MAIN_0_R5_2", "low_priority"},
	[52] = {39, "write", 1, "MAIN_0_R5_2", "notify_resp"},
	[53] = {40, "read", 1, "MAIN_0_R5_3", "notify"},
	[54] = {41, "read", 2, "MAIN_0_R5_3", "response"},
	[55] = {42, "write", 1, "MAIN_0_R5_3", "high_priority"},
	[56] = {43, "write", 1, "MAIN_0_R5_3", "low_priority"},
	[57] = {44, "write", 1, "MAIN_0_R5_3", "notify_resp"},
};

struct ti_sci_sec_proxy_info j7200_mcu_sp_info[] = {
	[0] = {80, "read", 13, "DM", "nonsec_high_priority_rx"},
	[1] = {79, "read", 13, "DM", "nonsec_low_priority_rx"},
	[2] = {78, "read", 5, "DM", "nonsec_notify_resp_rx"},
	[3] = {77, "write", 2, "DM", "nonsec_MCU_0_R5_0_notify_tx"},
	[4] = {76, "write", 20, "DM", "nonsec_MCU_0_R5_0_response_tx"},
	[5] = {75, "write", 1, "DM", "nonsec_MCU_0_R5_2_notify_tx"},
	[6] = {74, "write", 2, "DM", "nonsec_MCU_0_R5_2_response_tx"},
	[7] = {73, "write", 2, "DM", "nonsec_DMSC2DM_notify_tx"},
	[8] = {72, "write", 4, "DM", "nonsec_DMSC2DM_response_tx"},
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
	[29] = {20, "read", 2, "DM2DMSC", "notify"},
	[30] = {21, "read", 4, "DM2DMSC", "response"},
	[31] = {22, "write", 2, "DM2DMSC", "high_priority"},
	[32] = {23, "write", 2, "DM2DMSC", "low_priority"},
	[33] = {24, "write", 2, "DM2DMSC", "notify_resp"},
	[34] = {25, "read", 2, "DMSC2DM", "notify"},
	[35] = {26, "read", 4, "DMSC2DM", "response"},
	[36] = {27, "write", 2, "DMSC2DM", "high_priority"},
	[37] = {28, "write", 2, "DMSC2DM", "low_priority"},
	[38] = {29, "write", 2, "DMSC2DM", "notify_resp"},
};
