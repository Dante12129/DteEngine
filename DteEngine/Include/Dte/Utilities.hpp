#ifndef UTILITIES_HPP_INCLUDED
#define UTILITIES_HPP_INCLUDED

#include <memory>
#include <type_traits>
#include <utility>
#include <SFML/Config.hpp>

namespace sf { class RenderWindow; }

namespace dte
{
    void MinimizeWindow(const sf::RenderWindow& window);
    void MaximizeWindow(const sf::RenderWindow& window);

    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique_helper(std::false_type, Args&&... args)
    {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }

    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique_helper(std::true_type, Args&&... args)
    {
        static_assert(std::extent<T>::value == 0,
        "make_unique<T[N]>() is forbidden, please use make_unique<T[]>().");

        typedef typename std::remove_extent<T>::type U;
        return std::unique_ptr<T>(new U[sizeof...(Args)]{std::forward<Args>(args)...});
    }

    template <typename T, typename... Args>
    std::unique_ptr<T> make_unique(Args&&... args)
    {
        return make_unique_helper<T>(std::is_array<T>(), std::forward<Args>(args)...);
    }

    template <class T>
    void setTransparency(T& colorable, sf::Uint8 a)
    {
        colorable.setColor({colorable.getColor().r, colorable.getColor().g, colorable.getColor().b, a});
    }
    template <class T>
    void setShapeTransparency(T& colorable, sf::Uint8 a)
    {
        colorable.setFillColor({colorable.getFillColor().r, colorable.getFillColor().g, colorable.getFillColor().b, a});
    }
}

#endif // UTILITIES_HPP_INCLUDED
