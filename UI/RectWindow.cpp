//
// Created by chere on 26.01.2024.
//

#include "RectWindow.h"

RectWindow::RectWindow(sf::RectangleShape shape) :
    m_shape(std::move(shape))
{
}

RectWindow::RectWindow(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& fillColor,
    const sf::Color& outlineColor)
{
    m_shape.setPosition(pos);
    m_shape.setSize(size);
    m_shape.setFillColor(fillColor);
    m_shape.setOutlineColor(outlineColor);
}

void RectWindow::draw(sf::RenderTarget& target) const
{
    target.draw(m_shape);
}

sf::RectangleShape RectWindow::getShape() const
{
    return m_shape;
}

void RectWindow::setShape(sf::RectangleShape shape)
{
    m_shape = std::move(shape);
}

void RectWindow::update() {

}

bool RectWindow::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    return false;
}

bool RectWindow::onClick(const sf::Event::MouseButtonEvent &event) {
    return false;
}
