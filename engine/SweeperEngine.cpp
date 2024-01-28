//
// Created by chere on 27.01.2024.
//

#include "SweeperEngine.h"

#include "../UI/NestedSpriteWindow.h"
#include "../UI/SpriteWindow.h"

SweeperEngine::SweeperEngine() :
    m_game_window(sf::VideoMode{1920, 1080}, "Mine Sweeper")
{
    m_ui.setFillColor(sf::Color::White);
    m_ui.setSize({1920.f, 1080.f});
}

SweeperEngine::SweeperEngine(unsigned int windowWidth, unsigned int windowHeight, const std::string& title) :
    m_game_window(sf::VideoMode{windowWidth, windowHeight}, title)
{
    m_ui.setFillColor(sf::Color::White);
    m_ui.setSize({static_cast<float>(windowWidth), static_cast<float>(windowHeight)});
}

void SweeperEngine::run()
{
    m_ui.addWindows(generateLayout());

    sf::Event event{};

    while (m_game_window.isOpen())
    {
        while (m_game_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_game_window.close();
                break;

            case sf::Event::MouseButtonReleased:
                m_ui.onClick(event.mouseButton);
                break;

            case sf::Event::MouseMoved:
                m_ui.onMouseMove(event.mouseMove);
                break;

            default:
                break;
            }
        }

        m_ui.updateWindow();

        m_game_window.clear();
        m_ui.draw(m_game_window);
        m_game_window.display();
    }
}

nested_window_container SweeperEngine::generateLayout()
{
    auto sampleWindow1 = std::make_shared<RectNestedWindow>();
    sampleWindow1->setFillColor(sf::Color::Red);
    sampleWindow1->setSize({200.f, 150.f});
    sampleWindow1->setPosition(100.f, 100.f);

    auto sampleWindow2 = std::make_shared<RectNestedWindow>();
    sampleWindow2->setFillColor(sf::Color::Blue);
    sampleWindow2->setSize({200.f, 150.f});
    sampleWindow2->setPosition(300.f, 300.f);

    static sf::Texture bombTexture;
    bombTexture.loadFromFile("../bomb.png");

    auto sampleSpriteWindow = std::make_shared<NestedSpriteWindow>(bombTexture);
    sampleSpriteWindow->setPosition(500, 500);

    return {sampleWindow1, sampleWindow2, sampleSpriteWindow};
}
