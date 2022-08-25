/*
    Find the equilibrium point
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int equilibriumPoint(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n + 1, arr[0]);
    vector<int> suffix(n, arr[n - 1]);

    for (int i = 1; i < arr.size(); ++i)
    {
        prefix[i] = prefix[i - 1] + arr[i];
        suffix[n - i - 1] = suffix[n - i] + arr[n - i - 1];

        // if (prefix[i] == suffix[n - i - 1])
        //     return arr[i];
    }

    for (int i = 1; i < n - 1; ++i)
    {
        if (prefix[i - 1] == suffix[i + 1])
            return arr[i];
    }
    if (prefix[n - 2] == 0)
        return arr[n - 1];
    if (suffix[1] == 0)
        return arr[0];

    return -1;
}

int equilibrium(vector<int> &arr)
{

    int n = arr.size();
    int sum = 0;
    sum = accumulate(arr.begin(), arr.end(), sum);

    int left = 0;

    for (int i = 0; i < n; ++i)
    {
        if (left == sum - arr[i])
            return arr[i];
        left += arr[i];
        sum -= arr[i];
    }

    return -1;
    // int n = arr.size();
    // vector<int> prefix(n, arr[0]);
    // for (int i = 1; i < n; ++i)
    // {
    //     prefix[i] = prefix[i - 1] + arr[i];
    // }

    // for (int i = 0; i < n; ++i)
    // {
    //     int left = 0;
    //     if (i > 0)
    //         left = prefix[i - 1];

    //     int right = 0;

    //     // right = prefix[n - 1] - prefix[i];
    //     right = prefix[n - 1] - left;
    //     cout << left << " " << right << endl;
    //     if (left == right)
    //         return arr[i];
    // }

    // return -1;
}
int main()
{
    vector<int> arr = {3, 4, 8, -9, 20, 6};
    // vector<int> arr = {4, 2, -2};
    cout << equilibrium(arr);
    return 0;
}