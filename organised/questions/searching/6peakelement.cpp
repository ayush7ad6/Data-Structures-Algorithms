#include <iostream>
#include <vector>

using namespace std;

int peakElement(vector<int> &nums, int low, int high)
{
    if (high < low)
        return -1;

    int mid = (low + high) / 2;
    if (mid == 0 && nums[mid] > nums[mid + 1])
        return mid;

    if (mid == nums.size() - 1 && nums[mid] > nums[mid - 1])
        return mid;

    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        return mid;

    int left = peakElement(nums, low, mid - 1);
    int right = peakElement(nums, mid + 1, high);

    if (left == -1 && right == -1)
        return -1;

    return left == -1 ? right : left;
}

int peakElement(vector<int> &nums, int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if ((mid == 0 || nums[mid - 1] <= nums[mid]) || (mid == n - 1 || nums[mid + 1] <= nums[mid]))
            return mid;

        if (mid > 0 && nums[mid - 1] >= nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main()
{
    // vector<int> arr = {5, 10, 20, 15, 7};
    vector<int> arr = {10, 20, 15, 5, 23, 90, 67};

    cout << arr[peakElement(arr, 67)];
    return 0;
}