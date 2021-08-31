cmake_minimum_required(VERSION 3.20)
project(Advanced_Programming C)

set(CMAKE_C_STANDARD 11)

include_directories(..)
include_directories(".")

add_executable(Advanced_Programming
        "funciones.h"
        "main.c"
        ../Vector.h)
