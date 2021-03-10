# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)


find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(proj)
zephyr_compile_definitions(PROJECT_NAME=${PROJECT_NAME})
zephyr_compile_definitions(_POSIX_C_SOURCE=200809L)

# HEADER FILES
zephyr_library_include_directories( 
     src/bluetooth/
     src/bluetooth/services
     )

# APPLICATION SOURCE FILES
add_subdirectory(src/bluetooth)

target_sources(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
