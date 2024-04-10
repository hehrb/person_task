#include <gtest/gtest.h>
#include <vector>
#include "最大连续子数组和.cpp"

// 测试最大连续子数组和函数
TEST(MaxSubArrayTest, HandlesPositiveInput) 
{
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(maxSubArray(nums), 15);
}
TEST(MaxSubArrayTest, HandlesNegativeInput) 
{

    std::vector<int> nums = { -2, -3, -1, -5 };
    EXPECT_EQ(maxSubArray(nums), -1);
}

TEST(MaxSubArrayTest, HandlesMixedInput) 
{
    std::vector<int> nums = { 2, -1, 2, 3, 4, -5 };
    EXPECT_EQ(maxSubArray(nums), 10);
}

int main(int argc, char** argv) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
