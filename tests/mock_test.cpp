#include <mock/header.h>

#include <gmock/gmock.h>

#include <memory>
#include <string>

namespace mock {

TEST(SimpleTest, ItJustWorks) {
    EXPECT_EQ(42, calculateMainAnswer());
    auto s = std::make_shared<std::string>("Hello world");
}

} // namespace mock
