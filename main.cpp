#include <SFML/Graphics.hpp>
#include <iostream>

#include "engine/SweeperEngine.h"
#include "UI/WindowManager.h"
#include "UI/CallbackButton.h"
#include "UI/SpriteWindow.h"

abstract_window_container constructLayout();

int main()
{
    SweeperEngine().run();
}

