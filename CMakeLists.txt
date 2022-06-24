cmake_minimum_required(VERSION 3.21)
project(Cube3D C)

set(CMAKE_C_STANDARD 99)

add_executable(Cube3D src/main.c src/utils.c includes/cub3d.h src/parsing.c)
