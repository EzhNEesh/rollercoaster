cmake_minimum_required(VERSION 3.15)

project(rollercoaster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(rollercoaster "${CMAKE_SOURCE_DIR}/src/main.cpp"
    "${CMAKE_SOURCE_DIR}/src/binaryreader.cpp" "${CMAKE_SOURCE_DIR}/src/binaryreader.h"
    "${CMAKE_SOURCE_DIR}/src/normaldistribution.cpp" "${CMAKE_SOURCE_DIR}/src/normaldistribution.h"
    "${CMAKE_SOURCE_DIR}/src/rollercoaster.cpp" "${CMAKE_SOURCE_DIR}/src/rollercoaster.h")

add_subdirectory(test)

# find_package(GTest REQUIRED)

# include( GoogleTest )
# enable_testing()
# file( GLOB TestSources ${CMAKE_SOURCE_DIR}/test/*.cpp )

# add_executable( ${PROJECT_NAME}-test ${TestSources} )

# target_link_libraries(${PROJECT_NAME}-test gtest::gtest)
# gtest_discover_tests( ${PROJECT_NAME}-test WORKING_DIRECTORY
#     ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# # include(GNUInstallDirs)
# # install(TARGETS rollercoaster
# #     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
# #     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# # )
# target_include_directories( ${PROJECT_NAME}-test PUBLIC ${CMAKE_SOURCE_DIR}/src)

# configure_file(${CMAKE_SOURCE_DIR}/test/detector_src_32f.bin ${CMAKE_CURRENT_BINARY_DIR}/detector_src_32f.bin COPYONLY)
# configure_file(${CMAKE_SOURCE_DIR}/test/test_findrollercoasters_data.txt ${CMAKE_CURRENT_BINARY_DIR}/test_findrollercoasters_data.txt COPYONLY)
