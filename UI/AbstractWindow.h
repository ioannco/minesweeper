//
// Created by chere on 26.01.2024.
//

#ifndef ABSTRACTWINDOW_H
#define ABSTRACTWINDOW_H

#include <SFML/Graphics.hpp>

/**
 * \brief Base interface class for all windows
 */
class AbstractWindow {
public:
    AbstractWindow() = default;
    virtual ~AbstractWindow() = default;
    virtual void updateWindow() = 0;
    virtual void draw(sf::RenderTarget & target) const = 0;
    virtual bool onClick(const sf::Event::MouseButtonEvent & event) = 0;
    virtual bool onMouseMove(const sf::Event::MouseMoveEvent &event) = 0;
    virtual bool contains(const sf::Vector2f & point) const = 0;
    virtual bool contains(float x, float y) const = 0;
    virtual bool contains(int x, int y) const = 0;
};

#endif //ABSTRACTWINDOW_H
