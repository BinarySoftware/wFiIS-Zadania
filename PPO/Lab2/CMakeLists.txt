#ustawienie wersji CMake
cmake_minimum_required(VERSION 3.10)

#nazwa projektu
project(lab4_MaciejM)

#ustawienie flag podczas kompilacji
set (CMAKE_CXX_FLAGS "-Wall -g")

# ustawienie standardu C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# dodanie pliku wykonywalnego
set(SOURCES main.cpp funkcje.cpp)
add_executable(Lab01 ${SOURCES})