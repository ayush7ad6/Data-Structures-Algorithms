#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

string printLCS(int *dp[], string s1, string s2, int m, int n);
int commonSuperseq(string s1, string s2, string &lcs)
{
    int m = s1.length();
    int n = s2.length();

    int **dp;
    dp = new int *[m + 1];
    for (int i = 0; i <= m; ++i)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j <= n; ++j)
            dp[i][j] = 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    lcs = printLCS(dp, s1, s2, m, n);
    return dp[m][n];
}

string printLCS(int **dp, string s1, string s2, int m, int n)
{
    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        cout << i << " " << j << "--";
        if (s1[i - 1] == s2[j - 1])
        {
            cout << s1[i - 1] << " ";
            lcs += s1[i - 1];
            --i;
            --j;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                cout << s2[j - 1] << " ";
                lcs += s2[j - 1];
                --j;
            }
            else
            {
                cout << s1[i - 1] << " ";
                lcs += s1[i - 1];
                --i;
            }
        }
    }
    cout << endl;
    reverse(lcs.begin(), lcs.end());
    return lcs;
}
int main()
{
    string s1 = "CDA";
    string s2 = "DCA";
    string lcs;
    cout << commonSuperseq(s1, s2, lcs);

    cout << endl;
    //  << lcs;
    cout << lcs << " " << lcs.length() << endl
         << endl;

    return 0;
}
