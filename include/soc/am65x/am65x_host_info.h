/*
 * SoC Host Info
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

#ifndef __AM65X_HOST_INFO
#define __AM65X_HOST_INFO

#include <stdio.h>
#include <stdint.h>

#define AM65X_HOST_ID_DMSC   0
#define AM65X_HOST_ID_R5_0   3
#define AM65X_HOST_ID_R5_1   4
#define AM65X_HOST_ID_R5_2   5
#define AM65X_HOST_ID_R5_3   6
#define AM65X_HOST_ID_A53_0   10
#define AM65X_HOST_ID_A53_1   11
#define AM65X_HOST_ID_A53_2   12
#define AM65X_HOST_ID_A53_3   13
#define AM65X_HOST_ID_A53_4   14
#define AM65X_HOST_ID_A53_5   15
#define AM65X_HOST_ID_A53_6   16
#define AM65X_HOST_ID_A53_7   17
#define AM65X_HOST_ID_GPU_0   30
#define AM65X_HOST_ID_GPU_1   31
#define AM65X_HOST_ID_ICSSG_0   50
#define AM65X_HOST_ID_ICSSG_1   51
#define AM65X_HOST_ID_ICSSG_2   52

#define AM65X_MAX_HOST_IDS	18

extern struct ti_sci_host_info am65x_host_info[];
#endif