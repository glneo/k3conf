/*
 * Help Library for K3CONF
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

#include <help.h>
#include <stdio.h>

void help(help_category cat)
{
	if (cat >= HELP_CATEGORY_MAX) {
		fprintf(stderr, "help called with incorrect category!!! (%d)\n",
			cat);
		return;
	}

	if ((cat == HELP_ALL) || (cat == HELP_USAGE)) {
		printf("\nNAME\n");
		printf("\tk3conf - TI K3 Configuration Diagnostic Tool\n");

		printf("\nSYNOPSIS\n");
		printf("\tk3conf [--version] [--help] <command> [<args>]\n");
		if (cat == HELP_USAGE)
			printf("\n\tSee 'k3conf --help' for more information.\n\n");
	}

	if (cat == HELP_ALL) {
		printf("\nDESCRIPTION\n");
		printf("\tk3conf is standalone application designed to provide"
			" a quick'n easy way to \n\tdiagnose/debug/audit"
			" TI K3 architecture based processors configuration"
			" at\n\truntime, with no particular kernel dependency.\n");
		printf("\tk3conf is designed to be as much platform-agnostic"
			" as possible, being able to \n\trun on any Linux platform"
			" and easily ported to other OS.\n");
		printf("\tEven if k3conf today focuses mainly on TISCI"
			" related functionality, it is \n\tintended to be extended"
			" to any other area.\n");

		printf("\nOPTIONS\n");
		printf("\t--help\n");
		printf("\t    Print k3conf help.\n");

		printf("\n\t--version\n");
		printf("\t    Print k3conf version.\n");
	}

	if (cat != HELP_USAGE)
		printf("\nCOMMANDS\n");

	if ((cat == HELP_ALL) || (cat == HELP_SHOW) ||
	    (cat == HELP_SHOW_HOST)) {
		printf("\n\tk3conf show hosts\n");
		printf("\t	Prints all the available TISCI hosts\n");
	}
	if ((cat == HELP_ALL) || (cat == HELP_SHOW) ||
	    (cat == HELP_SHOW_SEC_PROXY)) {
		printf("\n\tk3conf show threads\n");
		printf("\t	Prints all the available TISCI secure proxy threads\n");
	}
	if ((cat == HELP_ALL) || (cat == HELP_SHOW) ||
	    (cat == HELP_SHOW_DEVICE)) {
		printf("\n\tk3conf show device\n");
		printf("\t	Prints all the available TISCI devices\n");
		printf("\n\tk3conf show device <dev_id>\n");
		printf("\t	Prints the corresponding device id information\n");
	}
	if ((cat == HELP_ALL) || (cat == HELP_SHOW) ||
	    (cat == HELP_SHOW_CLOCK)) {
		printf("\n\tk3conf show clock\n");
		printf("\t	Prints all the available TISCI clocks\n");
		printf("\n\tk3conf show clock <dev_id>\n");
		printf("\t	Prints the clocks for corresponding device id\n");
	}
	if ((cat == HELP_ALL) || (cat == HELP_SHOW) ||
	    (cat == HELP_SHOW_PROCESSOR)) {
		printf("\n\tk3conf show processor\n");
		printf("\t	Prints all the available TISCI processors\n");
	}
}
