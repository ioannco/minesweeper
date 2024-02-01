//
// Created by chere on 27.01.2024.
//

#ifndef MINESWEEPER_SWEEPERENGINE_H
#define MINESWEEPER_SWEEPERENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../UI/window/WindowManager.h"
#include "../UI/window/RectNestedWindow.h"

class SweeperEngine {
public:
    SweeperEngine();
    SweeperEngine(unsigned int windowWidth, unsigned int windowHeight, const std::string& title);

    void run();
    static nested_window_container generateLayout();

private:
    sf::RenderWindow m_game_window;
    WindowManager m_window_manager;
    RectNestedWindow m_ui;
};


#endif //MINESWEEPER_SWEEPERENGINE_H
