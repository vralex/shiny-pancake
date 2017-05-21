#include <sort/sort.h>

#include <gmock/gmock.h>

#include <algorithm>
#include <vector>


TEST(BubbleSort, CompareToStdSort) {
    std::vector<int> sortedByStdSort = {1, 10, 2, 4, 15, 5, 1, -1, 2};
    auto sortedByCustomSort = sortedByStdSort;
    std::sort(sortedByStdSort.begin(), sortedByStdSort.end());
    sort::bubbleSort(sortedByCustomSort.begin(), sortedByCustomSort.end());
    EXPECT_EQ(sortedByStdSort, sortedByCustomSort);
}

