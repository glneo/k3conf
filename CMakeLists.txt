cmake_minimum_required(VERSION 3.8)
project(k3conf C)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)

set(K3CONF_SOURCES
# Common
	common/k3conf.c
	common/help.c
	common/mmio.c
	common/socinfo.c
	common/sec_proxy.c
	common/tisci/tisci_core.c
	common/tisci/tisci_device.c
	common/tisci/tisci_clock.c
	common/autoadjust_table.c
	common/cmd_show.c
	common/cmd_dump.c
	common/cmd_enable.c
	common/cmd_disable.c
	common/cmd_set.c
	common/cmd_rw.c
# AM65x
	soc/am65x/am65x_host_info.c
	soc/am65x/am65x_sec_proxy_info.c
	soc/am65x/am65x_processors_info.c
	soc/am65x/am65x_devices_info.c
	soc/am65x/am65x_clocks_info.c
	soc/am65x/am65x_rm_info.c
	soc/am65x_sr2/am65x_sr2_host_info.c
	soc/am65x_sr2/am65x_sr2_sec_proxy_info.c
	soc/am65x_sr2/am65x_sr2_processors_info.c
	soc/am65x_sr2/am65x_sr2_devices_info.c
	soc/am65x_sr2/am65x_sr2_clocks_info.c
	soc/am65x_sr2/am65x_sr2_rm_info.c
# J721e
	soc/j721e/j721e_host_info.c
	soc/j721e/j721e_sec_proxy_info.c
	soc/j721e/j721e_processors_info.c
	soc/j721e/j721e_devices_info.c
	soc/j721e/j721e_clocks_info.c
	soc/j721e/j721e_rm_info.c
	soc/j7200/j7200_host_info.c
	soc/j7200/j7200_sec_proxy_info.c
	soc/j7200/j7200_processors_info.c
	soc/j7200/j7200_devices_info.c
	soc/j7200/j7200_clocks_info.c
	soc/j7200/j7200_rm_info.c
# AM64x
	soc/am64x/am64x_host_info.c
	soc/am64x/am64x_sec_proxy_info.c
	soc/am64x/am64x_processors_info.c
	soc/am64x/am64x_devices_info.c
	soc/am64x/am64x_clocks_info.c
	soc/am64x/am64x_rm_info.c

# AM62x
	soc/am62x/am62x_devices_info.c
	soc/am62x/am62x_clocks_info.c
	soc/am62x/am62x_host_info.c
	soc/am62x/am62x_processors_info.c
	soc/am62x/am62x_rm_info.c
	soc/am62x/am62x_sec_proxy_info.c

# J721s2
	soc/j721s2/j721s2_devices_info.c
	soc/j721s2/j721s2_clocks_info.c
	soc/j721s2/j721s2_host_info.c
	soc/j721s2/j721s2_processors_info.c
	soc/j721s2/j721s2_rm_info.c
	soc/j721s2/j721s2_sec_proxy_info.c

# J784s4
	soc/j784s4/j784s4_clocks_info.c
	soc/j784s4/j784s4_devices_info.c
	soc/j784s4/j784s4_host_info.c
	soc/j784s4/j784s4_processors_info.c
	soc/j784s4/j784s4_rm_info.c
	soc/j784s4/j784s4_sec_proxy_info.c

# AM62Ax
	soc/am62ax/am62ax_clocks_info.c
	soc/am62ax/am62ax_devices_info.c
	soc/am62ax/am62ax_host_info.c
	soc/am62ax/am62ax_processors_info.c
	soc/am62ax/am62ax_rm_info.c
	soc/am62ax/am62ax_sec_proxy_info.c
)

# Set build timestamp
string(TIMESTAMP TIMEDATE "%a %b %d %H:%M:%S UTC %Y" UTC)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/builddate.c "char *builddate=\"${TIMEDATE}\";\n")
list(APPEND K3CONF_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/builddate.c)

# Set version from Git
execute_process(COMMAND git describe --dirty --tags
                OUTPUT_VARIABLE GIT_VERSION
                ERROR_QUIET)
if ("${GIT_VERSION}" STREQUAL "")
	set(GIT_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}-nogit")
else()
	string(STRIP "${GIT_VERSION}" GIT_VERSION)
endif()
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/version.c "char *k3conf_version=\"${GIT_VERSION}\";\n")
list(APPEND K3CONF_SOURCES ${CMAKE_CURRENT_BINARY_DIR}/version.c)

add_executable(k3conf ${K3CONF_SOURCES})

target_include_directories(k3conf PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(k3conf PRIVATE -Wall;-Wextra;-Wpedantic;-Wno-missing-field-initializers)

install(TARGETS k3conf RUNTIME DESTINATION bin)
