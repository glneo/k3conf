// SPDX-License-Identifier: BSD-3-Clause
/*
 * K3CONF Command Dump
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - https://www.ti.com/
 *	Lokesh Vutla <lokeshvutla@ti.com>
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <tisci.h>
#include <socinfo.h>
#include <help.h>
#include <autoadjust_table.h>
#include <k3conf.h>
#include <inttypes.h>

int dump_cpu_info(void)
{
	struct ti_sci_processors_info *p = soc_info.sci_info.processors_info;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	uint32_t row = 0, found = 0;
	uint64_t freq;

	autoadjust_table_init(table);
	strncpy(table[row][0], "Processor Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Processor State", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Processor Frequency", TABLE_MAX_ELT_LEN);

	for (row = 0; row < soc_info.sci_info.num_processors; row++) {
		if (strncmp(p[row].name, "A", 1))
			continue;
		strncpy(table[found + 1][0], p[row].name, TABLE_MAX_ELT_LEN);
		/* ToDo: Should we get the state from proc ops */
		snprintf(table[found + 1][1], TABLE_MAX_ELT_LEN, "%s",
			 ti_sci_cmd_get_device_status(p[row].dev_id));
		ti_sci_cmd_get_clk_freq(p[row].dev_id, p[row].clk_id, &freq);
		snprintf(table[found + 1][2], TABLE_MAX_ELT_LEN, "%" PRIu64, freq);
		found++;
	}

	return autoadjust_table_print(table, found + 1, 3);
}

int dump_clocks_info(int argc, char *argv[])
{
	struct ti_sci_clocks_info *tisci_c = soc_info.sci_info.clocks_info;
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
			 tisci_c[row].dev_id);
		snprintf(table[row + 1][1], TABLE_MAX_ELT_LEN, "%5d",
			 tisci_c[row].clk_id);
		strncpy(table[row + 1][2], tisci_c[row].clk_name, TABLE_MAX_ELT_LEN);
		snprintf(table[row + 1][3], TABLE_MAX_ELT_LEN, "%s",
			 ti_sci_cmd_get_clk_state(tisci_c[row].dev_id, tisci_c[row].clk_id));
		ti_sci_cmd_get_clk_freq(tisci_c[row].dev_id, tisci_c[row].clk_id, &freq);
		snprintf(table[row + 1][4], TABLE_MAX_ELT_LEN, "%" PRIu64, freq);
	}

	return autoadjust_table_print(table, row + 1, 5);

print_single_device:
	ret = sscanf(argv[0], "%u", &dev_id);
	if (ret != 1)
		return -1;

	for (row = 0; row < soc_info.sci_info.num_clocks; row++) {
		if (dev_id == tisci_c[row].dev_id) {
			const char *clk_state = ti_sci_cmd_get_clk_state(dev_id, tisci_c[row].clk_id);
			if (!clk_state)
				return -1;
			snprintf(table[found + 1][0], TABLE_MAX_ELT_LEN, "%5d",
				 tisci_c[row].dev_id);
			snprintf(table[found + 1][1], TABLE_MAX_ELT_LEN, "%5d",
				 tisci_c[row].clk_id);
			strncpy(table[found + 1][2], tisci_c[row].clk_name,
				TABLE_MAX_ELT_LEN);
			strncpy(table[found + 1][3], clk_state,
				TABLE_MAX_ELT_LEN);
			ti_sci_cmd_get_clk_freq(tisci_c[row].dev_id, tisci_c[row].clk_id,
						&freq);
			snprintf(table[found + 1][4], TABLE_MAX_ELT_LEN,
				 "%" PRIu64, freq);
			found++;
		}
	}

	if (!found)
		return -1;

	return autoadjust_table_print(table, found + 1, 5);
}

