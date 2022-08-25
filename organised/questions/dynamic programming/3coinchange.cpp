// no of ways to get the sum
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(vector<int> &coins, int sum, int n)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;

    int sub = func(coins, sum, n - 1);

    if (coins[n - 1] <= sum)
        sub = sub + func(coins, sum - coins[n - 1], n);

    return sub;
}

int func_tabulation(vector<int> &coins, int sum, int n)
{
    vector<vector<int>> dp(sum + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= sum; ++i)
        dp[i][0] = 0;

    for (int i = 0; i <= n; ++i)
        dp[0][i] = 1;

    for (int i = 1; i <= sum; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int res = dp[i][j - 1];
            if (coins[j - 1] <= i)
                res = res + dp[i - coins[j - 1]][j];
            dp[i][j] = res;
        }
    }
    for (int i = 0; i <= sum; ++i)
    {
        for (int j = 0; j <= n; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[sum][n];
}
int dp[101][101];
int coinChange(vector<int> &coins, int sum, int n)
{
    cout << sum << " " << n << " " << dp[sum][n] << endl;
    if (sum < 0)
        return 0;
    if (dp[sum][n] == -1)
    {
        cout << "in\n\n";
        if (sum < 0 || n == 0)
            dp[sum][n] = 0;

        else if (sum == 0)
            dp[sum][n] = 1;

        else
            dp[sum][n] = coinChange(coins, sum - coins[n - 1], n) + coinChange(coins, sum, n - 1);
    }

    return dp[sum][n];
}

int main()
{
    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 101; ++j)
            dp[i][j] = -1;

    vector<int> coins = {1, 2, 3};
    // coins = {2, 5, 3, 6};
    int sum = 4;
    int n = coins.size();

    cout << func_tabulation(coins, sum, n);
    // cout << coinChange(coins, sum, n);
    cout << endl
         << endl
         << endl;

    // for (int i = 0; i <= sum; ++i)
    // {
    //     for (int j = 0; j <= n; ++j)
    //         cout << dp[i][j] << "\t";
    //     cout << endl;
    // }
    return 0;
}
