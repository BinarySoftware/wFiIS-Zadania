cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-Wall -g")

project(Lab06)

set(SOURCES main.cpp lab06.cpp lab06.h )

add_executable(Lab06 ${SOURCES})
