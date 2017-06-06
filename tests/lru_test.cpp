#include <lru.h>

#include <gmock/gmock.h>

#include <vector>
#include <utility>

namespace vralex {

TEST(LRU, Contains) {
    LRUCache<int, int> cache(4);
    std::vector<std::pair<int, int>> values = {
        {1, 5},
        {2, 6},
        {3, 7},
        {4, 8}
    };

    for (auto& value : values) {
        cache.put(value.first, value.second);
    }

    for (auto& value : values) {
        ASSERT_TRUE(cache.contains(value.first));
    }

    for (auto& value : values) {
        cache.put(value.second, value.first);
        ASSERT_FALSE(cache.contains(value.first));
    }
}

} // namespace vralex
