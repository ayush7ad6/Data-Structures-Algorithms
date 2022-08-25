#include <iostream>
#include <vector>

using namespace std;

int lastOccurence(vector<int> &nums, int val)
{
    int f = 0, r = nums.size() - 1;

    int mid;

    while (f <= r)
    {
        mid = (r + f) / 2;

        if (nums[mid] > val)
            r = mid - 1;
        else if (nums[mid] < val)
            f = mid + 1;
        else
        {
            if (mid == nums.size() - 1 || nums[mid + 1] != val)
                return mid;
            else
                f = mid + 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> arr = {10, 15, 20, 20, 40, 40};

    cout << lastOccurence(arr, 15) << endl;
    cout << lastOccurence(arr, 40) << endl;
    return 0;
}