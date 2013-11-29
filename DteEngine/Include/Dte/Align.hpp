#ifndef STRINGALIGN_HPP_INCLUDED
#define STRINGALIGN_HPP_INCLUDED

namespace sf { class Text; class RenderTarget; class Sprite; }

namespace dte
{
    void CenterTextHor(sf::Text& message, const sf::RenderTarget& window);
    void CenterSpriteHor(sf::Sprite& sprite, const sf::RenderTarget& target);

    void CenterTextVert(sf::Text& message, const sf::RenderTarget& target);
    void CenterSpriteVert(sf::Sprite& sprite, const sf::RenderTarget& target);

    void CenterText(sf::Text& message, const sf::RenderTarget& target);
    void CenterSprite(sf::Sprite& sprite, const sf::RenderTarget& target);
}

#endif // STRINGALIGN_HPP_INCLUDED
