#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// int minChange(vector<int> &coins, int sum, int n)
// {
//     if (sum == 0)
//         return 0;

//     if (n == 0)
//         return INT_MAX;
//     int res = INT_MAX;
//     if (sum >= coins[n - 1])
//     {
//         res = minChange(coins, sum - coins[n - 1], n);
//         if (res != INT_MAX)
//             res = res + 1;
//     }
//     cout << "Before: " << coins[n - 1] << " " << sum << " " << res << endl;
//     res = min(res, minChange(coins, sum, n - 1));
//     cout << "After: " << coins[n - 1] << " " << sum << " " << res << endl;

//     // if (res == INT_MAX)
//     //     return -1;
//     return res;
// }

int minChange(vector<int> &coins, int sum, int n)
{
    if (sum == 0)
        return 0;
    int res = INT_MAX;

    for (auto coin : coins)
    {
        if (coin <= sum)
        {
            int sub = minChange(coins, sum - coin, n);
            if (sub != INT_MAX)
                res = min(res, sub + 1);
        }
    }

    return res;
}

int minChange(vector<int> &coins, int sum)
{
    int dp[sum + 1];
    for (int i = 0; i <= sum; ++i)
        dp[i] = INT_MAX;

    dp[0] = 0;

    for (int i = 1; i <= sum; ++i)
    {
        for (auto coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        cout << dp[i] << " ";
    }

    return dp[sum];
}
int main()
{
    vector<int> coins = {25, 10, 5};
    coins = {9, 6, 5, 10};
    cout << endl;
    cout << minChange(coins, 11);
    return 0;
}