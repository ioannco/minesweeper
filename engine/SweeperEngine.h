//
// Created by chere on 27.01.2024.
//

#ifndef MINESWEEPER_SWEEPERENGINE_H
#define MINESWEEPER_SWEEPERENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../UI/WindowManager.h"

class SweeperEngine {
public:
    SweeperEngine();
    SweeperEngine(unsigned int windowWidth, unsigned int windowHeight, const std::string& title);

    void run();

private:
    sf::RenderWindow m_game_window;
    WindowManager m_window_manager;
};


#endif //MINESWEEPER_SWEEPERENGINE_H
