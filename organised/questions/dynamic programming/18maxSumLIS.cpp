#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSumLIS(vector<int> &nums)
{
    int n = nums.size();

    int lis[n] = {0};

    lis[0] = nums[0];
    int maxSum = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        lis[i] = nums[i];
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                lis[i] = max(lis[i], lis[j] + nums[i]);
            }
        }
        maxSum = max(maxSum, lis[i]);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {3, 20, 4, 6, 7, 30};
    nums = {5, 10, 20};
    nums = {20, 10, 5};

    cout << "LIS with max sum: " << maxSumLIS(nums);
    return 0;
}