//
// Created by chere on 26.01.2024.
//

#include "Button.h"

Button::Button(sf::RectangleShape shape, window_callback_t callback) :
    RectWindow(std::move(shape)),
    m_callback(std::move(callback))
{
}

Button::Button(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& fillColor,
    const sf::Color& outlineColor, window_callback_t callback) :
    RectWindow(pos, size, fillColor, outlineColor),
    m_callback(std::move(callback))
{

}

void Button::setCallback(window_callback_t callback)
{
    m_callback = std::move(callback);
}

bool Button::onClick(const sf::Event::MouseButtonEvent &event) {
    auto globalBounds = getShape().getGlobalBounds();
    sf::Vector2f mousePos{static_cast<float>(event.x), static_cast<float>(event.y)};

    if (globalBounds.contains(mousePos)) {
        return m_callback(event);
    }

    return false;
}
