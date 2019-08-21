/*
 * K3 SoC detection and helper apis
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

#include <socinfo.h>
#include <mmio.h>
#include <string.h>
#include <sec_proxy.h>
#include <soc/am65x/am65x_host_info.h>

/* Assuming these addresses and definitions stay common across K3 devices */
#define CTRLMMR_WKUP_JTAG_DEVICE_ID	0x43000018
#define DEVICE_ID_FAMILY_SHIFT	26
#define DEVICE_ID_FAMILY_MASK	(0x3f << 26)
#define DEVICE_ID_BASE_SHIFT	11
#define DEVICE_ID_BASE_MASK	(0x1fff << 11)
#define DEVICE_ID_SPEED_SHIFT	6
#define DEVICE_ID_SPEED_MASK	(0x1f << 6)
#define DEVICE_ID_TEMP_SHIFT	3
#define DEVICE_ID_TEMP_MASK	(0x7 << 3)

#define CTRLMMR_WKUP_JTAG_ID		0x43000014
#define JTAG_ID_VARIANT_SHIFT	28
#define JTAG_ID_VARIANT_MASK	(0xf << 28)
#define JTAG_ID_PARTNO_SHIFT	12
#define JTAG_ID_PARTNO_MASK	(0x7ff << 1)

#define CTRLMMR_WKUP_DIE_ID0	0x43000020
#define CTRLMMR_WKUP_DIE_ID1	0x43000024
#define CTRLMMR_WKUP_DIE_ID2	0x43000028
#define CTRLMMR_WKUP_DIE_ID3	0x4300002c
#define CTRLMMR_WKUP_DEVSTAT	0x43000030
#define CTRLMMR_WKUP_BOOTCFG	0x43000034

struct k3conf_soc_info soc_info;

static const char soc_name[K3_MAX + 1][SOC_NAME_MAX_LENGTH] = {
	[AM654] = "AM654",
	[J721E] = "J721E",
	[K3_MAX] = "UNKNOWN"
};

static const char soc_revision[REV_PG_MAX + 1][SOC_REVISION_MAX_LENGTH] = {
	[REV_PG1_0] = "1.0",
	[REV_PG2_0] = "2.0",
	[REV_PG_MAX] = "NULL"
};

static void am654_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->host_info = am65x_host_info;
	sci_info->num_hosts = AM65X_MAX_HOST_IDS;
}

int soc_init(void)
{
	memset(&soc_info, 0, sizeof(soc_info));

	soc_info.soc = (mmio_read_32(CTRLMMR_WKUP_JTAG_DEVICE_ID) &
			DEVICE_ID_FAMILY_MASK) >> DEVICE_ID_FAMILY_SHIFT;
	soc_info.rev = (mmio_read_32(CTRLMMR_WKUP_JTAG_ID) &
			JTAG_ID_VARIANT_MASK) >> JTAG_ID_VARIANT_SHIFT;

	if (soc_info.soc > K3_MAX || !soc_name[soc_info.soc]) {
		fprintf(stderr, "Unknown Silicon %d\n", soc_info.soc);
		return -1;
	}
	if (soc_info.rev > REV_PG_MAX) {
		fprintf(stderr, "Unknown Silicon revision %d for SoC %s\n",
			soc_info.rev, soc_name[soc_info.soc]);
		return -1;
	}

	strncpy(soc_info.soc_full_name, "", sizeof(soc_info.soc_full_name));
	strcat(soc_info.soc_full_name, soc_name[soc_info.soc]);
	strcat(soc_info.soc_full_name, " PG");
	strcat(soc_info.soc_full_name, soc_revision[soc_info.rev]);

	soc_info.host_id = DEFAULT_HOST_ID;

	if (soc_info.soc == AM654)
		am654_init();

	/* ToDo: Add error if sec_proxy_init/sci_init is failed */
	if(!k3_sec_proxy_init())
		if (!ti_sci_init())
			soc_info.ti_sci_enabled = 1;

	return 0;
}

int soc_is_j721e(void)
{
	return soc_info.soc == J721E;
}

int soc_is_am654(void)
{
	return soc_info.soc == AM654;
}
