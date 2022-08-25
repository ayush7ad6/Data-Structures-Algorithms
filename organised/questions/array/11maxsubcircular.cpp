#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxCircularSubarray(vector<int> &arr)
{
    int currMin = arr[0];
    int minSub = arr[0];
    int currMax = arr[0];
    int maxSub = arr[0];

    int total = arr[0];
    for (int i = 1; i < arr.size(); ++i)
    {
        currMin = min(arr[i], arr[i] + currMin);
        currMax = max(arr[i], arr[i] + currMax);

        minSub = min(minSub, currMin);
        maxSub = max(maxSub, currMax);

        total += arr[i];
    }
    // cout << total << " " << maxSub << " " << minSub << endl;
    return total == minSub ? maxSub : max(maxSub, total - minSub);
    // return max(maxSub, total - minSub);
}

int main()
{
    // vector<int> arr = {5, -2, 3, 4};
    // vector<int> arr = {2, 3, -4};
    // vector<int> arr = {8, -4, 3, -5, 4};
    // vector<int> arr = {-3, 4, 6, -2};
    // vector<int> arr = {-8, 7, 6};
    vector<int> arr = {-8, -7, -6};
    // vector<int> arr = {3, -4, 5, 6, -8, 7};

    cout << maxCircularSubarray(arr);
    return 0;
}