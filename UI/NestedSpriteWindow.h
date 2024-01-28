//
// Created by chere on 28.01.2024.
//

#ifndef NESTEDSPRITEWINDOW_H
#define NESTEDSPRITEWINDOW_H
#include <SFML/Graphics/Sprite.hpp>

#include "NestedWindow.h"


class NestedSpriteWindow : public sf::Sprite, public NestedWindow {
public:
    explicit NestedSpriteWindow(const sf::Texture & texture);

    void draw(sf::RenderTarget& target) const override;
    bool contains(const sf::Vector2f& point) const override;
};



#endif //NESTEDSPRITEWINDOW_H
