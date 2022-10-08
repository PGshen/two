cmake_minimum_required(VERSION 3.23)
project(two)

set(CMAKE_C_STANDARD 99)

ADD_SUBDIRECTORY(list)

add_executable(two main.c test.h test.c)
