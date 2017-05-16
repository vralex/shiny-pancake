#include <mock/header.h>

#include <gmock/gmock.h>

namespace mock {

TEST(SimpleTest, ItJustWorks) {
    EXPECT_EQ(42, calculateMainAnswer());
}

} // namespace mock