#include <iterable.h>

#include <gmock/gmock.h>

#include <vector>

namespace vralex {

TEST(TIterator, TIteratorCompileTest) {
    std::vector<int> vector;
    TIterator<int> vectorBegin(vector.begin());
}

} // namespace vralex
