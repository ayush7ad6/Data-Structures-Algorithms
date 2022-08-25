#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSumWithNoConsecutiveElements(vector<int> &nums, int n)
{
    if (n == 1)
        return nums[0];

    if (n == 2)
        return max(nums[0], nums[1]);
    int a = nums[n - 1] + maxSumWithNoConsecutiveElements(nums, n - 2);
    int b = maxSumWithNoConsecutiveElements(nums, n - 1);

    return max(a, b);
}

int maxSumWithNoConsecutiveElements(vector<int> &nums)
{
    int n = nums.size();
    int dp[n + 1];

    dp[1] = nums[0];
    dp[2] = max(nums[0], nums[1]);

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = INT_MIN;
        dp[i] = max(dp[i], max(nums[i] + dp[i - 2], dp[i - 1]));
    }

    return dp[n];
}
int main()
{
    vector<int> nums = {1, 10, 2};
    nums = {10, 5, 15, 20, 2, 30};
    nums = {8, 7, 6, 10};

    cout << maxSumWithNoConsecutiveElements(nums, 4) << endl;
    cout << maxSumWithNoConsecutiveElements(nums);
    return 0;
}