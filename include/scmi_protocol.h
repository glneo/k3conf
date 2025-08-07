/* SPDX-License-Identifier: BSD-3-Clause */
/*
 * SCMI Protocol header file
 *
 * Copyright (C) 2025 Texas Instruments Incorporated - https://www.ti.com/
 *
 * SCMI Specification: https://developer.arm.com/documentation/den0056/latest/
 */

#ifndef __SCMI_P_H
#define __SCMI_P_H

#include <stdint.h>
#include <scmi_raw_interface.h>

/* Protocol IDs */
#define SCMI_BASE_ID	0x10

/* Message IDs */
#define SCMI_GET_IMPL_VERS_MSG_ID	0x05

/* Message Types */
#define SCMI_CMD_MSG_TYPE	0x00

struct scmi_msg_hdr {
	uint32_t hdr;
} __attribute__ ((__packed__));

struct scmi_msg_resp_impl_version {
	struct scmi_msg_hdr hdr;
	int32_t status;
	uint32_t impl_version;
} __attribute__ ((__packed__));

void scmi_setup_header(struct scmi_msg_hdr *msg_hdr, uint32_t protocol_id, uint32_t msg_id,
			 uint32_t msg_type);
int scmi_xfer_msg(struct scmi_raw_msg *msg);

#endif
