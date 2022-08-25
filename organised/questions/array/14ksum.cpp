#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumKsum(vector<int> &arr, int k)
{
    int curr = 0;
    for (int i = 0; i < k; ++i)
        curr += arr[i];

    int maxsum = curr;

    for (int i = k; i < arr.size(); ++i)
    {
        curr += (arr[i] - arr[i - k]);
        maxsum = max(curr, maxsum);
    }

    cout << maxsum;

    return maxsum;
}

int main()
{
    vector<int> arr = {1, 8, 30, -5, 20, 7};
    int k = 3;

    maximumKsum(arr, k);
    return 0;
}