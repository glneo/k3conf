/*
 * K3CONF mmio helpers
 *
 * Copyright (C) 2019 Texas Instruments Incorporated - https://www.ti.com/
 *	Lokesh Vutla <lokeshvutla@ti.com>
 *	Nishanth Menon <nm@ti.com>
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

#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <mmio.h>
#include <error.h>

#define MEMORY "/dev/mem"

unsigned page_size, mapped_size, offset_in_page;
void *map_base, *virt_addr;
int fd;

static int map_address(off_t target)
{
	unsigned int width = 8 * sizeof(uint64_t);

	fd = open(MEMORY, (O_RDWR | O_SYNC));
	if (fd < 0) {
		fprintf(stderr, "Could not open %s!\n", MEMORY);
		return -5;
	}

	mapped_size = page_size = getpagesize();
	offset_in_page = (unsigned)target & (page_size - 1);
	if (offset_in_page + width > page_size) {
		/*
		 * This access spans pages.
		 * Must map two pages to make it possible:
		 */
		mapped_size *= 2;
	}
	map_base = mmap(NULL,
			mapped_size,
			(PROT_READ | PROT_WRITE),
			MAP_SHARED, fd, target & ~(off_t) (page_size - 1));
	if (map_base == MAP_FAILED) {
		fprintf(stderr, "Map fail\n");
		return -1;
	}

	virt_addr = (char *)map_base + offset_in_page;
	return 0;
}

static uint64_t read_reg(int width)
{
	uint64_t read_result = 0x0;

	switch (width) {
	case 8:
		read_result = *(volatile uint8_t *)virt_addr;
		break;
	case 16:
		read_result = *(volatile uint16_t *)virt_addr;
		break;
	case 32:
		read_result = *(volatile uint32_t *)virt_addr;
		break;
	case 64:
		read_result = *(volatile uint64_t *)virt_addr;
		break;
	default:
		fprintf(stderr, "bad width");
	}

	return read_result;
}

static void write_reg(int width, uint64_t writeval)
{
	switch (width) {
	case 8:
		*(volatile uint8_t *)virt_addr = writeval;
		break;
	case 16:
		*(volatile uint16_t *)virt_addr = writeval;
		break;
	case 32:
		*(volatile uint32_t *)virt_addr = writeval;
		break;
	case 64:
		*(volatile uint64_t *)virt_addr = writeval;
		break;
	default:
		fprintf(stderr, "bad width");
	}

}

static void unmap_address(void)
{
	if (munmap(map_base, mapped_size) == -1)
		fprintf(stderr, "munmap");
	close(fd);

}

void mmio_write_8(uintptr_t addr, uint8_t value)
{
	int r;

	r = map_address(addr);
	if (r)
		return;
	write_reg(8, value);
	unmap_address();
}

uint8_t mmio_read_8(uintptr_t addr)
{
	uint8_t v = 0;
	int r;

	r = map_address(addr);
	if (r)
		return 0;
	v = read_reg(8);
	unmap_address();
	return v;
}

void mmio_write_16(uintptr_t addr, uint16_t value)
{
	int r;

	r = map_address(addr);
	if (r)
		return;
	write_reg(16, value);
	unmap_address();
}

uint16_t mmio_read_16(uintptr_t addr)
{
	uint16_t v = 0;
	int r;

	r = map_address(addr);
	if (r)
		return 0;
	v = read_reg(16);
	unmap_address();
	return v;
}

void mmio_write_32(uintptr_t addr, uint32_t value)
{
	int r;

	r = map_address(addr);
	if (r)
		return;
	write_reg(32, value);
	unmap_address();
}

uint32_t mmio_read_32(uintptr_t addr)
{
	uint32_t v = 0;
	int r;

	r = map_address(addr);
	if (r)
		return 0;
	v = read_reg(32);
	unmap_address();
	return v;
}

void mmio_write_64(uintptr_t addr, uint64_t value)
{
	int r;

	r = map_address(addr);
	if (r)
		return;
	write_reg(64, value);
	unmap_address();
}

uint64_t mmio_read_64(uintptr_t addr)
{
	uint64_t v = 0;
	int r;

	r = map_address(addr);
	if (r)
		return 0;
	v = read_reg(64);
	unmap_address();
	return v;
}
