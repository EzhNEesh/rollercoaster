cmake_minimum_required(VERSION 3.15)

project(rollercoaster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rollercoaster "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/binaryreader.cpp" "${CMAKE_SOURCE_DIR}/src/binaryreader.h"
    "${CMAKE_SOURCE_DIR}/src/normaldistribution.cpp" "${CMAKE_SOURCE_DIR}/src/normaldistribution.h"
    "${CMAKE_SOURCE_DIR}/src/rollercoaster.cpp" "${CMAKE_SOURCE_DIR}/src/rollercoaster.h")

add_subdirectory(test)
