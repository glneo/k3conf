/*
 * K3CONF Command Dump
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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <tisci.h>
#include <socinfo.h>
#include <help.h>
#include <autoadjust_table.h>
#include <k3conf.h>

int dump_clocks_info(int argc, char *argv[])
{
	struct ti_sci_clocks_info *c = soc_info.sci_info.clocks_info;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	uint32_t row = 0, dev_id;
	int found = 0, ret;
	uint64_t freq;

	autoadjust_table_init(table);
	strncpy(table[row][0], "Device ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Clock ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Clock Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][3], "Status", TABLE_MAX_ELT_LEN);
	strncpy(table[row][4], "Clock Frequency", TABLE_MAX_ELT_LEN);

	if (argc)
		goto print_single_device;

	for (row = 0; row < soc_info.sci_info.num_clocks; row++) {
		snprintf(table[row + 1][0], TABLE_MAX_ELT_LEN, "%5d",
			 c[row].dev_id);
		snprintf(table[row + 1][1], TABLE_MAX_ELT_LEN, "%5d",
			 c[row].clk_id);
		strncpy(table[row + 1][2], c[row].clk_name, TABLE_MAX_ELT_LEN);
		snprintf(table[row + 1][3], TABLE_MAX_ELT_LEN, "%s",
			 ti_sci_cmd_get_clk_state(c[row].dev_id, c[row].clk_id));
		ti_sci_cmd_get_clk_freq(c[row].dev_id, c[row].clk_id, &freq);
		snprintf(table[row + 1][4], TABLE_MAX_ELT_LEN, "%lu", freq);
	}

	return autoadjust_table_print(table, row + 1, 5);

print_single_device:
	ret = sscanf(argv[0], "%u", &dev_id);
	if (ret != 1)
		return -1;

	for (row = 0; row < soc_info.sci_info.num_clocks; row++) {
		if (dev_id == c[row].dev_id) {
			snprintf(table[found + 1][0], TABLE_MAX_ELT_LEN, "%5d",
				 c[row].dev_id);
			snprintf(table[found + 1][1], TABLE_MAX_ELT_LEN, "%5d",
				 c[row].clk_id);
			strncpy(table[found + 1][2], c[row].clk_name,
				TABLE_MAX_ELT_LEN);
			strncpy(table[found + 1][3],
				ti_sci_cmd_get_clk_state(dev_id, c[row].clk_id),
				TABLE_MAX_ELT_LEN);
			ti_sci_cmd_get_clk_freq(c[row].dev_id, c[row].clk_id,
						&freq);
			snprintf(table[found + 1][4], TABLE_MAX_ELT_LEN, "%lu",
				 freq);
			found++;
		}
	}

	if (!found)
		return -1;

	return autoadjust_table_print(table, found + 1, 5);
}

int dump_devices_info(int argc, char *argv[])
{
	struct ti_sci_devices_info *p = soc_info.sci_info.devices_info;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	uint32_t row = 0, dev_id;
	int found = 0, ret;

	autoadjust_table_init(table);
	strncpy(table[row][0], "Device ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Device Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Device Status", TABLE_MAX_ELT_LEN);

	if (argc)
		goto print_single_device;

	for (row = 0; row < soc_info.sci_info.num_devices; row++) {
		snprintf(table[row + 1][0], TABLE_MAX_ELT_LEN, "%5d",
			 p[row].dev_id);
		strncpy(table[row + 1][1], p[row].name, TABLE_MAX_ELT_LEN);
		snprintf(table[row + 1][2], TABLE_MAX_ELT_LEN, "%s",
			 ti_sci_cmd_get_device_status(p[row].dev_id));
	}

	return autoadjust_table_print(table, row + 1, 3);

print_single_device:
	ret = sscanf(argv[0], "%u", &dev_id);
	if (ret != 1)
		return -1;

	for (row = 0; row < soc_info.sci_info.num_devices; row++) {
		if (dev_id == p[row].dev_id) {
			snprintf(table[1][0], TABLE_MAX_ELT_LEN, "%5d",
				 p[row].dev_id);
			strncpy(table[1][1], p[row].name,
				TABLE_MAX_ELT_LEN);
			snprintf(table[1][2], TABLE_MAX_ELT_LEN, "%s",
				 ti_sci_cmd_get_device_status(p[row].dev_id));
			found = 1;
			break;
		}
	}

	if (!found)
		return -1;

	return autoadjust_table_print(table, 2, 3);
}

static int dump_processors_info(int argc, char *argv[])
{
	struct ti_sci_processors_info *p = soc_info.sci_info.processors_info;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	uint32_t row = 0, proc_id;
	int found = 0, ret;
	uint64_t freq;

	autoadjust_table_init(table);
	strncpy(table[row][0], "Device ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Processor ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Processor Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][3], "Processor State", TABLE_MAX_ELT_LEN);
	strncpy(table[row][4], "Processor Frequency", TABLE_MAX_ELT_LEN);

	if (argc)
		goto print_single_processor;

	for (row = 0; row < soc_info.sci_info.num_processors; row++) {
		snprintf(table[row + 1][0], TABLE_MAX_ELT_LEN, "%5d",
			 p[row].dev_id);
		snprintf(table[row + 1][1], TABLE_MAX_ELT_LEN, "%7d",
			 p[row].processor_id);
		strncpy(table[row + 1][2], p[row].name, TABLE_MAX_ELT_LEN);
		/* ToDo: Should we get the state from proc ops */
		snprintf(table[row + 1][3], TABLE_MAX_ELT_LEN, "%s",
			 ti_sci_cmd_get_device_status(p[row].dev_id));
		ti_sci_cmd_get_clk_freq(p[row].dev_id, p[row].clk_id, &freq);
		snprintf(table[row + 1][4], TABLE_MAX_ELT_LEN, "%lu", freq);
	}

	return autoadjust_table_print(table, row + 1, 5);

