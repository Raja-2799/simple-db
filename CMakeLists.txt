cmake_minimum_required(VERSION 3.20)

project(SimpleDB)

set(CMAKE_CXX_STANDARD 20)

#
# Database library
#
add_library(simpledb_lib
    src/page.cc
    src/blockId.cc
)

target_include_directories(simpledb_lib PUBLIC src)

#
# Main executable
#
add_executable(simpledb
    src/main.cc
)

target_link_libraries(simpledb
    simpledb_lib
)

#
# Tests
#
enable_testing()

find_package(GTest REQUIRED)

add_executable(simpledb_tests
    tests/page_test.cc
    tests/blockId_test.cc
)

target_link_libraries(simpledb_tests
    simpledb_lib
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(simpledb_tests)