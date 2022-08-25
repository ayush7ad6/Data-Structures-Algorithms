#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int target, int n)
{
    if (target == 0)
        return 0;

    if (n == 0)
        return 0;

    int res = -1;

    if (weights[n - 1] <= target)
        res = values[n - 1] + knapsack(weights, values, target - weights[n - 1], n - 1);

    res = max(res, knapsack(weights, values, target, n - 1));

    return res;
}

int knapsack(vector<int> &weights, vector<int> &values, int W)
{
    vector<vector<int>> dp(W + 1, vector<int>(weights.size() + 1, 0));

    for (int i = 1; i <= W; ++i)
    {
        for (int j = 1; j <= weights.size(); ++j)
        {
            int res = -1;
            if (weights[j - 1] <= i)
            {
                res = values[j - 1] + dp[i - weights[j - 1]][j - 1];
            }

            dp[i][j] = max(res, dp[i][j - 1]);
        }
    }

    return dp[W][weights.size()];
}
int main()
{
    vector<int> values = {10, 40, 30, 50};
    vector<int> weights = {5, 4, 6, 3};

    cout << knapsack(weights, values, 10);
    return 0;
}