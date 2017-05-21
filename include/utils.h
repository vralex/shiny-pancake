#pragma once

#include <utility>

namespace vralex {

template <typename T>
struct less {
    bool operator()(const T& lhs, const T& rhs) const
    {
        return lhs < rhs;
    }
};

template <typename Iterator>
struct iterator_traits {
    typedef typename Iterator::value_type value_type;
};


template <typename BidirectionalIterator>
BidirectionalIterator prev(BidirectionalIterator iterator)
{
    return --iterator;
}

template <typename T>
void swap(T& lhs, T& rhs)
{
    // TODO: get rid of std::move
    auto temp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(temp);
}

template <typename ForwardIterator>
void iter_swap(ForwardIterator lhs, ForwardIterator rhs)
{
    swap(*lhs, *rhs);
}

} // namespace vralex
