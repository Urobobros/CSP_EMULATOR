cmake_minimum_required(VERSION 3.10)
project(csp_emulator)

add_library(csp_emulator
    src/cpu.cpp
    src/memory.cpp
    src/peripherals.cpp
    src/firmware.cpp
    src/algorithms.cpp)

add_executable(csp_main src/main.cpp)
target_link_libraries(csp_main csp_emulator)
