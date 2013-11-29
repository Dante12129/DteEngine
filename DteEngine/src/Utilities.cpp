#include "Dte/Utilities.hpp"

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "windows.h"

namespace dte
{
    void MinimizeWindow(const sf::RenderWindow& window)
    {
        #ifdef _WIN32
        ShowWindow(window.getSystemHandle(), SW_MINIMIZE);
        #else
        std::cerr << "Can't minimize on your system. Sorry."
        #endif
    }
    void MaximizeWindow(const sf::RenderWindow& window)
    {
        #ifdef _WIN32
        ShowWindow(window.getSystemHandle(), SW_MAXIMIZE);
        #else
        std::cerr << "Can't minimize on your system. Sorry."
        #endif
    }
}
