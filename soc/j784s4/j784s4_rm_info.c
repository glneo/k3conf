/*
 * J784S4 RM Info
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

struct ti_sci_rm_info j784s4_rm_info[] = {
	{0x0280, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x02C0, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x2B40, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x2B80, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x2C00, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x2C40, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x4642, "RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER"},
	{0x4643, "RESASG_SUBTYPE_UDMAP_GLOBAL_CONFIG"},
	{0x464E, "RESASG_SUBTYPE_BCDMA_RING_SPLIT_TR_RX_CHAN"},
	{0x464F, "RESASG_SUBTYPE_BCDMA_RING_SPLIT_TR_TX_CHAN"},
	{0x4661, "RESASG_SUBTYPE_BCDMA_SPLIT_TR_RX_CHAN"},
	{0x4662, "RESASG_SUBTYPE_BCDMA_SPLIT_TR_TX_CHAN"},
	{0x46C0, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x4D8A, "RESASG_SUBTYPE_IA_VINT"},
	{0x4D8D, "RESASG_SUBTYPE_GLOBAL_EVENT_SEVT"},
	{0x4DCA, "RESASG_SUBTYPE_IA_VINT"},
	{0x4DCD, "RESASG_SUBTYPE_GLOBAL_EVENT_SEVT"},
	{0x4E00, "RESASG_SUBTYPE_PROXY_PROXIES"},
	{0x4EC0, "RESASG_SUBTYPE_RA_ERROR_OES"},
	{0x4EC1, "RESASG_SUBTYPE_RA_GP"},
	{0x4EC2, "RESASG_SUBTYPE_RA_UDMAP_RX"},
	{0x4EC3, "RESASG_SUBTYPE_RA_UDMAP_TX"},
	{0x4EC4, "RESASG_SUBTYPE_RA_UDMAP_TX_EXT"},
	{0x4EC5, "RESASG_SUBTYPE_RA_UDMAP_RX_H"},
	{0x4EC6, "RESASG_SUBTYPE_RA_UDMAP_RX_UH"},
	{0x4EC7, "RESASG_SUBTYPE_RA_UDMAP_TX_H"},
	{0x4EC8, "RESASG_SUBTYPE_RA_UDMAP_TX_UH"},
	{0x4ECA, "RESASG_SUBTYPE_RA_VIRTID"},
	{0x4ECB, "RESASG_SUBTYPE_RA_MONITORS"},
	{0x4FC0, "RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON"},
	{0x4FC1, "RESASG_SUBTYPE_UDMAP_INVALID_FLOW_OES"},
	{0x4FC2, "RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER"},
	{0x4FC3, "RESASG_SUBTYPE_UDMAP_GLOBAL_CONFIG"},
	{0x4FCA, "RESASG_SUBTYPE_UDMAP_RX_CHAN"},
	{0x4FCB, "RESASG_SUBTYPE_UDMAP_RX_HCHAN"},
	{0x4FCC, "RESASG_SUBTYPE_UDMAP_RX_UHCHAN"},
	{0x4FCD, "RESASG_SUBTYPE_UDMAP_TX_CHAN"},
	{0x4FCE, "RESASG_SUBTYPE_UDMAP_TX_ECHAN"},
	{0x4FCF, "RESASG_SUBTYPE_UDMAP_TX_HCHAN"},
	{0x4FD0, "RESASG_SUBTYPE_UDMAP_TX_UHCHAN"},
	{0x504A, "RESASG_SUBTYPE_IA_VINT"},
	{0x504D, "RESASG_SUBTYPE_GLOBAL_EVENT_SEVT"},
	{0x504F, "RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_ERROR_OES"},
	{0x5050, "RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_DATA_COMPLETION_OES"},
	{0x5051, "RESASG_SUBTYPE_IA_BCDMA_TX_CHAN_RING_COMPLETION_OES"},
	{0x5052, "RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_ERROR_OES"},
	{0x5053, "RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_DATA_COMPLETION_OES"},
	{0x5054, "RESASG_SUBTYPE_IA_BCDMA_RX_CHAN_RING_COMPLETION_OES"},
	{0x5100, "RESASG_SUBTYPE_IR_OUTPUT"},
	{0x51C0, "RESASG_SUBTYPE_PROXY_PROXIES"},
	{0x5200, "RESASG_SUBTYPE_RA_ERROR_OES"},
	{0x5201, "RESASG_SUBTYPE_RA_GP"},
	{0x5202, "RESASG_SUBTYPE_RA_UDMAP_RX"},
	{0x5203, "RESASG_SUBTYPE_RA_UDMAP_TX"},
	{0x5205, "RESASG_SUBTYPE_RA_UDMAP_RX_H"},
	{0x5207, "RESASG_SUBTYPE_RA_UDMAP_TX_H"},
	{0x520A, "RESASG_SUBTYPE_RA_VIRTID"},
	{0x520B, "RESASG_SUBTYPE_RA_MONITORS"},
	{0x5240, "RESASG_SUBTYPE_UDMAP_RX_FLOW_COMMON"},
	{0x5241, "RESASG_SUBTYPE_UDMAP_INVALID_FLOW_OES"},
	{0x5242, "RESASG_SUBTYPE_GLOBAL_EVENT_TRIGGER"},
	{0x5243, "RESASG_SUBTYPE_UDMAP_GLOBAL_CONFIG"},
	{0x524A, "RESASG_SUBTYPE_UDMAP_RX_CHAN"},
	{0x524B, "RESASG_SUBTYPE_UDMAP_RX_HCHAN"},
	{0x524D, "RESASG_SUBTYPE_UDMAP_TX_CHAN"},
	{0x524F, "RESASG_SUBTYPE_UDMAP_TX_HCHAN"},
	{0x52CA, "RESASG_SUBTYPE_IA_VINT"},
	{0x52CD, "RESASG_SUBTYPE_GLOBAL_EVENT_SEVT"},
};
