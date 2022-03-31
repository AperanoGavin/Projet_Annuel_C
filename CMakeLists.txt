cmake_minimum_required(VERSION 3.21)
project(project_annuel_C C)

set(CMAKE_C_STANDARD 99)
set( LIBRARY -lcurl)

add_executable(project_annuel_C  main.c)
