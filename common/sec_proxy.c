/*
 * K3 Secure proxy driver
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

#include <stdio.h>
#include <stdint.h>
#include <sec_proxy.h>
#include <mmio.h>
#include <error.h>
#include <socinfo.h>

/* SEC PROXY RT THREAD STATUS */
#define RT_THREAD_STATUS			0x0
#define RT_THREAD_THRESHOLD			0x4
#define RT_THREAD_STATUS_ERROR_SHIFT		31
#define RT_THREAD_STATUS_ERROR_MASK		(1 << 31)
#define RT_THREAD_STATUS_CUR_CNT_SHIFT		0
#define RT_THREAD_STATUS_CUR_CNT_MASK		0xff

/* SEC PROXY SCFG THREAD CTRL */
#define SCFG_THREAD_CTRL			0x1000
#define SCFG_THREAD_CTRL_DIR_SHIFT		31
#define SCFG_THREAD_CTRL_DIR_MASK		(1 << 31)

#define SEC_PROXY_THREAD(base, x)		((base) + (0x1000 * (x)))
#define SEC_PROXY_TX_THREAD			0
#define SEC_PROXY_RX_THREAD			1
#define SEC_PROXY_MAX_THREADS			2

#define SEC_PROXY_TIMEOUT_US			1000000

#define SEC_PROXY_DATA_START_OFFS		0x4
#define SEC_PROXY_DATA_END_OFFS			0x3c

/* Physical address for AM6 NAVSS 256 Main domain */
#define SEC_PROXY0_CFG_MMRS		0x31140000
#define SEC_PROXY0_SRC_TARGET_DATA	0x32C00000
#define SEC_PROXY0_CFG_SCFG		0x32800000
#define SEC_PROXY0_CFG_RT		0x32400000

struct k3_sec_proxy_thread {
	uint32_t id;
	uintptr_t data;
	uintptr_t scfg;
	uintptr_t rt;
} spts[SEC_PROXY_MAX_THREADS];

static inline uint32_t sp_readl(uintptr_t addr)
{
	return mmio_read_32(addr);
}

static inline void sp_writel(uintptr_t addr, uint32_t data)
{
	mmio_write_32(addr, data);
}

static int k3_sec_proxy_verify_thread(uint32_t dir)
{
	struct k3_sec_proxy_thread *spt = &spts[dir];

	/* Check for any errors already available */
	if (sp_readl(spt->rt + RT_THREAD_STATUS) &
	    RT_THREAD_STATUS_ERROR_MASK) {
		fprintf(stderr, "%s: Thread %d is corrupted, cannot send data.\n",
		       __func__, spt->id);
		return -1;
	}

	/* Make sure thread is configured for right direction */
	if ((sp_readl(spt->scfg + SCFG_THREAD_CTRL)
	    & SCFG_THREAD_CTRL_DIR_MASK) >> SCFG_THREAD_CTRL_DIR_SHIFT != dir) {
		if (dir)
			fprintf(stderr, "%s: Trying to receive data on tx Thread %d\n",
			       __func__, spt->id);
		else
			fprintf(stderr, "%s: Trying to send data on rx Thread %d\n",
			       __func__, spt->id);
		return -1;
	}

	/* Check the message queue before sending/receiving data */
	if (!(sp_readl(spt->rt + RT_THREAD_STATUS) &
	      RT_THREAD_STATUS_CUR_CNT_MASK))
		return -2;

	return 0;
}

