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

bool RectWindow::contains(const sf::Vector2f& point) const
{
    return m_shape.getGlobalBounds().contains(point);
}

bool RectWindow::contains(float x, float y) const
{
    return contains({x, y});
}

bool RectWindow::contains(int x, int y) const
{
    return contains(static_cast<float>(x), static_cast<float>(y));
}


void RectWindow::updateWindow() {

}

bool RectWindow::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    return false;
}

bool RectWindow::onClick(const sf::Event::MouseButtonEvent &event) {
    return false;
}
