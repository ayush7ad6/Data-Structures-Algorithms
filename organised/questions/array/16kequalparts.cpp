/*
    check array can be divided into three equal parts
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <numeric>

using namespace std;

int threeEqualParts(vector<int> nums)
{
    for (int i = 1; i < nums.size(); ++i)
    {
        nums[i] += nums[i - 1];
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        int first = nums[i];
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[nums.size() - 1] - nums[j] == first && nums[j] - nums[i] == first)
            {
                cout << first;
                return true;
            }
        }
    }

    return false;
}

int threeEqualPartsII(vector<int> nums)
{
    int sum = 0;
    sum = accumulate(nums.begin(), nums.end(), sum);

    if (sum % 3)
        return false;

    int x = -1, y = -1;

    sum = sum / 3;
    int prefix = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        prefix += nums[i];

        if (prefix == sum && x == -1)
            x = i;

        if (prefix == (sum + sum) && x != -1)
            y = i;
    }

    if (x != -1 && y != -1)
        return true;

    return false;
}

int main()
{
    vector<int> arr = {5, 2, 6, 1, 1, 1, 5};

    cout << threeEqualPartsII(arr);
    return 0;
}