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
	[25] = {25, "read", 2, "MAIN_0_R5_0", "notify"},
	[26] = {26, "read", 7, "MAIN_0_R5_0", "response"},
	[27] = {27, "write", 2, "MAIN_0_R5_0", "high_priority"},
	[28] = {28, "write", 5, "MAIN_0_R5_0", "low_priority"},
	[29] = {29, "write", 2, "MAIN_0_R5_0", "notify_resp"},
	[30] = {30, "read", 2, "MAIN_0_R5_1", "notify"},
	[31] = {31, "read", 7, "MAIN_0_R5_1", "response"},
	[32] = {32, "write", 2, "MAIN_0_R5_1", "high_priority"},
	[33] = {33, "write", 5, "MAIN_0_R5_1", "low_priority"},
	[34] = {34, "write", 2, "MAIN_0_R5_1", "notify_resp"},
	[35] = {35, "read", 1, "MAIN_0_R5_2", "notify"},
	[36] = {36, "read", 2, "MAIN_0_R5_2", "response"},
	[37] = {37, "write", 1, "MAIN_0_R5_2", "high_priority"},
	[38] = {38, "write", 1, "MAIN_0_R5_2", "low_priority"},
	[39] = {39, "write", 1, "MAIN_0_R5_2", "notify_resp"},
	[40] = {40, "read", 1, "MAIN_0_R5_3", "notify"},
	[41] = {41, "read", 2, "MAIN_0_R5_3", "response"},
	[42] = {42, "write", 1, "MAIN_0_R5_3", "high_priority"},
	[43] = {43, "write", 1, "MAIN_0_R5_3", "low_priority"},
	[44] = {44, "write", 1, "MAIN_0_R5_3", "notify_resp"},
};

struct ti_sci_sec_proxy_info j7200_mcu_sp_info[] = {
	[0] = {0, "read", 2, "MCU_0_R5_0", "notify"},
	[1] = {1, "read", 20, "MCU_0_R5_0", "response"},
	[2] = {2, "write", 10, "MCU_0_R5_0", "high_priority"},
	[3] = {3, "write", 10, "MCU_0_R5_0", "low_priority"},
	[4] = {4, "write", 2, "MCU_0_R5_0", "notify_resp"},
	[5] = {5, "read", 2, "MCU_0_R5_1", "notify"},
	[6] = {6, "read", 20, "MCU_0_R5_1", "response"},
	[7] = {7, "write", 10, "MCU_0_R5_1", "high_priority"},
	[8] = {8, "write", 10, "MCU_0_R5_1", "low_priority"},
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
