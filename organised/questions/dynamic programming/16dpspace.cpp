#include <iostream>

using namespace std;

int lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    int dp[2][n + 1];
    for (int i = 0; i <= n; ++i)
    {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    int bi;
    for (int i = 1; i <= m; ++i)
    {
        bi = i & 1;
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // dp[i % 2][j] = 1 + dp[(i - 1) % 2][j - 1];
                dp[bi][j] = 1 + dp[1 - bi][j - 1];
            }
            else
            {
                // dp[i % 2][j] = max(dp[i % 2][j - 1], dp[(i - 1) % 2][j]);
                dp[bi][j] = max(dp[bi][j - 1], dp[1 - bi][j]);
            }
        }
    }

    return dp[bi][n];
}

int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";

    cout << lcs(s1, s2);
    return 0;
}