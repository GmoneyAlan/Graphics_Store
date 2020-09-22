cmake_minimum_required(VERSION 3.17)
project(Graphics_Store C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Graphics_Store
        login.c
        login.h
        product.c
        product.h
        main.c
)
