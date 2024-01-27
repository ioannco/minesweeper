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
            for (auto & window : m_windows)
                if (window->onClick(event.mouseButton))
                    return true;
            break;

        case sf::Event::MouseMoved: // OnMouseMove
            for (auto & window : m_windows)
                if (window->onMouseMove(event.mouseMove))
                    return true;
            break;

        default:
            return false;
    }

    return false;
}

void WindowManager::update() const {
    for (auto & window : m_windows) {
        window->update();
    }
}

void WindowManager::addWindow(abstract_window_ptr window) {
    m_windows.push_back(window);
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
