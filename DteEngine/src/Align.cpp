#include "Dte/Align.hpp"

#include <SFML/Graphics.hpp>

namespace dte
{
    void CenterTextHor(sf::Text& message, const sf::RenderTarget& target)
    {
        sf::FloatRect message_bounds = message.getLocalBounds();
        message.setOrigin(message_bounds.left + (message_bounds.width/2.f), 0);
        message.setPosition(target.getSize().x/2.f, message.getPosition().y);
    }
    void CenterSpriteHor(sf::Sprite& sprite, const sf::RenderTarget& target)
    {
        sf::FloatRect sprite_bounds = sprite.getLocalBounds();
        sprite.setOrigin(sprite_bounds.left + (sprite_bounds.width/2.f), 0);
        sprite.setPosition(target.getSize().x/2.f, sprite.getPosition().y);
    }

    void CenterTextVert(sf::Text& message, const sf::RenderTarget& target)
    {
        sf::FloatRect message_bounds = message.getLocalBounds();
        message.setOrigin(0, message_bounds.top + (message_bounds.height/2.f));
        message.setPosition(message.getPosition().x, target.getSize().y/2.f);
    }
    void CenterSpriteVert(sf::Sprite& sprite, const sf::RenderTarget& target)
    {
        sf::FloatRect sprite_bounds = sprite.getLocalBounds();
        sprite.setOrigin(0, sprite_bounds.top + (sprite_bounds.height/2.f));
        sprite.setPosition(sprite.getPosition().x, target.getSize().y/2.f);
    }

    void CenterText(sf::Text& message, const sf::RenderTarget& target)
    {
        sf::FloatRect message_bounds = message.getLocalBounds();
        message.setOrigin(message_bounds.left + (message_bounds.width/2.0f), message_bounds.top + (message_bounds.height/2.0f));
        message.setPosition(sf::Vector2f(target.getSize() / (unsigned)2));
    }
    void CenterSprite(sf::Sprite& sprite, const sf::RenderTarget& target)
    {
        sf::FloatRect sprite_bounds = sprite.getLocalBounds();
        sprite.setOrigin(sprite_bounds.left + (sprite_bounds.width/2.0f), sprite_bounds.top + (sprite_bounds.height/2.0f));
        sprite.setPosition(sf::Vector2f(target.getSize() / (unsigned)2));
    }
}
