#ifndef SPRITESHEET_HPP_INCLUDED
#define SPRITESHEET_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Dte/MultiArray.hpp"

namespace dte
{
    class Spritesheet : sf::NonCopyable
    {
        public:
            Spritesheet();
            Spritesheet(std::string filename, sf::Vector2u image_dims, sf::Vector2u sprite_dims);
            ~Spritesheet();

            sf::Vector2u GetImageDimensions() const;
            sf::Vector2u GetSpriteDimensions() const;
            unsigned int GetPerRow() const;
            unsigned int GetPerCol() const;

            const sf::Texture& GetTexture() const;
            sf::IntRect GetRect(unsigned int row, unsigned int col) const;
            sf::IntRect GetRect(unsigned int rect_num) const;

        private:
            sf::Texture m_texture;
            MultiArray<sf::IntRect> m_rects;

            sf::Vector2u m_image_dimensions;
            sf::Vector2u m_sprite_dimensions;

            unsigned int m_sprite_count, m_sprites_per_row, m_sprites_per_column;
    };
}

#endif // SPRITESHEET_HPP_INCLUDED
