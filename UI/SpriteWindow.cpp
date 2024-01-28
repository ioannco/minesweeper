//
// Created by chere on 27.01.2024.
//

#include "SpriteWindow.h"

#include <utility>

void SpriteWindow::updateWindow() {
    // Do nothing
}

void SpriteWindow::draw(sf::RenderTarget &target) const {
    target.draw(m_sprite);
}

bool SpriteWindow::onClick(const sf::Event::MouseButtonEvent &event) {
    return false;
}

bool SpriteWindow::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    return false;
}

SpriteWindow::SpriteWindow(sf::Sprite sprite) :
    m_sprite(std::move(sprite))
{

}

const sf::Sprite &SpriteWindow::getSprite() const {
    return m_sprite;
}

void SpriteWindow::setSprite(const sf::Sprite &mSprite) {
    m_sprite = mSprite;
}
