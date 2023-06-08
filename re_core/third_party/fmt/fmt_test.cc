#include <fmt/core.h>
#include <gtest/gtest.h>

namespace re {

TEST(FmtTest, TestFormat) {
  // SETUP / ACTION / VERIFICATION
  EXPECT_EQ(fmt::format("Hello, {}!", "World"), "Hello, World!");
}

}  // namespace re
