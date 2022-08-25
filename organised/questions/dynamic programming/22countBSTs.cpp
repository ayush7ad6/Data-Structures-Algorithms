#include <iostream>
#include <climits>

using namespace std;

int countBST(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += countBST(i - 1) * countBST(n - i);
    }

    return ans;
}

int countBSTDP(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    // dp[1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 0;
        // cout << "B: " << dp[i] << endl;
        for (int j = i; j >= 0; --j)
        {
            // cout << dp[j] << " " << dp[i - 1] << endl;
            dp[i] += (dp[j] * dp[i - j - 1]);
        }
        // cout << "A: " << dp[i] << endl;
    }

    return dp[n];
}

int catalanNumber(int n)
{
    if (n <= 1)
        return 1;

    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans += catalanNumber(i) * catalanNumber(n - i - 1);

    return ans;
}
int main()
{
    int n = 2;
    n = 3;
    n = 5;
    // cout << countBST(10);
    // cout << countBSTDP(5);

    cout << catalanNumber(5);
    return 0;
}