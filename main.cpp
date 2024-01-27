#include <SFML/Graphics.hpp>
#include <iostream>

#include "UI/WindowManager.h"
#include "UI/CallbackButton.h"
#include "UI/SpriteWindow.h"

abstract_window_container constructLayout();

int main() {
    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "Mine Sweeper"};

    sf::Event event{};

    WindowManager wndManager(constructLayout());

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            wndManager.processEvent(event);
        }

        wndManager.update();

        wndManager.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}


abstract_window_container constructLayout() {
    auto callback = [](const sf::Event::MouseButtonEvent & event) {
        static int click_counter = 0;
        std::cout << "Click #" << click_counter << "!"  << std::endl;
        click_counter++;
        return true;
    };

    auto sampleButton = std::make_shared<CallbackButton>(
            sf::Vector2f{200.f, 200.f},
            sf::Vector2f{200.f, 150.f},
            sf::Color::Blue,
            sf::Color::Red,
            callback
            );

    static sf::Texture texture;
    texture.loadFromFile("../bomb.png");

    sf::Sprite bombSprite(texture);
    bombSprite.setPosition(200, 500);

    auto bombWindow = std::make_shared<SpriteWindow>(
            bombSprite
            );

    return {sampleButton, bombWindow};
}
