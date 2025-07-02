// SPDX-License-Identifier: BSD-3-Clause
/*
 * SCMI device ops library
 *
 * Copyright (C) 2025 Texas Instruments Incorporated - https://www.ti.com/
 *
 * SCMI Specification: https://developer.arm.com/documentation/den0056/latest/
 */

#include <string.h>
#include <scmi_protocol.h>
#include <scmi.h>

const char *scmi_cmd_get_device_status(uint32_t dev_id)
{
	struct scmi_msg_resp_get_device_state *resp;
	struct scmi_msg_req_get_device_state *req;
	uint8_t buf[SCMI_RAW_MAX_MSG_SIZE];
	struct scmi_raw_msg msg;
	int ret = 0;

	memset(buf, 0, sizeof(buf));
	scmi_setup_header((struct scmi_msg_hdr *)buf, SCMI_PWR_DOMAIN_ID,
				SCMI_GET_PWR_DOMAIN_STATE_MSG_ID, SCMI_CMD_MSG_TYPE);

	req = (struct scmi_msg_req_get_device_state *)buf;
	req->id = dev_id;

	msg.len = sizeof(*req);
	msg.buf = buf;
	ret = scmi_xfer_msg(&msg);
	if (ret)
		return NULL;

	resp = (struct scmi_msg_resp_get_device_state *)buf;
	switch (resp->power_state) {
		case SCMI_DEVICE_STATE_OFF:
			return "DEVICE_STATE_OFF";
		case SCMI_DEVICE_STATE_ON:
			return "DEVICE_STATE_ON";
		default:
			return "DEVICE_STATE_UNKNOWN";
	}
}
