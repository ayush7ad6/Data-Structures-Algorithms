#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarray(vector<int> &arr)
{
    int curr = arr[0];
    int res = arr[0];

    for (int i = 1; i < arr.size(); ++i)
    {
        curr = max(arr[i], curr + arr[i]);
        res = max(res, curr);
    }

    return res;
}

int main()
{
    vector<int> arr = {2, 3, -4};

    cout << maxSubarray(arr);
    return 0;
}