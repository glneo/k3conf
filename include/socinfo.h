/*
 * SoC info header file
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
 *	Lokesh Vutla <lokeshvutla@ti.com>
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

#ifndef __SOCINFO_H
#define __SOCINFO_H

#include <stdint.h>
#include <tisci.h>

#define SOC_NAME_MAX_LENGTH			10
#define SOC_REVISION_MAX_LENGTH			5
#define SOC_FULL_NAME_MAX_LENGTH		20

typedef enum {
	AM654 = 2,
	J721E = 4,
	K3_MAX
} k3_soc;

typedef enum {
	REV_PG1_0,
	REV_PG2_0,
	REV_PG_MAX
} k3_soc_rev;

struct k3conf_soc_info {
	k3_soc soc;
	k3_soc_rev rev;
	char soc_full_name[SOC_FULL_NAME_MAX_LENGTH];
	uint8_t host_id;
	uint8_t ti_sci_enabled;
	struct ti_sci_info sci_info;
};

extern struct k3conf_soc_info soc_info;
int soc_init(void);
int soc_is_j721e(void);
int soc_is_am654(void);

#endif
