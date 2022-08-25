#include <iostream>
#include <vector>

using namespace std;

vector<int> leader(vector<int> &arr)
{
    vector<int> leaders;

    int n = arr.size() - 1;
    int currMax = arr[n] - 1;
    for (auto i = n; i >= 0; --i)
    {
        if (currMax < arr[i])
            leaders.push_back(arr[i]);
        currMax = max(currMax, arr[i]);
    }

    for (auto i : leaders)
        cout << i << " ";

    return leaders;
}

int main()
{
    // vector<int> arr = {7, 10, 5, 6, 2, 3};
    // vector<int> arr = {10, 11, 20, 30};
    vector<int> arr = {1000, 111, 111, 30, 30};
    leader(arr);
    return 0;
}