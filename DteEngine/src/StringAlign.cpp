#include "Dte/StringAlign.hpp"

namespace dte
{
    void CenterTextHor(sf::Text& message, const sf::RenderWindow& window)
    {
        sf::FloatRect message_bounds = message.getLocalBounds();
        message.setOrigin(message_bounds.left + (message_bounds.width/2), 0);
        message.setPosition(window.getSize().x/2, message.getPosition().y);
    }

    std::string getStringFromTime_T(time_t time_to_convert)
    {
        std::string temp;
        temp = ctime(&time_to_convert);
        temp = temp.substr(0, temp.length()-1);

        return temp;
    }
}
