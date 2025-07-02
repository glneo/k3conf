// SPDX-License-Identifier: BSD-3-Clause
/*
 * SCMI Raw Interface header file
 *
 * Copyright (C) 2025 Texas Instruments Incorporated
 *
 * SCMI Specification: https://developer.arm.com/documentation/den0056/latest/
 */

#include <stdio.h>
#include <stdint.h>

#ifndef __SCMI_RAW_H
#define __SCMI_RAW_H

int scmi_raw_init(void);

extern struct arm_scmi_raw_interface_info raw_info;

#endif /* __SCMI_RAW_H */
