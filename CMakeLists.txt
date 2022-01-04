cmake_minimum_required(VERSION 3.21)
project(untitled C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -pedantic-errors -Wall -Wextra ") # -Werror

add_executable(untitled main.c list.h list.c)