int dump_clock_parent_info(int argc, char *argv[])
{
	struct ti_sci_clocks_info *c = soc_info.sci_info.clocks_info;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	char clk_name[TABLE_MAX_ELT_LEN];
	char clk_name_len = 0;
	uint32_t row = 0, dev_id, clk_id, parent_clk_id = 0xffffffff;
	int found = 0, ret;
	uint64_t freq;

	if (argc != 2)
		return -1;

	ret = sscanf(argv[0], "%u", &dev_id);
	if (ret != 1)
		return -1;

	ret = sscanf(argv[1], "%u", &clk_id);
	if (ret != 1)
		return -1;

	autoadjust_table_init(table);
	strncpy(table[row][0], "Clock information", TABLE_MAX_ELT_LEN);
	row++;
	strncpy(table[row][0], "Device ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Clock ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Clock Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][3], "Status", TABLE_MAX_ELT_LEN);
	strncpy(table[row][4], "Clock Frequency", TABLE_MAX_ELT_LEN);

	for (found = 1, row = 0; row < soc_info.sci_info.num_clocks; row++) {
		if (dev_id != c[row].dev_id)
			continue;
		if (c[row].clk_id != clk_id)
			continue;
		snprintf(table[found + 1][0], TABLE_MAX_ELT_LEN, "%5d", c[row].dev_id);
		snprintf(table[found + 1][1], TABLE_MAX_ELT_LEN, "%5d", c[row].clk_id);
		strncpy(table[found + 1][2], c[row].clk_name, TABLE_MAX_ELT_LEN);
		strncpy(table[found + 1][3],
			ti_sci_cmd_get_clk_state(dev_id, c[row].clk_id),
			TABLE_MAX_ELT_LEN);
		ti_sci_cmd_get_clk_freq(c[row].dev_id, c[row].clk_id, &freq);
		snprintf(table[found + 1][4], TABLE_MAX_ELT_LEN, "%" PRIu64, freq);

		ti_sci_cmd_get_clk_parent(dev_id, clk_id, &parent_clk_id);
		strncpy(clk_name, c[row].clk_name, TABLE_MAX_ELT_LEN);
		clk_name_len = strnlen(clk_name, TABLE_MAX_ELT_LEN);
		found++;

		break;
	}

	if (found == 1)
		return -1;

	ret = autoadjust_table_generic_fprint(stdout, table, found + 1, 5,
					      TABLE_HAS_TITLE | TABLE_HAS_SUBTITLE);
	if (ret != 0)
		return ret;

	/* List out the parents and Mark the one that is selected */
	row = 0;
	autoadjust_table_init(table);
	strncpy(table[row][0], "Clock Parent information", TABLE_MAX_ELT_LEN);
	row++;
	strncpy(table[row][0], "Selected", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Clock ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Clock Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][3], "Status", TABLE_MAX_ELT_LEN);
	strncpy(table[row][4], "Clock Frequency", TABLE_MAX_ELT_LEN);

	for (found = 1, row = 0; row < soc_info.sci_info.num_clocks; row++) {
		int found_parent = 0;

		if (dev_id != c[row].dev_id)
			continue;
		if (c[row].clk_id == clk_id)
			continue;

		if (c[row].clk_id == parent_clk_id)
			found_parent = 1;
		else if (strncmp(c[row].clk_name, clk_name, clk_name_len))
			continue;

		snprintf(table[found + 1][0], TABLE_MAX_ELT_LEN, "%5s",
			 found_parent ? "==>" : "");
		snprintf(table[found + 1][1], TABLE_MAX_ELT_LEN, "%5d", c[row].clk_id);
		strncpy(table[found + 1][2], c[row].clk_name, TABLE_MAX_ELT_LEN);
		strncpy(table[found + 1][3],
			ti_sci_cmd_get_clk_state(dev_id, c[row].clk_id),
			TABLE_MAX_ELT_LEN);
		ti_sci_cmd_get_clk_freq(c[row].dev_id, c[row].clk_id, &freq);
		snprintf(table[found + 1][4], TABLE_MAX_ELT_LEN, "%" PRIu64, freq);
		found++;
	}

	if (!found)
		return -1;
	return autoadjust_table_generic_fprint(stdout, table, found + 1, 5,
					       TABLE_HAS_TITLE | TABLE_HAS_SUBTITLE);
}

