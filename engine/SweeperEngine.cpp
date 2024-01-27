//
// Created by chere on 27.01.2024.
//

#include "SweeperEngine.h"

SweeperEngine::SweeperEngine() :
    m_game_window(sf::VideoMode{1920, 1080}, "Mine Sweeper")
{
}

SweeperEngine::SweeperEngine(unsigned int windowWidth, unsigned int windowHeight, const std::string& title) :
    m_game_window(sf::VideoMode{windowWidth, windowHeight}, title)
{
}

void SweeperEngine::run()
{
    sf::Event event{};

    while (m_game_window.isOpen())
    {
        while (m_game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_game_window.close();

            m_window_manager.processEvent(event);
        }

        m_game_window.clear();
        m_window_manager.draw(m_game_window);
        m_game_window.display();
    }
}
