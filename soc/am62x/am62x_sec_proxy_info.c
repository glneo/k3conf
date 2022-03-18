/*
 * AM62X Sec Proxy Info
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

struct ti_sci_sec_proxy_info am62x_main_sp_info[] = {
	[0] = {70, "read", 35, "DM", "nonsec_low_priority_rx"},
	[1] = {69, "write", 11, "DM", "nonsec_MAIN_0_R5_1_response_tx"},
	[2] = {68, "write", 2, "DM", "nonsec_MAIN_0_R5_3_response_tx"},
	[3] = {67, "write", 6, "DM", "nonsec_A53_1_response_tx"},
	[4] = {66, "write", 6, "DM", "nonsec_A53_2_response_tx"},
	[5] = {65, "write", 6, "DM", "nonsec_A53_3_response_tx"},
	[6] = {64, "write", 6, "DM", "nonsec_M4_0_response_tx"},
	[7] = {63, "write", 2, "DM", "nonsec_GPU_response_tx"},
	[8] = {62, "write", 2, "DM", "nonsec_ICSSG_0_response_tx"},
	[9] = {61, "write", 4, "DM", "nonsec_TIFS2DM_response_tx"},
	[10] = {0, "read", 11, "MAIN_0_R5_0", "response"},
	[11] = {1, "write", 10, "MAIN_0_R5_0", "low_priority"},
	[12] = {2, "read", 11, "MAIN_0_R5_1", "response"},
	[13] = {3, "write", 10, "MAIN_0_R5_1", "low_priority"},
	[14] = {4, "read", 2, "MAIN_0_R5_2", "response"},
	[15] = {5, "write", 1, "MAIN_0_R5_2", "low_priority"},
	[16] = {6, "read", 2, "MAIN_0_R5_3", "response"},
	[17] = {7, "write", 1, "MAIN_0_R5_3", "low_priority"},
	[18] = {8, "read", 11, "A53_0", "response"},
	[19] = {9, "write", 10, "A53_0", "low_priority"},
	[20] = {10, "read", 6, "A53_1", "response"},
	[21] = {11, "write", 5, "A53_1", "low_priority"},
	[22] = {12, "read", 6, "A53_2", "response"},
	[23] = {13, "write", 5, "A53_2", "low_priority"},
	[24] = {14, "read", 6, "A53_3", "response"},
	[25] = {15, "write", 5, "A53_3", "low_priority"},
	[26] = {16, "read", 6, "M4_0", "response"},
	[27] = {17, "write", 5, "M4_0", "low_priority"},
	[28] = {18, "read", 2, "GPU", "response"},
	[29] = {19, "write", 1, "GPU", "low_priority"},
	[30] = {20, "read", 2, "ICSSG_0", "response"},
	[31] = {21, "write", 1, "ICSSG_0", "low_priority"},
	[32] = {22, "read", 4, "DM2TIFS", "response"},
	[33] = {23, "write", 2, "DM2TIFS", "low_priority"},
	[34] = {24, "read", 4, "TIFS2DM", "response"},
	[35] = {25, "write", 2, "TIFS2DM", "low_priority"},
};
