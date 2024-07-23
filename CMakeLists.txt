cmake_minimum_required(VERSION 3.15)

project(rollercoaster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(rollercoaster "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/binaryreader.cpp" "${CMAKE_SOURCE_DIR}/src/binaryreader.h"
    "${CMAKE_SOURCE_DIR}/src/normaldistribution.cpp" "${CMAKE_SOURCE_DIR}/src/normaldistribution.h"
    "${CMAKE_SOURCE_DIR}/src/rollercoaster.cpp" "${CMAKE_SOURCE_DIR}/src/rollercoaster.h")

include( GoogleTest )
enable_testing()
file( GLOB TestSources ${CMAKE_SOURCE_DIR}/test/*.cpp )

add_executable( ${PROJECT_NAME}-test ${TestSources} )

target_link_libraries(${PROJECT_NAME}-test gtest::gtest)
gtest_discover_tests( ${PROJECT_NAME}-test WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

include(GNUInstallDirs)
install(TARGETS rollercoaster
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
