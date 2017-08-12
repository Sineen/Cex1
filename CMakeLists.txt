cmake_minimum_required(VERSION 3.6)
project(ex1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES ex1.c ex1.h)

add_executable(ex1 ${SOURCE_FILES})