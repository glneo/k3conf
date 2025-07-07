// SPDX-License-Identifier: BSD-3-Clause
/*
 * SCMI helper apis header file
 *
 * Copyright (C) 2025 Texas Instruments Incorporated
 *
 * SCMI Specification: https://developer.arm.com/documentation/den0056/latest/
 */

#ifndef __SCMI_H
#define __SCMI_H

#include <stdint.h>

#define MAX_PROC_NAME_LEN	30
#define MAX_DEV_NAME_LEN	60
#define MAX_CLK_NAME_LEN	120
#define MAX_CLK_FUNC_LEN	30

struct arm_scmi_processors_info {
	char dev_name[MAX_PROC_NAME_LEN];
	uint32_t clk_id;
};

struct arm_scmi_devices_info {
	uint32_t dev_id;
	char name[MAX_DEV_NAME_LEN];
};

struct arm_scmi_clocks_info {
	char dev_name[MAX_DEV_NAME_LEN];
	uint32_t clk_id;
	char clk_name[MAX_CLK_NAME_LEN];
	char clk_function[MAX_CLK_FUNC_LEN];
};

struct arm_scmi_version_info {
	uint32_t impl_version;
};

struct arm_scmi_info {
	struct arm_scmi_version_info version;
	struct arm_scmi_processors_info *processors_info;
	uint32_t num_processors;
	struct arm_scmi_devices_info *devices_info;
	uint32_t num_devices;
	struct arm_scmi_clocks_info *clocks_info;
	uint32_t num_clocks;
};

#endif
