#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int> &nums)
{
    int n = nums.size();
    int lis[n] = {0};

    lis[0] = 1;
    int maxLcs = 1;
    for (int i = 1; i < n; ++i)
    {
        // cout <<
        lis[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }

        maxLcs = max(maxLcs, lis[i]);
    }

    return maxLcs;
}
int ceilInd(vector<int> &nums, int f, int r, int x)
{
    int m;
    while (r > f)
    {
        m = f + (r - f) / 2;

        if (nums[m] >= x)
            r = m;
        else
            f = m + 1;
    }

    return r;
}
int lisBS(vector<int> &nums)
{
    vector<int> tail;
    int len = 1;
    tail.push_back(nums[0]);

    for (int i = 1; i < nums.size(); ++i)
    {
        cout << "i: " << nums[i] << endl;
        if (nums[i] > tail[len - 1])
        {
            tail.push_back(nums[i]);
            ++len;
        }
        else
        {
            int cInd = ceilInd(tail, 0, len - 1, nums[i]);
            cout << "Replacing " << nums[cInd] << " with " << nums[i] << endl;
            tail[cInd] = nums[i];
        }
        for (auto t : tail)
            cout << t << " ";
        cout << endl;
        cout << endl;
    }

    return len;
}
int main()
{
    vector<int> nums = {3, 4, 2, 8, 10, 5, 1};
    nums = {10, 5, 18, 7, 2, 9};
    nums = {4, 10, 6, 5, 8, 11, 2, 20};
    nums = {10, 20, 30};
    nums = {30, 20, 10};
    nums = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};

    cout << lis(nums) << " " << lisBS(nums);
    return 0;
}