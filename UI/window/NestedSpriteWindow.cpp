//
// Created by chere on 28.01.2024.
//

#include "NestedSpriteWindow.h"

NestedSpriteWindow::NestedSpriteWindow(const sf::Texture& texture) :
    Sprite(texture)
{

}

void NestedSpriteWindow::draw(sf::RenderTarget& target) const
{
    target.draw(*this);
    NestedWindow::draw(target);
}

bool NestedSpriteWindow::contains(const sf::Vector2f& point) const
{
    return getGlobalBounds().contains(point);
}
