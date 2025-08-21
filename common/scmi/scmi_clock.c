// SPDX-License-Identifier: BSD-3-Clause
/*
 * SCMI clock ops library
 *
 * Copyright (C) 2025 Texas Instruments Incorporated - https://www.ti.com/
 *
 * SCMI Specification: https://developer.arm.com/documentation/den0056/latest/
 */

#include <string.h>
#include <scmi_raw_interface.h>
#include <scmi_protocol.h>
#include <scmi.h>

const char *scmi_cmd_get_clk_state(uint32_t clk_id, uint32_t flags)
{
	struct scmi_msg_resp_get_clk_state *resp;
	struct scmi_msg_req_get_clk_state *req;
	uint8_t buf[SCMI_RAW_MAX_MSG_SIZE];
	struct scmi_raw_msg msg;
	int ret;

	memset(buf, 0, sizeof(buf));
	scmi_setup_header((struct scmi_msg_hdr *)buf, SCMI_CLK_ID,
				SCMI_GET_CLK_STATE_MSG_ID, SCMI_CMD_MSG_TYPE);

	req = (struct scmi_msg_req_get_clk_state *)buf;
	req->flags = flags;
	req->id = clk_id;

	msg.len = sizeof(*req);
	msg.buf = buf;
	ret = scmi_xfer_msg(&msg);
	if (ret)
		return NULL;

	resp = (struct scmi_msg_resp_get_clk_state *)buf;
	switch (resp->config) {
		case SCMI_CLOCK_STATE_DISABLED:
			return "CLK_STATE_NOT_READY";
		case SCMI_CLOCK_STATE_ENABLED:
			return "CLK_STATE_READY";
		default:
			return "CLK_STATE_ERROR";
	}
}

int scmi_cmd_get_clk_freq(uint32_t clk_id, uint64_t *freq)
{
	struct scmi_msg_resp_get_clk_freq *resp;
	struct scmi_msg_req_get_clk_freq *req;
	uint8_t buf[SCMI_RAW_MAX_MSG_SIZE];
	struct scmi_raw_msg msg;
	int ret;

	memset(buf, 0, sizeof(buf));
	scmi_setup_header((struct scmi_msg_hdr *)buf, SCMI_CLK_ID,
				SCMI_GET_CLK_FREQ_MSG_ID, SCMI_CMD_MSG_TYPE);

	req = (struct scmi_msg_req_get_clk_freq *)buf;
	req->id = clk_id;

	msg.len = sizeof(*req);
	msg.buf = buf;
	ret = scmi_xfer_msg(&msg);
	if (ret)
		return ret;

	resp = (struct scmi_msg_resp_get_clk_freq *)buf;
	*freq = resp->rate;

	return 0;
}
