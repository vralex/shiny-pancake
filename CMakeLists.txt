cmake_minimum_required(VERSION 3.7.2)

project( shiny-pancake )
set(CMAKE_CXX_STANDART 14)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()