#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    return static_cast<double>(a.second) / a.first > static_cast<double>(b.second) / b.first;
}

double fKnapsack(vector<pair<int, int>> arr, int amount)
{
    sort(arr.begin(), arr.end(), mycmp);

    // for (auto p : arr)
    //     cout << p.first << " " << p.second << endl;
    int n = arr.size();
    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
        cout << "Before: " << amount << endl;

        if (amount >= arr[i].first)
        {
            // int flr = amount / arr[i].first;
            // amount -= arr[i].first * flr;
            amount -= arr[i].first;

            // ans += arr[i].second * flr;
            ans += arr[i].second;
        }
        else
        {
            double flr = static_cast<double>(amount) / arr[i].first;
            ans += flr * arr[i].second;
            amount = 0;
            // break;
        }

        cout << "After: " << amount << "  " << ans << endl
             << endl;
        if (amount == 0)
            break;
    }
    cout << ans;
    return ans;
}

int main()
{
    vector<pair<int, int>> arr;
    arr = {{50, 600}, {20, 500}, {30, 400}};

    fKnapsack(arr, 70);
    return 0;
}