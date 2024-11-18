cmake_minimum_required(VERSION 3.29)
project(proyect)

set(CMAKE_CXX_STANDARD 20)

add_executable(proyect main.cpp
        modules/CTable.cpp
        modules/CTable.h
        modules/util.cpp
        modules/util.h
        modules/control-game.cpp
        modules/control-game.h
        modules/menu.h
        modules/estadisticas.h
        modules/estadisticas.cpp)
