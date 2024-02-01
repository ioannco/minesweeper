//
// Created by chere on 27.01.2024.
//

#include "NestedWindow.h"

NestedWindow::NestedWindow(const nested_window_container& children) :
    m_children(children)
{
}

NestedWindow::NestedWindow(nested_window_container&& children) :
    m_children(std::move(children))
{
}

NestedWindow::NestedWindow(const nested_window_container& children, const nested_window_wptr& parent) :
    m_children(children),
    m_parent(parent)
{
}

NestedWindow::NestedWindow(nested_window_container&& children, nested_window_wptr&& parent) :
    m_children(std::move(children)),
    m_parent(std::move(parent))
{
}

void NestedWindow::updateWindow()
{
    for (const auto & child : m_children)
        child->updateWindow();
}

void NestedWindow::draw(sf::RenderTarget& target) const
{
    for (const auto & child : m_children)
        child->draw(target);
}

bool NestedWindow::onClick(const sf::Event::MouseButtonEvent& event)
{
    return std::any_of(m_children.begin(), m_children.end(),
        [event](const nested_window_ptr & window)
        {
            return window->contains(event.x, event.y) && window->onClick(event);
        });
}

bool NestedWindow::onMouseMove(const sf::Event::MouseMoveEvent& event)
{
    return std::any_of(m_children.begin(), m_children.end(),
        [event](const nested_window_ptr & window)
        {
            return window->contains(event.x, event.y) && window->onMouseMove(event);
        });
}

const nested_window_wptr& NestedWindow::getParent() const
{
    return m_parent;
}

void NestedWindow::resetParent()
{
    m_parent.reset();
}

void NestedWindow::removeWindow(const nested_window_ptr& window)
{
    window->resetParent();
    m_children.erase(std::find(m_children.begin(), m_children.end(), window));
}


bool NestedWindow::contains(float x, float y) const
{
    return contains({x, y});
}

bool NestedWindow::contains(int x, int y) const
{
    return contains(static_cast<float>(x), static_cast<float>(y));
}
