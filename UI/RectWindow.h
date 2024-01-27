//
// Created by chere on 26.01.2024.
//

#ifndef RECTWINDOW_H
#define RECTWINDOW_H
#include "AbstractWindow.h"

/**
* Base class for all rectange shaped windows
*/
class RectWindow : public AbstractWindow {
public:
    // Ctors

    RectWindow() = default;
    explicit RectWindow(sf::RectangleShape shape);
    RectWindow(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Color& outlineColor);

    // Update members

    void draw(sf::RenderTarget& target) const override;
    void update() override;

    // Event handling

    bool onMouseMove(const sf::Event::MouseMoveEvent &event) override;
    bool onClick(const sf::Event::MouseButtonEvent &event) override;

public:

    // Getters and setters

    sf::RectangleShape getShape() const;
    void setShape(sf::RectangleShape shape);

private:
    sf::RectangleShape m_shape{};
};



#endif //RECTWINDOW_H
