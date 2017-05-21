cmake_minimum_required(VERSION 3.7.2)

project( shiny-pancake )

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_REQUIRED TRUE)

include_directories(include /usr/include/c++/6)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()
