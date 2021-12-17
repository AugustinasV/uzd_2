cmake_minimum_required(VERSION 2.6)
project(v2.0)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(executeTests v2test.cpp)
add_executable(executeTimeTests v15.cpp)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(executeTimeTests)

