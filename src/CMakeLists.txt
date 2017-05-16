cmake_minimum_required(VERSION 3.7.2)

project( pancake )
set(CMAKE_CXX_STANDART 14)

include_directories(../include)

file(GLOB_RECURSE sources *.h *.cpp)

add_library(pancake SHARED ${sources})