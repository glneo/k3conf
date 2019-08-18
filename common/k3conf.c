/*
 * K3CONF main entry file
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

#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sec_proxy.h>
#include <tisci.h>
#include <version.h>
#include <socinfo.h>
#include <help.h>
#include <string.h>

void k3conf_print_version(FILE *stream)
{
	struct ti_sci_version_info ver = soc_info.sci_info.version;

	if (stream == NULL) {
		fprintf(stderr, "%s(): stream == NULL!!!\n", __func__);
		return;
	}

	fprintf(stream, "K3CONF (version %s built %s)\n", k3conf_version,
		builddate);
	fprintf(stream, "SoC %s\n", soc_info.soc_full_name);

	if (!soc_info.ti_sci_enabled)
		return;

	fprintf(stream, "SYSFW ABI: %d.%d (firmware version 0x%04x '%.*s)')\n",
		ver.abi_major, ver.abi_minor, ver.firmware_version,
		(int)sizeof(ver.firmware_description),
		ver.firmware_description);
}

int main(int argc, char *argv[])
{
	int ret = 0;

	/* Scan user arguments for options */
	argc--;
	argv++;

	if (argc == 0) {
		help(HELP_USAGE);
		ret = -1;
		goto main_exit;
	}

	if (soc_init())
		goto main_exit;

	if (!strcmp(argv[0], "--help")) {
		k3conf_print_version(stdout);
		help(HELP_ALL);
		goto main_exit;
	} else if (!strcmp(argv[0], "--version")) {
		k3conf_print_version(stdout);
		goto main_exit;
	} else {
		fprintf(stderr, "Invalid argument %s", argv[0]);
		help(HELP_USAGE);
		ret = -1;
		goto main_exit;
	}

main_exit:
	return ret;
}
