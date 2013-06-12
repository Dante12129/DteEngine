#ifndef MULTIARRAY_HPP_INCLUDED
#define MULTIARRAY_HPP_INCLUDED

#include <algorithm>
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
            MultiArray(unsigned int rows, unsigned int cols) : m_rows(rows), m_columns(cols)
            {
                m_data.resize(rows * cols);
            }
            MultiArray(unsigned int rows, unsigned int cols, const T& def_fill) : m_rows(rows), m_columns(cols)
            {
                m_data.resize(rows * cols);
                std::fill(m_data.begin(), m_data.end(), def_fill);
            }
            ~MultiArray() = default;

            std::size_t size() { return m_data.size(); }

            T& operator() (unsigned int row, unsigned int col)
            {
                return m_data.at(row * m_rows + col);
            }
            T const& operator() (unsigned int row, unsigned int col) const
            {
                return m_data.at(row * m_rows + col);
            }

        private:
            std::vector<T> m_data;

            std::size_t m_rows, m_columns;
    };
    /** \} */
}

#endif // MULTIARRAY_HPP_INCLUDED
