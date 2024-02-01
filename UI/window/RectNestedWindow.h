//
// Created by chere on 28.01.2024.
//

#ifndef RECTNESTEDWINDOW_H
#define RECTNESTEDWINDOW_H
#include "NestedWindow.h"


class RectNestedWindow : public sf::RectangleShape, public NestedWindow {
public:

    void draw(sf::RenderTarget& target) const override;
    bool contains(const sf::Vector2f& point) const override;
    bool contains(float x, float y) const override;
    bool contains(int x, int y) const override;
};



#endif //RECTNESTEDWINDOW_H
