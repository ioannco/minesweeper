//
// Created by chere on 27.01.2024.
//

#ifndef MINESWEEPER_SPRITEWINDOW_H
#define MINESWEEPER_SPRITEWINDOW_H


#include "AbstractWindow.h"

class SpriteWindow : public AbstractWindow {
public:
    explicit SpriteWindow(sf::Sprite sprite);

    void update() override;
    void draw(sf::RenderTarget &target) const override;
    bool onClick(const sf::Event::MouseButtonEvent &event) override;
    bool onMouseMove(const sf::Event::MouseMoveEvent &event) override;

    const sf::Sprite &getSprite() const;
    void setSprite(const sf::Sprite &mSprite);

private:
    sf::Sprite m_sprite;
};


#endif //MINESWEEPER_SPRITEWINDOW_H
