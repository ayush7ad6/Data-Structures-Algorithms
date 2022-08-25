#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxDifference(vector<int> &arr)
{
    int currMin = arr[0];
    int res = INT_MIN;

    for (auto i = 1; i < arr.size(); ++i)
    {
        res = max(res, arr[i] - currMin);
        if (arr[i] < currMin)
            currMin = arr[i];
    }

    return res;
}

int main()
{
    // vector<int> arr = {2, 3, 10, 6, 4, 8, 1};
    // vector<int> arr = {10, 20, 30};
    vector<int> arr = {300, 10, 9};

    cout << maxDifference(arr);
    return 0;
}