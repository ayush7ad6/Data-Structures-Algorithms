#include <iostream>
#include <vector>

using namespace std;

int firstOccurence(vector<int> &nums, int f, int r, int val)
{
    if (f > r)
        return -1;

    int mid = f + (r - f) / 2;

    if (nums[mid] == val)
    {
        if (mid > 0)
        {
            if (nums[mid - 1] != val)
                return mid;
        }
        else
            return mid;
    }

    if (nums[mid] < val)
        return firstOccurence(nums, mid + 1, r, val);

    return firstOccurence(nums, f, mid - 1, val);
}

int firstOccurence(vector<int> &nums, int val)
{
    int f = 0, r = nums.size() - 1;

    int mid;
    while (f <= r)
    {
        mid = (r + f) / 2;

        if (nums[mid] == val)
        {
            if (mid == 0 || nums[mid - 1] != val)
                return mid;

            r = mid - 1;
        }
        else if (nums[mid] > val)
            r = mid - 1;
        else
            f = mid + 1;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1, 10, 10, 10, 20, 20, 40};

    cout << firstOccurence(arr, 0, 6, 20) << " " << firstOccurence(arr, 20);
    cout << endl
         << firstOccurence(arr, 0, 6, 10) << " " << firstOccurence(arr, 10) << endl;
    return 0;
}
