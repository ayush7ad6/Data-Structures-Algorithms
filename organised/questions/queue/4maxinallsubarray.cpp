#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void maximumInSubarray(vector<int> &nums, int k)
{
    for (int i = 0; i <= nums.size() - k; ++i)
    {
        int larg = nums[i];
        for (int j = 1; j < k; ++j)
        {
            if (larg < nums[i + j])
                larg = nums[i + j];
        }
        cout << larg << " ";
    }
}

void maximumInSubarray_dq(vector<int> &nums, int k)
{
    deque<int> dq;

    for (int i = 0; i < k; ++i)
    {
        while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << nums[dq.front()] << " ";

    for (int i = k; i < nums.size(); ++i)
    {
        if (dq.empty() == false && dq.front() <= (i - k))
            dq.pop_front();

        while (dq.empty() == false && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        cout << nums[dq.front()] << " ";
    }
}
int main()
{
    // vector<int> arr = {10, 8, 5, 12, 15, 7, 6};
    vector<int> arr = {20, 10, 30, 10, 60};
    int k = 3;
    maximumInSubarray_dq(arr, k);

    return 0;
}