/*
 * J721E Sec Proxy Info
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

struct ti_sci_sec_proxy_info j721e_main_sp_info[] = {
	[0] = {0, "read", 2, "A72_0", "notify"},
	[1] = {1, "read", 30, "A72_0", "response"},
	[2] = {2, "write", 10, "A72_0", "high_priority"},
	[3] = {3, "write", 20, "A72_0", "low_priority"},
	[4] = {4, "write", 2, "A72_0", "notify_resp"},
	[5] = {5, "read", 2, "A72_1", "notify"},
	[6] = {6, "read", 30, "A72_1", "response"},
	[7] = {7, "write", 10, "A72_1", "high_priority"},
	[8] = {8, "write", 20, "A72_1", "low_priority"},
	[9] = {9, "write", 2, "A72_1", "notify_resp"},
	[10] = {10, "read", 2, "A72_2", "notify"},
	[11] = {11, "read", 22, "A72_2", "response"},
	[12] = {12, "write", 2, "A72_2", "high_priority"},
	[13] = {13, "write", 20, "A72_2", "low_priority"},
	[14] = {14, "write", 2, "A72_2", "notify_resp"},
	[15] = {15, "read", 2, "A72_3", "notify"},
	[16] = {16, "read", 7, "A72_3", "response"},
	[17] = {17, "write", 2, "A72_3", "high_priority"},
	[18] = {18, "write", 5, "A72_3", "low_priority"},
	[19] = {19, "write", 2, "A72_3", "notify_resp"},
	[20] = {20, "read", 2, "A72_4", "notify"},
	[21] = {21, "read", 7, "A72_4", "response"},
	[22] = {22, "write", 2, "A72_4", "high_priority"},
	[23] = {23, "write", 5, "A72_4", "low_priority"},
	[24] = {24, "write", 2, "A72_4", "notify_resp"},
	[25] = {25, "read", 2, "C7X_0", "notify"},
	[26] = {26, "read", 7, "C7X_0", "response"},
	[27] = {27, "write", 2, "C7X_0", "high_priority"},
	[28] = {28, "write", 5, "C7X_0", "low_priority"},
	[29] = {29, "write", 2, "C7X_0", "notify_resp"},
	[30] = {30, "read", 2, "C7X_1", "notify"},
	[31] = {31, "read", 7, "C7X_1", "response"},
	[32] = {32, "write", 2, "C7X_1", "high_priority"},
	[33] = {33, "write", 5, "C7X_1", "low_priority"},
	[34] = {34, "write", 2, "C7X_1", "notify_resp"},
	[35] = {35, "read", 2, "C6X_0_0", "notify"},
	[36] = {36, "read", 7, "C6X_0_0", "response"},
	[37] = {37, "write", 2, "C6X_0_0", "high_priority"},
	[38] = {38, "write", 5, "C6X_0_0", "low_priority"},
	[39] = {39, "write", 2, "C6X_0_0", "notify_resp"},
	[40] = {40, "read", 2, "C6X_0_1", "notify"},
	[41] = {41, "read", 7, "C6X_0_1", "response"},
	[42] = {42, "write", 2, "C6X_0_1", "high_priority"},
	[43] = {43, "write", 5, "C6X_0_1", "low_priority"},
	[44] = {44, "write", 2, "C6X_0_1", "notify_resp"},
	[45] = {45, "read", 2, "C6X_1_0", "notify"},
	[46] = {46, "read", 7, "C6X_1_0", "response"},
	[47] = {47, "write", 2, "C6X_1_0", "high_priority"},
	[48] = {48, "write", 5, "C6X_1_0", "low_priority"},
	[49] = {49, "write", 2, "C6X_1_0", "notify_resp"},
	[50] = {50, "read", 2, "C6X_1_1", "notify"},
	[51] = {51, "read", 7, "C6X_1_1", "response"},
	[52] = {52, "write", 2, "C6X_1_1", "high_priority"},
	[53] = {53, "write", 5, "C6X_1_1", "low_priority"},
	[54] = {54, "write", 2, "C6X_1_1", "notify_resp"},
	[55] = {55, "read", 2, "GPU_0", "notify"},
	[56] = {56, "read", 7, "GPU_0", "response"},
	[57] = {57, "write", 2, "GPU_0", "high_priority"},
	[58] = {58, "write", 5, "GPU_0", "low_priority"},
	[59] = {59, "write", 2, "GPU_0", "notify_resp"},
	[60] = {60, "read", 2, "MAIN_0_R5_0", "notify"},
	[61] = {61, "read", 7, "MAIN_0_R5_0", "response"},
	[62] = {62, "write", 2, "MAIN_0_R5_0", "high_priority"},
	[63] = {63, "write", 5, "MAIN_0_R5_0", "low_priority"},
	[64] = {64, "write", 2, "MAIN_0_R5_0", "notify_resp"},
	[65] = {65, "read", 2, "MAIN_0_R5_1", "notify"},
	[66] = {66, "read", 7, "MAIN_0_R5_1", "response"},
	[67] = {67, "write", 2, "MAIN_0_R5_1", "high_priority"},
	[68] = {68, "write", 5, "MAIN_0_R5_1", "low_priority"},
	[69] = {69, "write", 2, "MAIN_0_R5_1", "notify_resp"},
	[70] = {70, "read", 1, "MAIN_0_R5_2", "notify"},
	[71] = {71, "read", 2, "MAIN_0_R5_2", "response"},
	[72] = {72, "write", 1, "MAIN_0_R5_2", "high_priority"},
	[73] = {73, "write", 1, "MAIN_0_R5_2", "low_priority"},
	[74] = {74, "write", 1, "MAIN_0_R5_2", "notify_resp"},
	[75] = {75, "read", 1, "MAIN_0_R5_3", "notify"},
	[76] = {76, "read", 2, "MAIN_0_R5_3", "response"},
	[77] = {77, "write", 1, "MAIN_0_R5_3", "high_priority"},
	[78] = {78, "write", 1, "MAIN_0_R5_3", "low_priority"},
	[79] = {79, "write", 1, "MAIN_0_R5_3", "notify_resp"},
	[80] = {80, "read", 2, "MAIN_1_R5_0", "notify"},
	[81] = {81, "read", 7, "MAIN_1_R5_0", "response"},
	[82] = {82, "write", 2, "MAIN_1_R5_0", "high_priority"},
	[83] = {83, "write", 5, "MAIN_1_R5_0", "low_priority"},
	[84] = {84, "write", 2, "MAIN_1_R5_0", "notify_resp"},
	[85] = {85, "read", 2, "MAIN_1_R5_1", "notify"},
	[86] = {86, "read", 7, "MAIN_1_R5_1", "response"},
	[87] = {87, "write", 2, "MAIN_1_R5_1", "high_priority"},
	[88] = {88, "write", 5, "MAIN_1_R5_1", "low_priority"},
	[89] = {89, "write", 2, "MAIN_1_R5_1", "notify_resp"},
	[90] = {90, "read", 1, "MAIN_1_R5_2", "notify"},
	[91] = {91, "read", 2, "MAIN_1_R5_2", "response"},
	[92] = {92, "write", 1, "MAIN_1_R5_2", "high_priority"},
	[93] = {93, "write", 1, "MAIN_1_R5_2", "low_priority"},
	[94] = {94, "write", 1, "MAIN_1_R5_2", "notify_resp"},
	[95] = {95, "read", 1, "MAIN_1_R5_3", "notify"},
	[96] = {96, "read", 2, "MAIN_1_R5_3", "response"},
	[97] = {97, "write", 1, "MAIN_1_R5_3", "high_priority"},
	[98] = {98, "write", 1, "MAIN_1_R5_3", "low_priority"},
	[99] = {99, "write", 1, "MAIN_1_R5_3", "notify_resp"},
	[100] = {100, "read", 2, "ICSSG_0", "notify"},
	[101] = {101, "read", 7, "ICSSG_0", "response"},
	[102] = {102, "write", 2, "ICSSG_0", "high_priority"},
	[103] = {103, "write", 5, "ICSSG_0", "low_priority"},
	[104] = {104, "write", 2, "ICSSG_0", "notify_resp"},
};

struct ti_sci_sec_proxy_info j721e_mcu_sp_info[] = {
	[0] = {0, "read", 2, "MCU_0_R5_0", "notify"},
	[1] = {1, "read", 7, "MCU_0_R5_0", "response"},
	[2] = {2, "write", 2, "MCU_0_R5_0", "high_priority"},
	[3] = {3, "write", 5, "MCU_0_R5_0", "low_priority"},
	[4] = {4, "write", 2, "MCU_0_R5_0", "notify_resp"},
	[5] = {5, "read", 2, "MCU_0_R5_1", "notify"},
	[6] = {6, "read", 7, "MCU_0_R5_1", "response"},
	[7] = {7, "write", 2, "MCU_0_R5_1", "high_priority"},
	[8] = {8, "write", 5, "MCU_0_R5_1", "low_priority"},
	[9] = {9, "write", 2, "MCU_0_R5_1", "notify_resp"},
	[10] = {10, "read", 1, "MCU_0_R5_2", "notify"},
	[11] = {11, "read", 2, "MCU_0_R5_2", "response"},
	[12] = {12, "write", 1, "MCU_0_R5_2", "high_priority"},
	[13] = {13, "write", 1, "MCU_0_R5_2", "low_priority"},
	[14] = {14, "write", 1, "MCU_0_R5_2", "notify_resp"},
	[15] = {15, "read", 1, "MCU_0_R5_3", "notify"},
	[16] = {16, "read", 2, "MCU_0_R5_3", "response"},
	[17] = {17, "write", 1, "MCU_0_R5_3", "high_priority"},
	[18] = {18, "write", 1, "MCU_0_R5_3", "low_priority"},
	[19] = {19, "write", 1, "MCU_0_R5_3", "notify_resp"},
};
