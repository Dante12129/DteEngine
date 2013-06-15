#ifndef STRINGALIGN_HPP_INCLUDED
#define STRINGALIGN_HPP_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

namespace dte
{
    void CenterTextHor(sf::Text& message, const sf::RenderWindow& window);
    std::string getStringFromTime_T(time_t time_to_convert);
}

#endif // STRINGALIGN_HPP_INCLUDED
