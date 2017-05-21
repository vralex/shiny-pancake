#pragma once

#include <utils.h>

namespace sort {

template <
    typename BidirectionalIterator, 
    typename Compare = vralex::less<typename vralex::iterator_traits<BidirectionalIterator>::value_type>
>
void bubbleSort(
    BidirectionalIterator begin, 
    BidirectionalIterator end, 
    Compare compare = Compare())
{
    for (; begin != end; ++begin) {
        for (auto rhs = vralex::prev(end); rhs != begin; --rhs) {
            auto lhs = vralex::prev(rhs);
            if (compare(*rhs, *lhs)) {
                vralex::iter_swap(lhs, rhs);
            }
        }
    }
}


} // namespace sort
