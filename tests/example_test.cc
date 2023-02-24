#include <gtest/gtest.h>

#undef ASSERT_FALSE
#undef ASSERT_ALL

TEST(ExampleTest, BasicAssertions) {
    EXPECT_TRUE(2 == 2);
}

