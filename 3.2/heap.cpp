// =================================================================
//
// File: heap.cpp
// Author: Sergio Augusto Macías Corona
// ID: A01352038
// Date:
//
// =================================================================
#include "heap.h"
template <class T>
Heap<T>::Heap(const Heap<T> &other) : elements(other.elements){};
template <class T>
unsigned int Heap<T>::get_parent(unsigned int position) const
{
    return (position - 1) / 2;
}
template <class T>
unsigned int Heap<T>::get_left_leaf(unsigned int position) const
{
    return (position * 2) + 1;
}
template <class T>
unsigned int Heap<T>::get_right_leaf(unsigned int position) const
{
    return (position * 2) + 2;
}
template <class T>
T Heap<T>::get_size() const { return elements.size(); }
template <class T>
T Heap<T>::get_top() const
{
    if (is_empty())
        return INT_MAX;

    return elements[0];
}
template <class T>
void Heap<T>::swap(unsigned int first, unsigned int second)
{
    T temporal = elements[first];
    elements[first] = elements[second];
    elements[second] = temporal;
}

template <class T>
void Heap<T>::push_up(unsigned int position)
{
    unsigned int left_leaf = get_left_leaf(position),
                 right_leaf = get_right_leaf(position),
                 smallest_value = position;

    if (left_leaf < elements.size() &&
        elements[left_leaf] > elements[position])
        smallest_value = left_leaf;

    if (right_leaf < elements.size() &&
        elements[right_leaf] > elements[position])
        smallest_value = right_leaf;

    if (position != smallest_value)
    {
        swap(position, smallest_value);
        push_up(smallest_value);
    }
}

// Public Functions
/**
 * @brief
 * Returns if the heap is empty or not.
 * @tparam T      Class allowed data types.
 * @return true   if the heap is empty,
 * @return false  otherwise
 * @complexity    O(1)
 */
template <class T>
bool Heap<T>::is_empty() const
{
    return elements.empty();
}

/**
 * @brief
 * Adds an element to the heap. It's first inserted as the last element of the
 * vector. Then, it's verified if the new value is less significant that its
 * father element. If the condition is true, the values are exchanged.
 * @tparam T         Class allowed data types.
 * @param value      Value to be inserted in the heap structure.
 * @complexity       O(log(n))
 */
template <class T>
void Heap<T>::push(T value)
{
    elements.push_back(value);
    unsigned int position = elements.size() - 1;

    while (position > 0 && value > elements[get_parent(position)])
    {
        swap(position, get_parent(position));
        position = get_parent(position);
    }
}

/**
 * @brief
 * Pops the most significant element from the heap structure.
 * @tparam T     Class allowed data types.
 * @complexity   O(log(n))
 */
template <class T>
void Heap<T>::pop()
{
    if (is_empty())
        return;

    elements[0] = elements[elements.size() - 1];
    elements.pop_back();
    push_up(0);
}

/**
 * @brief
 * Auxiliary function. Shows the elements from the heap structure as strings.
 * @tparam T           Class allowed data types.
 * @return stream with all the values shown as strings.
 * @complexity          O(n)
 */
template <class T>
std::string Heap<T>::heap_elements() const
{
    std::stringstream heap_data;

    for (const auto &elem : elements)
        heap_data << elem << " ";

    return heap_data.str();
}