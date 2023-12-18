cmake_minimum_required(VERSION 3.5)

# 开启调试级别日志打印
add_definitions(-DDEBUG_PRINT)

if (NOT DEFINED PROJECT_NAME)
    include($ENV{IDF_PATH}/tools/cmake/project.cmake)
    project(EspNanoTool)
else ()
    message(FATAL_ERROR "LV PORT ESP32: This must be a project's main CMakeLists.txt.")
endif ()

littlefs_create_partition_image(littlefs flash_built_in_files)
