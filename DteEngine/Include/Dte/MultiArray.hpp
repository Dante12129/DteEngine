#ifndef MULTIARRAY_HPP_INCLUDED
#define MULTIARRAY_HPP_INCLUDED

#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <vector>

namespace dte
{
    /** \addtogroup utils
     * \{
     */
    template <typename T>
    class MultiArray
    {
        public:
            MultiArray() = default;
            MultiArray(unsigned int cols, unsigned int rows) : m_rows(rows), m_columns(cols)
            {
                m_data.resize(rows * cols);
            }
            MultiArray(unsigned int cols, unsigned int rows, const T& def_fill) : m_rows(rows), m_columns(cols)
            {
                m_data.resize(rows * cols);
                std::fill(m_data.begin(), m_data.end(), def_fill);
            }
            MultiArray(std::initializer_list<T> init) : m_data(init) {}
            ~MultiArray() = default;

            std::size_t size() const { return m_data.size(); }
            std::size_t capacity() const { return m_data.capacity(); }
            std::size_t GetHeight() const { return m_rows; }
            std::size_t GetWidth() const { return m_columns; }

            void resize(std::size_t new_size) { m_data.resize(new_size); }

            void push_back(const T& object) { m_data.push_back(object); }

            T& operator() (unsigned int row, unsigned int col)
            {
                #ifdef DEBUGBUILD
                #ifdef DOUTPUT
                std::cout << "Accessing element " << row * m_columns + col << "in multimap" << std::endl;
                #endif // DOUTPUT
                #endif // DEBUGBUILD
                return m_data.at(row * m_columns + col);
            }
            T const& operator() (unsigned int row, unsigned int col) const
            {
                #ifdef DEBUGBUILD
                #ifdef DOUTPUT
                std::cout << "Accessing element " << row * m_columns + col << "in multimap" << std::endl;
                #endif // DOUTPUT
                #endif // DEBUGBUILD
                return m_data.at(row * m_columns + col);
            }
            T& operator() (unsigned int element_num)
            {
                #ifdef DEBUGBUILD
                #ifdef DOUTPUT
                std::cout << "Accessing element " << element_num << "in multimap" << std::endl;
                #endif // DOUTPUT
                #endif // DEBUGBUILD
                return m_data.at(element_num);
            }
            T const& operator() (unsigned int element_num) const
            {
                #ifdef DEBUGBUILD
                #ifdef DOUTPUT
                std::cout << "Accessing element " << element_num << "in multimap" << std::endl;
                #endif // DOUTPUT
                #endif // DEBUGBUILD
                return m_data.at(element_num);
            }

        private:
            std::vector<T> m_data;

            std::size_t m_rows, m_columns;
    };
    /** \} */
}

#endif // MULTIARRAY_HPP_INCLUDED
