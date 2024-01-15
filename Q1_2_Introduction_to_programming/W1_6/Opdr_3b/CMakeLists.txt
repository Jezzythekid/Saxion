cmake_minimum_required(VERSION 3.26)
project(Opdr_3b C)

set(CMAKE_C_STANDARD 11)

add_executable(Opdr_3b main.c
        functions.h
        functions.c
        DateFunctions.h
        DateFunctions.c)