int dump_devices_info(int argc, char *argv[])
{
	struct ti_sci_devices_info *tisci_p = soc_info.sci_info.devices_info;
	struct arm_scmi_devices_info *scmi_p = soc_info.scmi_info.devices_info;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	uint32_t row = 0, dev_id, num_devices;
	int found = 0, ret;
	const char *dev_status, *dev_name;

	if (soc_info.protocol == TISCI)
		num_devices = soc_info.sci_info.num_devices;
	else
		num_devices = soc_info.scmi_info.num_devices;

	autoadjust_table_init(table);
	strncpy(table[row][0], "Device ID", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Device Name", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Device Status", TABLE_MAX_ELT_LEN);

	if (argc)
		goto print_single_device;

	for (row = 0; row < num_devices; row++) {
		if (soc_info.protocol == TISCI) {
			dev_id = tisci_p[row].dev_id;
			dev_name = tisci_p[row].name;
			dev_status = ti_sci_cmd_get_device_status(dev_id);
		} else {
			dev_id = scmi_p[row].dev_id;
			dev_name = scmi_p[row].name;
			dev_status = scmi_cmd_get_device_status(dev_id);
		}
		snprintf(table[row + 1][0], TABLE_MAX_ELT_LEN, "%5d",
			dev_id);
		strncpy(table[row + 1][1], dev_name, TABLE_MAX_ELT_LEN);
		snprintf(table[row + 1][2], TABLE_MAX_ELT_LEN, "%s",
			dev_status);
	}

	return autoadjust_table_print(table, row + 1, 3);

print_single_device:
	ret = sscanf(argv[0], "%u", &dev_id);
	if (ret != 1)
		return -1;

	if (soc_info.protocol == TISCI) {
		for (row = 0; row < num_devices; row++) {
			if (dev_id == tisci_p[row].dev_id) {
				snprintf(table[1][0], TABLE_MAX_ELT_LEN, "%5d",
					tisci_p[row].dev_id);
				strncpy(table[1][1], tisci_p[row].name,
					TABLE_MAX_ELT_LEN);
				snprintf(table[1][2], TABLE_MAX_ELT_LEN, "%s",
					ti_sci_cmd_get_device_status(tisci_p[row].dev_id));
				found = 1;
				break;
			}
		}
	} else {
		dev_status = scmi_cmd_get_device_status(dev_id);
		if (dev_status != NULL) {
			snprintf(table[1][0], TABLE_MAX_ELT_LEN, "%5d",
				dev_id);
			strncpy(table[1][1], scmi_p[dev_id].name,
				TABLE_MAX_ELT_LEN);
			snprintf(table[1][2], TABLE_MAX_ELT_LEN, "%s",
				dev_status);
			found = 1;
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
		snprintf(table[row + 1][4], TABLE_MAX_ELT_LEN, "%" PRIu64, freq);
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
		snprintf(table[found + 1][4], TABLE_MAX_ELT_LEN, "%" PRIu64, freq);
		found++;
		break;
	}
	if (!found)
		return -1;

	return autoadjust_table_print(table, found + 1, 5);
}

static int dump_rm_resource(uint32_t type, uint32_t subtype,
			uint32_t host_id, char *value)
{
	struct ti_sci_rm_desc desc;
	int ret;

	ret = ti_sci_cmd_get_range(type, subtype, host_id, &desc);
	if (ret)
		return ret;

	if (desc.num_sec && desc.num) {

		/* Print Primary + Secondary range  */
		snprintf(value, TABLE_MAX_ELT_LEN, "[%5d +%4d] (%4d +%3d)",
				desc.start, desc.num,
				desc.start_sec, desc.num_sec);

	} else if (desc.num_sec) {

		/* Print blank + Secondary range  */
		snprintf(value, TABLE_MAX_ELT_LEN, "[           ] (%4d +%3d)",
				desc.start_sec, desc.num_sec);
	} else if (desc.num) {

		/* Print only Primary range */
		snprintf(value, TABLE_MAX_ELT_LEN,
				"[%5d +%4d]",
				desc.start, desc.num);
	} else {
		*value = 0;
	}

	return 0;
}

static int dump_rm_info(int argc, char *argv[])
{
	uint32_t filter_host_id = 0, filter_type = 0, filter_subtype = 0xFFF;
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	struct ti_sci_host_info *h = soc_info.sci_info.host_info;
	struct ti_sci_rm_info *r = soc_info.sci_info.rm_info;
	uint32_t type, subtype, host_id, host_valid;
	char cell[TABLE_MAX_ELT_LEN], *host_name;
	uint32_t i, j, row, col;
	int ret;

	if (argc > 0 && !strcmp(argv[0], "-h")) {

		if (argc == 1)
			return -1;

		sscanf(argv[1], "%u", &filter_host_id);
		argc -= 2;
		argv += 2;
	}

	if (argc > 0) {
		sscanf(argv[0], "%u", &filter_type);
		argc--;
		argv++;
	}

	if (argc > 0) {
		sscanf(argv[0], "%u", &filter_subtype);
		argc--;
		argv++;
	}

	autoadjust_table_init(table);
	snprintf(table[0][0], TABLE_MAX_ELT_LEN,
			"Resource allocation => [Primary start +count] (Secondary start +count)");
	snprintf(table[1][0], TABLE_MAX_ELT_LEN,
			"utype");
	snprintf(table[1][1], TABLE_MAX_ELT_LEN,
			"type");
	snprintf(table[1][2], TABLE_MAX_ELT_LEN,
			"subtype");

	row = 2;
	col = 3;
	for (i = 0; i < soc_info.sci_info.num_hosts; i++) {

		host_valid =  0;
		host_id = h[i].host_id;
		host_name = h[i].host_name;
		if (filter_host_id && host_id != filter_host_id)
			continue;

		row = 2;
		for (j = 0; j < soc_info.sci_info.num_res; j++) {

			type = r[j].utype >> 6;
			subtype = r[j].utype & 0x3F;

			if (filter_type && type != filter_type)
				continue;
			if (filter_subtype != 0xFFF && subtype != filter_subtype)
				continue;

			snprintf(table[row][0], TABLE_MAX_ELT_LEN,
				"0x%04x", r[j].utype);
			snprintf(table[row][1], TABLE_MAX_ELT_LEN,
				"%d", type);
			snprintf(table[row][2], TABLE_MAX_ELT_LEN,
				"%d", subtype);

			ret = dump_rm_resource(type, subtype, host_id, cell);
			if (ret)
				return ret;

			if (!cell[0]) {
				row++;
				continue;
			}

			host_valid = 1;
			snprintf(table[row][col], TABLE_MAX_ELT_LEN,
				"%s", cell);
			row++;
		}

		if (!host_valid)
			continue;

		snprintf(table[1][col], TABLE_MAX_ELT_LEN,
				"%s", host_name);
		col++;
	}

	return autoadjust_table_generic_fprint(stdout, table, row, col,
				TABLE_HAS_TITLE | TABLE_HAS_SUBTITLE);
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
	} else if (!strncmp(argv[0], "parent_clock", 12)) {
		argc--;
		argv++;
		ret = dump_clock_parent_info(argc, argv);
		if (ret) {
			fprintf(stderr, "Invalid clock_parent arguments\n");
			help(HELP_DUMP_CLOCK_PARENT);
		}
	} else if(!strncmp(argv[0], "processor", 9)) {
		argc--;
		argv++;
		ret = dump_processors_info(argc, argv);
		if (ret)
			help(HELP_DUMP_PROCESSOR);
	} else if(!strncmp(argv[0], "rm", 2)) {
		argc--;
		argv++;
		ret = dump_rm_info(argc, argv);
		if (ret) {
			fprintf(stderr, "Invalid arguments\n");
			help(HELP_DUMP_RM);
		}
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
