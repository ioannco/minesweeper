//
// Created by chere on 28.01.2024.
//

#include "RectNestedWindow.h"

void RectNestedWindow::draw(sf::RenderTarget& target) const
{
    target.draw(*this);
    NestedWindow::draw(target);
}

bool RectNestedWindow::contains(const sf::Vector2f& point) const
{
    return getGlobalBounds().contains(point.x, point.y);
}

bool RectNestedWindow::contains(float x, float y) const
{
    return contains({x, y});
}

bool RectNestedWindow::contains(int x, int y) const
{
    return contains(static_cast<float>(x), static_cast<float>(y));
}
