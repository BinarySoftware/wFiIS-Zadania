cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS "-Wall -g")

project(Lab05)

set(INCLUDES include)
set(SRC src)

include_directories(${INCLUDES})
include_directories(${SRC})

set(SOURCES main.cpp ${SRC}/plik.cpp ${YOUR_DIRECTORY}/plik.h )

add_executable(Lab05 ${SOURCES})
