/*
 * AM65X Sec Proxy Info
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

struct ti_sci_sec_proxy_info am65x_main_sp_info[] = {
	{0, "read", 2, "A53_0", "notify"},
	{1, "read", 30, "A53_0", "response"},
	{2, "write", 10, "A53_0", "high_priority"},
	{3, "write", 20, "A53_0", "low_priority"},
	{4, "write", 2, "A53_0", "notify_resp"},
	{5, "read", 2, "A53_1", "notify"},
	{6, "read", 30, "A53_1", "response"},
	{7, "write", 10, "A53_1", "high_priority"},
	{8, "write", 20, "A53_1", "low_priority"},
	{9, "write", 2, "A53_1", "notify_resp"},
	{10, "read", 2, "A53_2", "notify"},
	{11, "read", 22, "A53_2", "response"},
	{12, "write", 2, "A53_2", "high_priority"},
	{13, "write", 20, "A53_2", "low_priority"},
	{14, "write", 2, "A53_2", "notify_resp"},
	{15, "read", 2, "A53_3", "notify"},
	{16, "read", 7, "A53_3", "response"},
	{17, "write", 2, "A53_3", "high_priority"},
	{18, "write", 5, "A53_3", "low_priority"},
	{19, "write", 2, "A53_3", "notify_resp"},
	{20, "read", 2, "A53_4", "notify"},
	{21, "read", 5, "A53_4", "response"},
	{22, "write", 2, "A53_4", "high_priority"},
	{23, "write", 5, "A53_4", "low_priority"},
	{24, "write", 2, "A53_4", "notify_resp"},
	{25, "read", 2, "A53_5", "notify"},
	{26, "read", 5, "A53_5", "response"},
	{27, "write", 2, "A53_5", "high_priority"},
	{28, "write", 5, "A53_5", "low_priority"},
	{29, "write", 2, "A53_5", "notify_resp"},
	{30, "read", 2, "A53_6", "notify"},
	{31, "read", 5, "A53_6", "response"},
	{32, "write", 2, "A53_6", "high_priority"},
	{33, "write", 5, "A53_6", "low_priority"},
	{34, "write", 2, "A53_6", "notify_resp"},
	{35, "read", 2, "A53_7", "notify"},
	{36, "read", 5, "A53_7", "response"},
	{37, "write", 2, "A53_7", "high_priority"},
	{38, "write", 5, "A53_7", "low_priority"},
	{39, "write", 2, "A53_7", "notify_resp"},
	{40, "read", 2, "ICSSG_0", "notify"},
	{41, "read", 7, "ICSSG_0", "response"},
	{42, "write", 2, "ICSSG_0", "high_priority"},
	{43, "write", 5, "ICSSG_0", "low_priority"},
	{44, "write", 2, "ICSSG_0", "notify_resp"},
	{45, "read", 2, "ICSSG_1", "notify"},
	{46, "read", 4, "ICSSG_1", "response"},
	{47, "write", 2, "ICSSG_1", "high_priority"},
	{48, "write", 2, "ICSSG_1", "low_priority"},
	{49, "write", 2, "ICSSG_1", "notify_resp"},
	{50, "read", 2, "ICSSG_2", "notify"},
	{51, "read", 4, "ICSSG_2", "response"},
	{52, "write", 2, "ICSSG_2", "high_priority"},
	{53, "write", 2, "ICSSG_2", "low_priority"},
	{54, "write", 2, "ICSSG_2", "notify_resp"},
	{55, "read", 2, "GPU_0", "notify"},
	{56, "read", 7, "GPU_0", "response"},
	{57, "write", 2, "GPU_0", "high_priority"},
	{58, "write", 5, "GPU_0", "low_priority"},
	{59, "write", 2, "GPU_0", "notify_resp"},
	{60, "read", 2, "GPU_1", "notify"},
	{61, "read", 5, "GPU_1", "response"},
	{62, "write", 2, "GPU_1", "high_priority"},
	{63, "write", 3, "GPU_1", "low_priority"},
	{64, "write", 2, "GPU_1", "notify_resp"},
};

struct ti_sci_sec_proxy_info am65x_mcu_sp_info[] = {
	{0, "read", 2, "R5_0", "notify"},
	{1, "read", 20, "R5_0", "response"},
	{2, "write", 10, "R5_0", "high_priority"},
	{3, "write", 10, "R5_0", "low_priority"},
	{4, "write", 2, "R5_0", "notify_resp"},
	{5, "read", 2, "R5_1", "notify"},
	{6, "read", 20, "R5_1", "response"},
	{7, "write", 10, "R5_1", "high_priority"},
	{8, "write", 10, "R5_1", "low_priority"},
	{9, "write", 2, "R5_1", "notify_resp"},
	{10, "read", 1, "R5_2", "notify"},
	{11, "read", 2, "R5_2", "response"},
	{12, "write", 1, "R5_2", "high_priority"},
	{13, "write", 1, "R5_2", "low_priority"},
	{14, "write", 1, "R5_2", "notify_resp"},
	{15, "read", 1, "R5_3", "notify"},
	{16, "read", 2, "R5_3", "response"},
	{17, "write", 1, "R5_3", "high_priority"},
	{18, "write", 1, "R5_3", "low_priority"},
	{19, "write", 1, "R5_3", "notify_resp"},
};
