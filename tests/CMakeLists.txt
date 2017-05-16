cmake_minimum_required(VERSION 3.7.2)

project( test )
set(CMAKE_CXX_STANDART 14)

include_directories(../include googletest/googlemock/include googletest/googletest/include)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)

file(GLOB_RECURSE test_sources "*.cpp")
add_executable(unit_tests ${test_sources})
target_link_libraries(unit_tests gtest_main pancake)
