/*! \brief Heterogenous dynamic array class
 *
 * \file Array.h
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_ARRAY_H_INCLUDED
#define EGLI_ARRAY_H_INCLUDED

#include <vector>

#include "Exception.h"
#include "detail/Types.h"

namespace egli
{
class Array
{
public:

    /*! \brief Constructor
     */
    Array();

    /*! \brief Destructor
     */
    ~Array();

    /*! \brief Get the array size
     *
     * \return The array size
     */
    size_t size() const;

    /*! \brief Add a value at the end of the array
     *
     * \param value - the new value
     */
    template<typename T>
    void add(const T &value);

    /*! \brief Get the Type at index i
     *
     * \param i - index
     * \return The Type at index i
     *
     * \throw Exception if i >= size()
     */
    detail::Type typeOf(size_t i) const;

    /*! \brief Get the value at index i
     *
     * \param i - index
     * \return A constant reference to the value
     *
     * \throw Exception if typeOf(i) != T
     */
    template<typename T>
    const T &get(size_t i) const;

private:

    // Associate a void* with a Type
    struct Element
    {
        detail::Type type;
        void *ptr;
    };

    // data members
    std::vector<Element> elements;
};
} // namespace egli

template<typename T>
void egli::Array::add(const T &value)
{
    elements.push_back({
        detail::EnumValue<T>::value,
        static_cast<void*>(new T(value))});
}

template<typename T>
const T &egli::Array::get(size_t i) const
{
    if (typeOf(i) != detail::EnumValue<T>::value) // do the index check
        throw Exception("Bad type cast", "egli::Array::get<T>");

    return *static_cast<T*>(elements[i].ptr);
}

#endif // EGLI_ARRAY_H_INCLUDED