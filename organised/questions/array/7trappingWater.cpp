#include <iostream>
#include <vector>

using namespace std;

int trappingWaterI(vector<int> &arr)
{
    int res = 0;

    for (auto i = 0; i < arr.size(); ++i)
    {
        int start = arr[i];
        int middle = 0;
        for (auto j = i + 1; j < arr.size(); ++j)
        {
            int curr = start < arr[j] ? start * (j - i - 1) : arr[j] * (j - i - 1);
            curr = curr - middle;
            res = max(res, curr);

            middle += arr[j];
        }
    }

    return res;
}

int trappingWaterII(vector<int> arr)
{

    vector<int> lMax(arr.size(), arr[0]);
    vector<int> rMax(arr.size(), arr[arr.size() - 1]);
    int l = 0;
    int r = 0;
    int n = arr.size();
    for (int i = 1; i < arr.size(); ++i)
    {
        lMax[i] = max(lMax[i - 1], arr[i]);
        rMax[n - 1 - i] = max(rMax[n - i], arr[n - 1 - i]);
    }

    int water = 0;
    for (int i = 0; i < n; ++i)
    {
        water += min(lMax[i], rMax[i]) - arr[i];
    }
    return water;
}

int main()
{
    // vector<int> arr = {2, 0, 2};
    // vector<int> arr = {3, 0, 1, 2, 5};
    // vector<int> arr = {5, 0, 6, 2, 3};
    vector<int> arr = {1, 2, 3};

    cout << trappingWaterII(arr);
    return 0;
}