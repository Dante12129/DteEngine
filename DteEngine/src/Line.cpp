#include <Dte/Line.hpp>

namespace dte
{
    Line::Line() = default;
    Line::Line(Two_Points points, sf::Color color) : m_points(points), m_line(points.first - points.second) { m_line.setFillColor(color); }
    Line::Line(sf::Vector2f point_one, sf::Vector2f point_two, sf::Color color) : m_points(std::make_pair(point_one, point_two)), m_line(point_one - point_two) { m_line.setFillColor(color); }
    Line::~Line() = default;

    void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(m_line, states);
    }
}
