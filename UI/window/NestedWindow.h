//
// Created by chere on 27.01.2024.
//

#ifndef NESTEDWINDOW_H
#define NESTEDWINDOW_H
#include "AbstractWindow.h"
#include "WindowManager.h"

class NestedWindow;

using nested_window_ptr = std::shared_ptr<NestedWindow>;
using nested_window_wptr = nested_window_ptr::weak_type;
using nested_window_container = std::list<nested_window_ptr>;

class NestedWindow : public AbstractWindow{
public:
    NestedWindow() = default;
    explicit NestedWindow(const nested_window_container& children);
    explicit NestedWindow(nested_window_container&& children);
    NestedWindow(const nested_window_container& children, const nested_window_wptr& parent);
    NestedWindow(nested_window_container && children, nested_window_wptr&& parent);

    void updateWindow() override;
    void draw(sf::RenderTarget& target) const override;
    bool onClick(const sf::Event::MouseButtonEvent& event) override;
    bool onMouseMove(const sf::Event::MouseMoveEvent& event) override;

    template<typename T>
    void setParent(T&& parent);
    const nested_window_wptr & getParent() const;

    void resetParent();

    template<typename T>
    void addWindow(T&& window);

    template<typename Container>
    void addWindows(Container&& window);

    void removeWindow(const nested_window_ptr & window);

    bool contains(const sf::Vector2f& point) const override = 0;
    bool contains(float x, float y) const override;
    bool contains(int x, int y) const override;

private:
    nested_window_container m_children{};
    nested_window_wptr m_parent{};
};

template <typename T>
void NestedWindow::setParent(T&& parent)
{
    m_parent = std::forward<T>(parent);
}

template <typename T>
void NestedWindow::addWindow(T&& window)
{
    window->setParent(nested_window_wptr(window));
    m_children.push_back(std::forward<T>(window));
}

template <typename Container>
void NestedWindow::addWindows(Container&& windows)
{
    for (auto & window : windows)
        window->setParent(nested_window_wptr(window));

    m_children.insert(m_children.end(), std::make_move_iterator(windows.begin()), std::make_move_iterator(windows.end()));
}


#endif //NESTEDWINDOW_H
