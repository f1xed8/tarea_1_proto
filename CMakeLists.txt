cmake_minimum_required(VERSION 3.28)
project(tarea_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(tarea_1
        emisor.cpp
        receptor.cpp
        protocolo.h
        funciones.cpp
        funciones.h)
