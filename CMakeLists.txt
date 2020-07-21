cmake_minimum_required(VERSION 3.17.0)

project(uEtch)

set(C_STANDARD C90)

add_library(uetch SHARED include/libuetch.h src/platform/dgeom.h src/platform/dgeom.c src/platform/linux/linux_dgeom.c src/platform/linux/linux_dgeom.h src/platform/nt/nt_dgeom.c src/platform/nt/nt_dgeom.h cli/cli.c)
include_directories(include src)
add_executable(uecli cli/cli.c)
target_link_libraries(uecli uetch)
add_dependencies(uecli uetch)
