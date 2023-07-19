###############################################################################
#                                                                             #
#                                   K3CONF                                    #
#                                                                             #
#    A Powerful Diagnostic Tool for Texas Instruments K3 based Processors     #
###############################################################################



INTRODUCTION:
-------------

K3CONF is a Linux user-space standalone application designed to provide a
quick'n easy way to dynamically diagnose Texas Instruments' K3 architecture
based processors. K3CONF is intended to provide similar experience to that of
OMAPCONF that runs on legacy TI platforms.

**WARNING**: This is work in progress! Don't expect things to be complete in any
dimension. Use at your own risk. And keep the reset button in reach.



SUPPORT:
--------

K3CONF currently supports AM654, J721E, J7200, AM64x, AM62x, J721S2, J784S4 and
AM62Ax Devices. Legacy OMAP and DRA7 platforms are not supported.



Build Instructions:
-------------------

Install build dependencies (Debian based example):

	# sudo apt install build-essential cmake

If cross-compiling, install and set your cross-compiler:

	# sudo apt install gcc-aarch64-linux-gnu
	# export CC=aarch64-linux-gnu-gcc

To build the output binary file run the following commands:

	# mkdir build
	# cd build
	# cmake ..
	# make

Copy the output binary "k3conf" to your Filesystem.

That's it!!



Help:
-----

Type "./k3conf --help" to get complete list of available commands and options.
Note that in case of incorrect command/option, help will also be displayed.
