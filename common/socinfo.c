/*
 * K3 SoC detection and helper apis
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - https://www.ti.com/
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
#include <soc/am65x/am65x_sec_proxy_info.h>
#include <soc/am65x/am65x_processors_info.h>
#include <soc/am65x/am65x_devices_info.h>
#include <soc/am65x/am65x_clocks_info.h>
#include <soc/am65x/am65x_rm_info.h>
#include <soc/am65x_sr2/am65x_sr2_host_info.h>
#include <soc/am65x_sr2/am65x_sr2_sec_proxy_info.h>
#include <soc/am65x_sr2/am65x_sr2_processors_info.h>
#include <soc/am65x_sr2/am65x_sr2_devices_info.h>
#include <soc/am65x_sr2/am65x_sr2_clocks_info.h>
#include <soc/am65x_sr2/am65x_sr2_rm_info.h>
#include <soc/j721e/j721e_host_info.h>
#include <soc/j721e/j721e_sec_proxy_info.h>
#include <soc/j721e/j721e_processors_info.h>
#include <soc/j721e/j721e_devices_info.h>
#include <soc/j721e/j721e_clocks_info.h>
#include <soc/j721e/j721e_rm_info.h>
#include <soc/j7200/j7200_host_info.h>
#include <soc/j7200/j7200_sec_proxy_info.h>
#include <soc/j7200/j7200_processors_info.h>
#include <soc/j7200/j7200_devices_info.h>
#include <soc/j7200/j7200_clocks_info.h>
#include <soc/j7200/j7200_rm_info.h>
#include <soc/am64x/am64x_host_info.h>
#include <soc/am64x/am64x_sec_proxy_info.h>
#include <soc/am64x/am64x_processors_info.h>
#include <soc/am64x/am64x_devices_info.h>
#include <soc/am64x/am64x_clocks_info.h>
#include <soc/am64x/am64x_rm_info.h>
#include <soc/am62x/am62x_devices_info.h>
#include <soc/am62x/am62x_clocks_info.h>
#include <soc/am62x/am62x_host_info.h>
#include <soc/am62x/am62x_processors_info.h>
#include <soc/am62x/am62x_rm_info.h>
#include <soc/am62x/am62x_sec_proxy_info.h>
#include <soc/j721s2/j721s2_devices_info.h>
#include <soc/j721s2/j721s2_clocks_info.h>
#include <soc/j721s2/j721s2_host_info.h>
#include <soc/j721s2/j721s2_processors_info.h>
#include <soc/j721s2/j721s2_rm_info.h>

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
#define JTAG_ID_PARTNO_MASK	(0xffff << 12)

#define CTRLMMR_WKUP_DIE_ID0	0x43000020
#define CTRLMMR_WKUP_DIE_ID1	0x43000024
#define CTRLMMR_WKUP_DIE_ID2	0x43000028
#define CTRLMMR_WKUP_DIE_ID3	0x4300002c
#define CTRLMMR_WKUP_DEVSTAT	0x43000030
#define CTRLMMR_WKUP_BOOTCFG	0x43000034

struct k3conf_soc_info soc_info;

static const char soc_revision[REV_PG_MAX + 1][SOC_REVISION_MAX_LENGTH] = {
	[REV_SR1_0] = "1.0",
	[REV_SR2_0] = "2.0",
	[REV_PG_MAX] = "NULL"
};

static void am654_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->host_info = am65x_host_info;
	sci_info->num_hosts = AM65X_MAX_HOST_IDS;
	sci_info->sp_info[MAIN_SEC_PROXY] = am65x_main_sp_info;
	sci_info->num_sp_threads[MAIN_SEC_PROXY] = AM65X_MAIN_SEC_PROXY_THREADS;
	sci_info->sp_info[MCU_SEC_PROXY] = am65x_mcu_sp_info;
	sci_info->num_sp_threads[MCU_SEC_PROXY] = AM65X_MCU_SEC_PROXY_THREADS;
	sci_info->processors_info = am65x_processors_info;
	sci_info->num_processors = AM65X_MAX_PROCESSORS_IDS;
	sci_info->devices_info = am65x_devices_info;
	sci_info->num_devices = AM65X_MAX_DEVICES;
	sci_info->clocks_info = am65x_clocks_info;
	sci_info->num_clocks = AM65X_MAX_CLOCKS;
	sci_info->rm_info = am65x_rm_info;
	sci_info->num_res = AM65X_MAX_RES;
	soc_info.host_id = DEFAULT_HOST_ID;
	soc_info.sec_proxy = &k3_generic_sec_proxy_base;
}

static void am654_sr2_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->host_info = am65x_sr2_host_info;
	sci_info->num_hosts = AM65X_SR2_MAX_HOST_IDS;
	sci_info->sp_info[MAIN_SEC_PROXY] = am65x_sr2_main_sp_info;
	sci_info->num_sp_threads[MAIN_SEC_PROXY] = AM65X_SR2_MAIN_SEC_PROXY_THREADS;
	sci_info->sp_info[MCU_SEC_PROXY] = am65x_sr2_mcu_sp_info;
	sci_info->num_sp_threads[MCU_SEC_PROXY] = AM65X_SR2_MCU_SEC_PROXY_THREADS;
	sci_info->processors_info = am65x_sr2_processors_info;
	sci_info->num_processors = AM65X_SR2_MAX_PROCESSORS_IDS;
	sci_info->devices_info = am65x_sr2_devices_info;
	sci_info->num_devices = AM65X_SR2_MAX_DEVICES;
	sci_info->clocks_info = am65x_sr2_clocks_info;
	sci_info->num_clocks = AM65X_SR2_MAX_CLOCKS;
	sci_info->rm_info = am65x_sr2_rm_info;
	sci_info->num_res = AM65X_SR2_MAX_RES;
	soc_info.host_id = DEFAULT_HOST_ID;
	soc_info.sec_proxy = &k3_generic_sec_proxy_base;
}

static void j721s2_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->rm_info = j721s2_rm_info;
	sci_info->num_res = J721S2_MAX_RES;
	sci_info->host_info = j721s2_host_info;
	sci_info->num_hosts = J721S2_MAX_HOST_IDS;
	sci_info->clocks_info = j721s2_clocks_info;
	sci_info->num_clocks = J721S2_MAX_CLOCKS;
	sci_info->devices_info = j721s2_devices_info;
	sci_info->num_devices = J721S2_MAX_DEVICES;
	soc_info.host_id = DEFAULT_HOST_ID;
	soc_info.sec_proxy = &k3_generic_sec_proxy_base;
}

static void j721e_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->host_info = j721e_host_info;
	sci_info->num_hosts = J721E_MAX_HOST_IDS;
	sci_info->sp_info[MAIN_SEC_PROXY] = j721e_main_sp_info;
	sci_info->num_sp_threads[MAIN_SEC_PROXY] = J721E_MAIN_SEC_PROXY_THREADS;
	sci_info->sp_info[MCU_SEC_PROXY] = j721e_mcu_sp_info;
	sci_info->num_sp_threads[MCU_SEC_PROXY] = J721E_MCU_SEC_PROXY_THREADS;
	sci_info->processors_info = j721e_processors_info;
	sci_info->num_processors = J721E_MAX_PROCESSORS_IDS;
	sci_info->devices_info = j721e_devices_info;
	sci_info->num_devices = J721E_MAX_DEVICES;
	sci_info->clocks_info = j721e_clocks_info;
	sci_info->num_clocks = J721E_MAX_CLOCKS;
	sci_info->rm_info = j721e_rm_info;
	sci_info->num_res = J721E_MAX_RES;
	soc_info.host_id = DEFAULT_HOST_ID;
	soc_info.sec_proxy = &k3_generic_sec_proxy_base;
}

static void j7200_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->host_info = j7200_host_info;
	sci_info->num_hosts = J7200_MAX_HOST_IDS;
	sci_info->sp_info[MAIN_SEC_PROXY] = j7200_main_sp_info;
	sci_info->num_sp_threads[MAIN_SEC_PROXY] = J7200_MAIN_SEC_PROXY_THREADS;
	sci_info->sp_info[MCU_SEC_PROXY] = j7200_mcu_sp_info;
	sci_info->num_sp_threads[MCU_SEC_PROXY] = J7200_MCU_SEC_PROXY_THREADS;
	sci_info->processors_info = j7200_processors_info;
	sci_info->num_processors = J7200_MAX_PROCESSORS_IDS;
	sci_info->devices_info = j7200_devices_info;
	sci_info->num_devices = J7200_MAX_DEVICES;
	sci_info->clocks_info = j7200_clocks_info;
	sci_info->num_clocks = J7200_MAX_CLOCKS;
	sci_info->rm_info = j7200_rm_info;
	sci_info->num_res = J7200_MAX_RES;
	soc_info.host_id = DEFAULT_HOST_ID;
	soc_info.sec_proxy = &k3_generic_sec_proxy_base;
}

static void am64x_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->host_info = am64x_host_info;
	sci_info->num_hosts = AM64X_MAX_HOST_IDS;
	sci_info->sp_info[MAIN_SEC_PROXY] = am64x_main_sp_info;
	sci_info->num_sp_threads[MAIN_SEC_PROXY] = AM64X_MAIN_SEC_PROXY_THREADS;
	sci_info->sp_info[MCU_SEC_PROXY] = NULL;
	sci_info->num_sp_threads[MCU_SEC_PROXY] = 0;
	sci_info->processors_info = am64x_processors_info;
	sci_info->num_processors = AM64X_MAX_PROCESSORS_IDS;
	sci_info->devices_info = am64x_devices_info;
	sci_info->num_devices = AM64X_MAX_DEVICES;
	sci_info->clocks_info = am64x_clocks_info;
	sci_info->num_clocks = AM64X_MAX_CLOCKS;
	sci_info->rm_info = am64x_rm_info;
	sci_info->num_res = AM64X_MAX_RES;
	soc_info.host_id = 13;
	soc_info.sec_proxy = &k3_lite_sec_proxy_base;
}

static void am62x_init(void)
{
	struct ti_sci_info *sci_info = &soc_info.sci_info;

	sci_info->sp_info[MAIN_SEC_PROXY] = am62x_main_sp_info;
	sci_info->num_sp_threads[MAIN_SEC_PROXY] = AM62X_MAIN_SEC_PROXY_THREADS;
	sci_info->sp_info[MCU_SEC_PROXY] = NULL;
	sci_info->num_sp_threads[MCU_SEC_PROXY] = 0;
	sci_info->rm_info = am62x_rm_info;
	sci_info->num_res = AM62X_MAX_RES;
	sci_info->processors_info = am62x_processors_info;
	sci_info->num_processors = AM62X_MAX_PROCESSORS_IDS;
	sci_info->host_info = am62x_host_info;
	sci_info->num_hosts = AM62X_MAX_HOST_IDS;
	sci_info->devices_info = am62x_devices_info;
	sci_info->num_devices = AM62X_MAX_DEVICES;
	sci_info->clocks_info = am62x_clocks_info;
	sci_info->num_clocks = AM62X_MAX_CLOCKS;
	soc_info.host_id = 13;
	soc_info.sec_proxy = &k3_lite_sec_proxy_base;
}

int soc_init(uint32_t host_id)
{
	char *name;

	memset(&soc_info, 0, sizeof(soc_info));

	soc_info.soc = (mmio_read_32(CTRLMMR_WKUP_JTAG_ID) &
			JTAG_ID_PARTNO_MASK) >> JTAG_ID_PARTNO_SHIFT;
	soc_info.rev = (mmio_read_32(CTRLMMR_WKUP_JTAG_ID) &
			JTAG_ID_VARIANT_MASK) >> JTAG_ID_VARIANT_SHIFT;

	switch (soc_info.soc) {
	case AM65X:
		name = "AM65x";
		break;
	case J721S2:
		name = "J721S2";
		break;
	case J721E:
		name = "J721E";
		break;
	case J7200:
		name = "J7200";
		break;
	case AM64X:
		name = "AM64x";
		break;
	case AM62X:
		name = "AM62X";
		break;
	default:
		fprintf(stderr, "Unknown Silicon %d\n", soc_info.soc);
		return -1;
	};

	if (soc_info.rev > REV_PG_MAX) {
		fprintf(stderr, "Unknown Silicon revision %d for SoC %s\n",
			soc_info.rev, name);
		return -1;
	}

	strncpy(soc_info.soc_full_name, "", sizeof(soc_info.soc_full_name));
	strcat(soc_info.soc_full_name, name);
	strcat(soc_info.soc_full_name, " SR");
	strcat(soc_info.soc_full_name, soc_revision[soc_info.rev]);

	if (soc_info.soc == AM65X && soc_info.rev == REV_SR1_0)
		am654_init();
	else if (soc_info.soc == AM65X && soc_info.rev == REV_SR2_0)
		am654_sr2_init();
	else if (soc_info.soc == J721S2)
		j721s2_init();
	else if (soc_info.soc == J721E)
		j721e_init();
	else if (soc_info.soc == J7200)
		j7200_init();
	else if (soc_info.soc == AM64X)
		am64x_init();
	else if (soc_info.soc == AM62X)
		am62x_init();

	if (host_id != INVALID_HOST_ID)
		soc_info.host_id = host_id;

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
	return soc_info.soc == AM65X;
}
