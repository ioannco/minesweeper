cmake_minimum_required(VERSION 3.27)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(MineSweeper main.cpp
        UI/AbstractWindow.h
        UI/RectWindow.cpp
        UI/RectWindow.h
        UI/CallbackButton.cpp
        UI/CallbackButton.h
        UI/WindowManager.cpp
        UI/WindowManager.h)

target_link_libraries(MineSweeper PRIVATE sfml-system sfml-network sfml-graphics sfml-window)