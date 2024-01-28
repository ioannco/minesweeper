//
// Created by chere on 26.01.2024.
//

#include "WindowManager.h"

WindowManager::WindowManager(const abstract_window_container& container) :
    m_windows(container)
{
}

WindowManager::WindowManager(abstract_window_container&& container) noexcept :
    m_windows(std::move(container))
{
}

bool WindowManager::processEvent(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::MouseButtonReleased: // OnClick
            return std::any_of(m_windows.begin(), m_windows.end(),
                [event](const abstract_window_ptr & window)
                {
                    return window->contains(event.mouseButton.x, event.mouseButton.y) && window->onClick(event.mouseButton);
                }
                );

        case sf::Event::MouseMoved: // OnMouseMove
            return std::any_of(m_windows.begin(), m_windows.end(),
                [event](const abstract_window_ptr & window)
                {
                    return window->contains(event.mouseMove.x, event.mouseMove.y) && window->onMouseMove(event.mouseMove);
                }
                );

        default:
            return false;
    }
}

void WindowManager::update() const {
    for (auto & window : m_windows) {
        window->updateWindow();
    }
}

void WindowManager::addWindow(abstract_window_ptr window) {
    m_windows.push_back(std::move(window));
}

void WindowManager::removeWindow(const abstract_window_ptr &window) {
    m_windows.erase(std::find(m_windows.begin(), m_windows.end(), window));
}

void WindowManager::draw(sf::RenderTarget &target) const {
    for (auto & window : m_windows)
        window->draw(target);
}

template<typename Container>
void WindowManager::addAll(const Container &windows) {
    m_windows.insert(m_windows.end(), windows.begin(), windows.end());
}