print_single_processor:
	ret = sscanf(argv[0], "%u", &proc_id);
	if (ret != 1)
		return -1;

	for (row = 0; row < soc_info.sci_info.num_processors; row++) {
		if (proc_id != p[row].processor_id)
			continue;
		snprintf(table[found + 1][0], TABLE_MAX_ELT_LEN, "%5d",
			 p[row].dev_id);
		snprintf(table[found + 1][1], TABLE_MAX_ELT_LEN, "%7d",
			 p[row].processor_id);
		strncpy(table[found + 1][2], p[row].name, TABLE_MAX_ELT_LEN);
		/* ToDo: Should we get the state from proc ops */
		snprintf(table[found + 1][3], TABLE_MAX_ELT_LEN, "%s",
			 ti_sci_cmd_get_device_status(p[row].dev_id));
		ti_sci_cmd_get_clk_freq(p[row].dev_id, p[row].clk_id, &freq);
		snprintf(table[found + 1][4], TABLE_MAX_ELT_LEN, "%lu", freq);
		found++;
		break;
	}
	if (!found)
		return -1;

	return autoadjust_table_print(table, found + 1, 5);
}

int process_dump_command(int argc, char *argv[])
{
	int ret;

	if (argc < 1) {
		help(HELP_DUMP);
		return -1;
	}

	if (!strncmp(argv[0], "device", 6)) {
		argc--;
		argv++;
		ret = dump_devices_info(argc, argv);
		if (ret) {
			fprintf(stderr, "Invalid device arguments\n");
			help(HELP_DUMP_DEVICE);
		}
	} else if (!strncmp(argv[0], "clock", 5)) {
		argc--;
		argv++;
		ret = dump_clocks_info(argc, argv);
		if (ret) {
			fprintf(stderr, "Invalid clock arguments\n");
			help(HELP_DUMP_CLOCK);
		}
	} else if(!strncmp(argv[0], "processor", 9)) {
		argc--;
		argv++;
		ret = dump_processors_info(argc, argv);
		if (ret)
			help(HELP_DUMP_PROCESSOR);
	} else if (!strcmp(argv[0], "--help")) {
		help(HELP_DUMP);
		return 0;
	} else {
		fprintf(stderr, "Invalid argument %s\n", argv[1]);
		help(HELP_DUMP);
		return -1;
	}
	return ret;
}
