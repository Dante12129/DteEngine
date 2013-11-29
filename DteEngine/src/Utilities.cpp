#include "Dte/Utilities.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include "windows.h"

namespace dte
{
    void MinimizeWindow(const sf::RenderWindow& window) { ShowWindow(window.getSystemHandle(), SW_MINIMIZE); }
    void MaximizeWindow(const sf::RenderWindow& window) { ShowWindow(window.getSystemHandle(), SW_MAXIMIZE); }
}
