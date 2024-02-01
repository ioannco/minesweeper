cmake_minimum_required(VERSION 3.27)
project(MineSweeper)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(MineSweeper main.cpp
        UI/window/AbstractWindow.h
        UI/window/RectWindow.cpp
        UI/window/RectWindow.h
        UI/window/CallbackButton.cpp
        UI/window/CallbackButton.h
        UI/window/WindowManager.cpp
        UI/window/WindowManager.h
        UI/window/SpriteWindow.h
        UI/window/SpriteWindow.cpp
        engine/SweeperEngine.cpp
        engine/SweeperEngine.h
        UI/window/NestedWindow.cpp
        UI/window/NestedWindow.h
        UI/window/RectNestedWindow.cpp
        UI/window/RectNestedWindow.h
        UI/window/NestedSpriteWindow.cpp
        UI/window/NestedSpriteWindow.h
        UI/editor/UIFactory.h
        UI/editor/UIFactory.cpp
)

target_link_libraries(MineSweeper PRIVATE sfml-system sfml-network sfml-graphics sfml-window)