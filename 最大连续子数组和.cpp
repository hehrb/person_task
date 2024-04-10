#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 最大连续子数组和
int maxSubArray(vector<int>& nums) 
{
    int pre = 0, res = nums[0];
    for (int x : nums)
    {
        pre = max(pre + x, x);
        res = max(res, pre);
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    cout << maxSubArray(nums) << endl;

    return 0;
}