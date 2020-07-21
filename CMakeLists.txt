cmake_minimum_required(VERSION 3.16.5)

project(uEtch)

set(C_STANDARD C90)

set(uetch_common_headers src/platform/dgeom.h include/libuetch.h include/getcomp.h)
set(uetch_common_sources src/platform/dgeom.c)

if(${CMAKE_SYSTEM_NAME} MATCHES Linux)
    add_library(uetch SHARED ${uetch_common_headers} ${uetch_common_sources} src/platform/linux/linux_dgeom.c src/platform/linux/linux_dgeom.h)
endif(${CMAKE_SYSTEM_NAME} MATCHES Linux)
if (${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_library(uetch SHARED ${uetch_common_headers} ${uetch_common_sources} src/platform/nt/nt_dgeom.c src/platform/nt/nt_dgeom.h)
endif (${CMAKE_SYSTEM_NAME} MATCHES Windows)
include_directories(include src)

add_executable(uecli cli/cli.c)
target_link_libraries(uecli uetch)
add_dependencies(uecli uetch)
