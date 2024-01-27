//
// Created by chere on 26.01.2024.
//

#ifndef BUTTON_H
#define BUTTON_H
#include <functional>

#include "RectWindow.h"

using window_callback_t = std::function<bool (const sf::Event::MouseButtonEvent &)>;

/**
 * \brief Base class for all rectangle shaped buttons
 */
class CallbackButton : public RectWindow {
public:
    // Ctors

    CallbackButton(sf::RectangleShape shape, window_callback_t callback);
    CallbackButton(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Color& outlineColor, window_callback_t callback);

    // Events

private:
    bool onClick(const sf::Event::MouseButtonEvent &event) override;

public:

    // Getters and setters

    void setCallback(window_callback_t callback);

private:
    window_callback_t m_callback;
};



#endif //BUTTON_H
