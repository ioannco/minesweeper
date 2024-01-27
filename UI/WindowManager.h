//
// Created by chere on 26.01.2024.
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#include <queue>

#include "AbstractWindow.h"

using abstract_window_ptr = std::shared_ptr<AbstractWindow>;
using abstract_window_container = std::deque<abstract_window_ptr>;

class WindowManager {
public:
    WindowManager() = default;
    explicit WindowManager(const abstract_window_container & container);
    explicit WindowManager(abstract_window_container && container) noexcept;

    bool processEvent(const sf::Event & event);
    void update() const;

    void addWindow(abstract_window_ptr window);
    void removeWindow(const abstract_window_ptr & window);

    template <typename Container>
    void addAll(const Container & windows);

private:
    abstract_window_container m_windows;
};



#endif //WINDOWMANAGER_H