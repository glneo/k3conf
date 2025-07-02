// SPDX-License-Identifier: BSD-3-Clause
/*
 * SCMI Raw Interface driver
 *
 * Copyright (C) 2025 Texas Instruments Incorporated
 *
 * SCMI Specification: https://developer.arm.com/documentation/den0056/latest/
 */

#include <stdio.h>
#include <stdint.h>
#include <scmi_raw_interface.h>
#include <socinfo.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define TRANS_DEFAULT_BASE_PATH	"/sys/kernel/debug/scmi/0"
#define TRANS_MESSAGE_FILE		"raw/message"
#define TRANS_MAX_RX_TIMEOUT_FILE	"transport/max_rx_timeout_ms"

struct arm_scmi_raw_interface_info raw_info;

int scmi_raw_init(void)
{
	int scmi_raw_base_fd = -1, max_rx_timeout_fd = -1, ret = 0;

	scmi_raw_base_fd = open(TRANS_DEFAULT_BASE_PATH, O_RDONLY | O_NONBLOCK);
	if (scmi_raw_base_fd < 0) {
		fprintf(stderr, "INIT: open(%s) failed, no access to raw interface! %d\n",
			TRANS_DEFAULT_BASE_PATH, scmi_raw_base_fd);
		ret = -1;
		goto exit;
	}

	max_rx_timeout_fd = openat(scmi_raw_base_fd, TRANS_MAX_RX_TIMEOUT_FILE,
			O_RDONLY | O_NONBLOCK);
	if (max_rx_timeout_fd < 0) {
		fprintf(stderr, "INIT: openat(%s/%s) failed! %d\n",
			TRANS_DEFAULT_BASE_PATH, TRANS_MAX_RX_TIMEOUT_FILE, max_rx_timeout_fd);
		ret = -1;
		goto exit;
	}

	ret = read(max_rx_timeout_fd, &raw_info.max_rx_timeout_ms,
			sizeof(raw_info.max_rx_timeout_ms));
	if (ret < 0) {
		fprintf(stderr, "INIT: read at %s/%s failed! %d\n",
			TRANS_DEFAULT_BASE_PATH, TRANS_MAX_RX_TIMEOUT_FILE, ret);
		ret = -1;
		goto exit;
	}
	ret = 0;

exit:
	if (max_rx_timeout_fd >= 0)
		close(max_rx_timeout_fd);
	if (scmi_raw_base_fd >= 0)
		close(scmi_raw_base_fd);

	return ret;
}
