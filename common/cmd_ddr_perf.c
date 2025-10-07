// SPDX-License-Identifier: BSD-3-Clause
/*
 * K3CONF DDR b/w capture
 *
 * Copyright (C) 2023 Texas Instruments Incorporated - https://www.ti.com/
 *	Aarya Chaumal <a-chaumal@ti.com>
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <socinfo.h>
#include <help.h>
#include <k3conf.h>
#include <mmio.h>
#include <ddr_perf.h>
#include <autoadjust_table.h>

static bool parse_line(FILE *fp, uint32_t *count, uint64_t *time)
{
	int ret = fscanf(fp, "%*f;%u;;%*[^;];%lu;%*f;;", count, time);
	return (ret == 2); // Should read in 2 items
}

int ddrbw_info(int argc, char *argv[])
{
	char table[TABLE_MAX_ROW][TABLE_MAX_COL][TABLE_MAX_ELT_LEN];
	uint32_t row = 0;
	int ret = 0;
	uint32_t duration = 1;
	int auto_refresh = -1;
	struct ddr_perf_soc_info *pinfo = soc_info.ddr_perf_info;

	if (!pinfo) {
		fprintf(stderr,
			"DDR performance monitoring is not supported on this SoC\n");
		return -1;
	}

	if (argc >= 1) {
		ret = sscanf(argv[0], "%u", &duration);
		if (ret != 1) {
			fprintf(stderr, "Invalid argument for duration.\n");
			help(HELP_DUMP_DDRBW);
			return -1;
		}
	}

	if (argc == 2) {
		ret = sscanf(argv[1], "%d", &auto_refresh);
		if (ret != 1) {
			fprintf(stderr, "Invalid argument for auto_refresh.\n");
			help(HELP_DUMP_DDRBW);
			return -1;
		}
	}

	autoadjust_table_init(table);
	strncpy(table[row][0], "Read data (MiB)", TABLE_MAX_ELT_LEN);
	strncpy(table[row][1], "Avg Read B/W (MiB/s)", TABLE_MAX_ELT_LEN);
	strncpy(table[row][2], "Write data (MiB)", TABLE_MAX_ELT_LEN);
	strncpy(table[row][3], "Avg Write B/W (MiB/s)", TABLE_MAX_ELT_LEN);

	char *command;
	asprintf(&command, "/root/perf stat -e k3_ddr/read/,k3_ddr/write/ -a -I %d --interval-count %d -x ';' 2>&1", duration * 1000, auto_refresh);
	FILE *fp = popen(command, "r");
	free(command);

	while (true) {
		uint32_t read_count, write_count;
		uint64_t read_time, write_time;

		/* Read count and time */
		if (!parse_line(fp, &read_count, &read_time)) break;
		read_time /= pinfo->num_perf_insts; // Un-aggregate time

		/* Write count and time */
		if (!parse_line(fp, &write_count, &write_time)) break;
		write_time /= pinfo->num_perf_insts; // Un-aggregate time

		float read_mibytes = ((float)read_count * pinfo->burst_size) / (1024 * 1024);
		float write_mibytes = ((float)write_count * pinfo->burst_size) / (1024 * 1024);

		float read_bw = read_mibytes / (read_time / 1000000000.0f);
		float write_bw = write_mibytes / (write_time / 1000000000.0f);

		snprintf(table[1][0], TABLE_MAX_ELT_LEN, "%.3f", read_mibytes);
		snprintf(table[1][1], TABLE_MAX_ELT_LEN, "%.3f", read_bw);
		snprintf(table[1][2], TABLE_MAX_ELT_LEN, "%.3f", write_mibytes);
		snprintf(table[1][3], TABLE_MAX_ELT_LEN, "%.3f", write_bw);

		ret = autoadjust_table_print(table, 2, 5);
	}

	pclose(fp);

	return ret;
}