int k3_sec_proxy_send(struct k3_sec_proxy_msg *msg)
{
	struct k3_sec_proxy_thread *spt = &spts[SEC_PROXY_TX_THREAD];
	int num_words, trail_bytes, ret;
	uint32_t *word_data;
	uintptr_t data_reg;

	ret = k3_sec_proxy_verify_thread(SEC_PROXY_TX_THREAD);
	if (ret) {
		fprintf(stderr, "%s: Thread%d verification failed. ret = %d\n",
			__func__, spt->id, ret);
		return ret;
	}

	/* Check the message size. */
	if (msg->len > SEC_PROXY_MAX_MSG_SIZE) {
		fprintf(stderr, "%s: Thread %u message length %zu > max msg size %d\n",
		       __func__, spt->id, msg->len, SEC_PROXY_MAX_MSG_SIZE);
		return -1;
	}

	/* Send the message */
	data_reg = spt->data + SEC_PROXY_DATA_START_OFFS;
	word_data = (uint32_t *)msg->buf;
	for (num_words = msg->len / sizeof(uint32_t);
	     num_words;
	     num_words--, data_reg += sizeof(uint32_t), word_data++)
		sp_writel(data_reg, *word_data);

	trail_bytes = msg->len % sizeof(uint32_t);
	if (trail_bytes) {
		uint32_t data_trail = *word_data;

		/* Ensure all unused data is 0 */
		data_trail &= 0xFFFFFFFF >> (8 * (sizeof(uint32_t) - trail_bytes));
		sp_writel(data_reg, data_trail);
		data_reg++;
	}

	/*
	 * 'data_reg' indicates next register to write. If we did not already
	 * write on tx complete reg(last reg), we must do so for transmit
	 */
	if (data_reg <= (spt->data + SEC_PROXY_DATA_END_OFFS))
		sp_writel(spt->data + SEC_PROXY_DATA_END_OFFS, 0);

	return 0;
}

int k3_sec_proxy_recv(struct k3_sec_proxy_msg *msg)
{
	struct k3_sec_proxy_thread *spt = &spts[SEC_PROXY_RX_THREAD];
	int num_words, ret = -1, retry = 10000;
	uint32_t *word_data;
	uintptr_t data_reg;

	while (retry-- && ret) {
		ret = k3_sec_proxy_verify_thread(SEC_PROXY_RX_THREAD);
		if ((ret && ret != -2) || !retry) {
			fprintf(stderr, "%s: Thread%d verification failed. ret = %d\n",
				__func__, spt->id, ret);
			return ret;
		}
	}

	data_reg = spt->data + SEC_PROXY_DATA_START_OFFS;
	word_data = (uint32_t *)(uintptr_t)msg->buf;
	for (num_words = SEC_PROXY_MAX_MSG_SIZE / sizeof(uint32_t);
	     num_words;
	     num_words--, data_reg += sizeof(uint32_t), word_data++)
		*word_data = sp_readl(data_reg);

	return 0;
}

int k3_sec_proxy_init(void)
{
	uint32_t rx_thread, tx_thread;

	if (soc_info.host_id == DEFAULT_HOST_ID) {
		tx_thread = DEFAULT_SEC_PROXY_TX_THREAD;
		rx_thread = DEFAULT_SEC_PROXY_RX_THREAD;
	}

	/* ToDO: Get thread ids using host_id and soc information */
	spts[SEC_PROXY_TX_THREAD].id = tx_thread;
	spts[SEC_PROXY_TX_THREAD].data = SEC_PROXY_THREAD(SEC_PROXY0_SRC_TARGET_DATA, tx_thread);
	spts[SEC_PROXY_TX_THREAD].scfg = SEC_PROXY_THREAD(SEC_PROXY0_CFG_SCFG, tx_thread);
	spts[SEC_PROXY_TX_THREAD].rt = SEC_PROXY_THREAD(SEC_PROXY0_CFG_RT, tx_thread);

	spts[SEC_PROXY_RX_THREAD].id = rx_thread;
	spts[SEC_PROXY_RX_THREAD].data = SEC_PROXY_THREAD(SEC_PROXY0_SRC_TARGET_DATA, rx_thread);
	spts[SEC_PROXY_RX_THREAD].scfg = SEC_PROXY_THREAD(SEC_PROXY0_CFG_SCFG, rx_thread);
	spts[SEC_PROXY_RX_THREAD].rt = SEC_PROXY_THREAD(SEC_PROXY0_CFG_RT, rx_thread);

	return 0;
}
