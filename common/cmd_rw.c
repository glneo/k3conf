/*
 * K3CONF Command Read and write
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - https://www.ti.com/
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
#include <stdint.h>
#include <stdio.h>
#include <tisci.h>
#include <socinfo.h>
#include <help.h>
#include <k3conf.h>
#include <mmio.h>

int process_read_command(int argc, char *argv[])
{
	uint64_t addr = 0;
	int ret, num_read_bits = 32;

	if (argc < 1) {
		help(HELP_READ);
		return -1;
	}

	ret = sscanf(argv[0], "%lx", &addr);
	if (ret != 1) {
		help(HELP_READ);
		return -1;
	}

	if (argc == 2)
		ret = sscanf(argv[1], "%d", &num_read_bits);

	switch (num_read_bits) {
	case 8:
		fprintf(stdout, "Value at addr 0x%lx = 0x%x\n\n", addr,
			mmio_read_8(addr));
		break;
	case 16:
		fprintf(stdout, "Value at addr 0x%lx = 0x%x\n\n", addr,
			mmio_read_16(addr));
		break;
	case 32:
		fprintf(stdout, "Value at addr 0x%lx = 0x%x\n\n", addr,
			mmio_read_32(addr));
		break;
	case 64:
		fprintf(stdout, "Value at addr 0x%lx = 0x%lx\n\n", addr,
			mmio_read_64(addr));
		break;
	default:
		fprintf(stdout, "Wrong input size, expected input size is 8,16,32,64\n");
		return -1;
	};
	return 0;
}

int process_write_command(int argc, char *argv[])
{
	unsigned long val;
	uint64_t addr;
	int ret, num_write_bits = 32;

	if (argc < 2) {
		help(HELP_WRITE);
		return -1;
	}

	ret = sscanf(argv[0], "%lx", &addr);
	if (ret != 1) {
		help(HELP_WRITE);
		return -1;
	}

	ret = sscanf(argv[1], "%lx", &val);
	if (ret != 1) {
		help(HELP_WRITE);
		return -1;
	}

	if (argc == 3)
		ret = sscanf(argv[2], "%d", &num_write_bits);

	switch (num_write_bits) {
	case 8:
		mmio_write_8(addr, val);
		fprintf(stdout, "Value at addr 0x%lx = 0x%x\n\n", addr,
			mmio_read_8(addr));
		break;
	case 16:
		mmio_write_16(addr, val);
		fprintf(stdout, "Value at addr 0x%lx = 0x%x\n\n", addr,
			mmio_read_16(addr));
		break;
	case 32:
		mmio_write_32(addr, val);
		fprintf(stdout, "Value at addr 0x%lx = 0x%x\n\n", addr,
			mmio_read_32(addr));
		break;
	case 64:
		mmio_write_64(addr, val);
		fprintf(stdout, "Value at addr 0x%lx = 0x%lx\n\n", addr,
			mmio_read_64(addr));
		break;
	default:
		fprintf(stdout, "Wrong input size, expected input size is 8,16,32,64\n");
		return -1;
	};

	return 0;
}
