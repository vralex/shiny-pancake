cmake_minimum_required(VERSION 3.7.2)

project( pancake )

include_directories(../include)

file(GLOB_RECURSE sources *.h *.cpp ../include/*.h)

add_library(pancake SHARED ${sources})
