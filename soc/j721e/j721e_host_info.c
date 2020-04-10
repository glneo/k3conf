/*
 * J721E Hosts Info
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

struct ti_sci_host_info j721e_host_info[] = {
	[0] = {0, "DMSC", "Secure", "Device Management and Security Control"},
	[1] = {3, "MCU_0_R5_0", "Non Secure", "Cortex R5 context 0 on MCU island"},
	[2] = {4, "MCU_0_R5_1", "Secure", "Cortex R5 context 1 on MCU island(Boot)"},
	[3] = {5, "MCU_0_R5_2", "Non Secure", "Cortex R5 context 2 on MCU island"},
	[4] = {6, "MCU_0_R5_3", "Secure", "Cortex R5 context 3 on MCU island"},
	[5] = {10, "A72_0", "Secure", "Cortex A72 context 0 on Main island"},
	[6] = {11, "A72_1", "Secure", "Cortex A72 context 1 on Main island"},
	[7] = {12, "A72_2", "Non Secure", "Cortex A72 context 2 on Main island"},
	[8] = {13, "A72_3", "Non Secure", "Cortex A72 context 3 on Main island"},
	[9] = {14, "A72_4", "Non Secure", "Cortex A72 context 4 on Main island"},
	[10] = {20, "C7X_0", "Secure", "C7x Context 0 on Main island"},
	[11] = {21, "C7X_1", "Non Secure", "C7x context 1 on Main island"},
	[12] = {25, "C6X_0_0", "Secure", "C6x_0 Context 0 on Main island"},
	[13] = {26, "C6X_0_1", "Non Secure", "C6x_0 context 1 on Main island"},
	[14] = {27, "C6X_1_0", "Secure", "C6x_1 Context 0 on Main island"},
	[15] = {28, "C6X_1_1", "Non Secure", "C6x_1 context 1 on Main island"},
	[16] = {30, "GPU_0", "Non Secure", "RGX context 0 on Main island"},
	[17] = {35, "MAIN_0_R5_0", "Non Secure", "Cortex R5_0 context 0 on Main island"},
	[18] = {36, "MAIN_0_R5_1", "Secure", "Cortex R5_0 context 1 on Main island"},
	[19] = {37, "MAIN_0_R5_2", "Non Secure", "Cortex R5_0 context 2 on Main island"},
	[20] = {38, "MAIN_0_R5_3", "Secure", "Cortex R5_0 context 3 on MCU island"},
	[21] = {40, "MAIN_1_R5_0", "Non Secure", "Cortex R5_1 context 0 on Main island"},
	[22] = {41, "MAIN_1_R5_1", "Secure", "Cortex R5_1 context 1 on Main island"},
	[23] = {42, "MAIN_1_R5_2", "Non Secure", "Cortex R5_1 context 2 on Main island"},
	[24] = {43, "MAIN_1_R5_3", "Secure", "Cortex R5_1 context 3 on MCU island"},
	[25] = {50, "ICSSG_0", "Non Secure", "ICSSG context 0 on Main island"},
};
