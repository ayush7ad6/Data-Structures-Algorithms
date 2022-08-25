#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int searchInSorted(vector<int> &nums, int val)
{
    //     int first = nums[0];
    //     int second = nums[nums.size() - 1];
    int f = 0,
        r = nums.size() - 1;
    int mid;

    while (f <= r)
    {
        mid = (f + r) / 2;
        if (nums[mid] == val)
            return mid;
        // cout << mid << " ";
        if (nums[f] < nums[mid])
        {
            if (nums[f] <= val && val < nums[mid])
                r = mid - 1;
            else
                f = mid + 1;
        }
        else
        {
            if (nums[r] >= val && nums[mid] < val)
                f = mid + 1;
            else
                r = mid - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {10, 20, 40, 60, 5, 8};

    cout << searchInSorted(arr, 8);
    return 0;
}