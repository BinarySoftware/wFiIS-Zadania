cmake_minimum_required(VERSION 3.16)
project(cycle C)

set(CMAKE_C_STANDARD 11)

add_executable(cycle cycle_main.c cycle.c cycle.h)