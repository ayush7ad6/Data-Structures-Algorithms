#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[500];
int maxCuts(int n, int a, int b, int c)
{
    if (n < 0)
        return -1;
    if (dp[n] == -1)
    {
        if (n < 0)
            return dp[n] = -1;
        if (n == 0)
            return dp[n] = 0;

        int res = max(maxCuts(n - a, a, b, c), max(maxCuts(n - b, a, b, c), maxCuts(n - c, a, b, c)));

        if (res == -1)
            return dp[n] = -1;

        return dp[n] = res + 1;
    }

    return dp[n];
}

int main()
{
    int n = 100, a = 1, b = 2, c = 3;
    for (int i = 0; i <= n; ++i)
        dp[i] = -1;
    cout << maxCuts(n, a, b, c);
    return 0;
}