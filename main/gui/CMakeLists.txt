# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(gui_guider)

FILE(GLOB app_sources src/*.c src/generated/*.c src/custom/*.c src/generated/guider_customer_fonts/*.c src/generated/guider_fonts/*.c src/generated/images/*.c)
target_include_directories(app PRIVATE src/generated src/custom src/generated/guider_customer_fonts src/generated/guider_fonts src/generated/images)
target_sources(app PRIVATE ${app_sources})
