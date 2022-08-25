#include <iostream>
#include <vector>

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

    return nums.size() - maxLcs;
}

int main()
{
    vector<int> nums = {5, 10, 3, 6, 7, 8};

    cout << " Number of elements to remove to make the array sorted is: ";
    cout << lis(nums) << endl;
    return 0;
}