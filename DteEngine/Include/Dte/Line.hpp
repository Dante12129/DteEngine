#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

#include <utility>
#include <SFML/Graphics.hpp>

namespace dte
{
    class Line : public sf::Drawable
    {
        public:
            typedef std::pair<sf::Vector2f, sf::Vector2f> Two_Points;
        public:
            Line();
            Line(Two_Points points, sf::Color color = sf::Color::Black);
            Line(sf::Vector2f point_one, sf::Vector2f point_two, sf::Color color = sf::Color::Black);
            ~Line();

            void draw(sf::RenderTarget &target, sf::RenderStates states) const;

        private:
            Two_Points m_points;
            sf::RectangleShape m_line;
    };
}

#endif // LINE_HPP_INCLUDED
