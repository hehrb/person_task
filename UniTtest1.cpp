#include <gtest/gtest.h>
#include <vector>
#include "��������������.cpp"

// �����������������ͺ���
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
