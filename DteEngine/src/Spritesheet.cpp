#include <iostream>
#include "Dte/Spritesheet.hpp"

namespace dte
{
    Spritesheet::Spritesheet() = default;
    Spritesheet::Spritesheet(std::string filename, sf::Vector2u image_dims, sf::Vector2u sprite_dims)
    {
        if(!m_texture.loadFromFile(filename))
            std::cerr << "Could not load image: " << filename << " for spritesheet." << std::endl;

        m_image_dimensions = image_dims; m_sprite_dimensions = sprite_dims;
        m_sprites_per_row = m_image_dimensions.x/m_sprite_dimensions.x; m_sprites_per_column = m_image_dimensions.y/m_sprite_dimensions.y; m_sprite_count = m_sprites_per_row*m_sprites_per_column;

        if(m_sprites_per_column == 1)
        {
            for(unsigned i = 0; i < m_sprites_per_row; i++)
            {
                m_rects.push_back(sf::IntRect(i*m_sprite_dimensions.x, 0, m_sprite_dimensions.x, m_sprite_dimensions.y));
            }
        }
        else if(m_sprites_per_row == 1)
        {
            for(unsigned i = 0; i < m_sprites_per_column; i++)
            {
                m_rects.push_back(sf::IntRect(0, i*m_sprite_dimensions.y, m_sprite_dimensions.x, m_sprite_dimensions.y));
            }
        }
        else
        {
            for(unsigned i = 0; i < m_sprites_per_column; i++)
            {
                for(unsigned j = 0; j < m_sprites_per_row; j++)
                {
                    m_rects.push_back(sf::IntRect(j*m_sprite_dimensions.x, i*m_sprite_dimensions.y, m_sprite_dimensions.x, m_sprite_dimensions.y));
                }
            }
        }
    }
    Spritesheet::~Spritesheet() = default;

    sf::Vector2u Spritesheet::GetImageDimensions() const { return m_image_dimensions; }
    sf::Vector2u Spritesheet::GetSpriteDimensions() const { return m_sprite_dimensions; }
    unsigned Spritesheet::GetPerRow() const { return m_sprites_per_row; }
    unsigned Spritesheet::GetPerCol() const { return m_sprites_per_column; };

    const sf::Texture& Spritesheet::GetTexture() const { return m_texture; }
    sf::IntRect Spritesheet::GetRect(unsigned row, unsigned col) const { return m_rects(row * m_sprites_per_row + col); }
    sf::IntRect Spritesheet::GetRect(unsigned rect_num) const { return m_rects(rect_num); }
}
