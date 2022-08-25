#include <iostream>
#include <algorithm>

using namespace std;

void lcs_print(string a, string b, int m, int n)
{
    if (n == 0 || m == 0)
        return;

    if (a[m - 1] == b[n - 1])
    {
        cout << a[m - 1];
        lcs_print(a, b, m - 1, n - 1);
        return;
    }

    lcs_print(a, b, m - 1, n - 1);
    lcs_print(a, b, m, n - 1);
}
int lcs(string s1, string s2, int m, int n)
{
    int tabulation[m + 1][n + 1] = {0};

    for (int i = 0; i <= m; ++i)
        tabulation[i][0] = 0;

    for (int i = 0; i <= n; ++i)
        tabulation[0][i] = 0;

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                tabulation[i][j] = 1 + tabulation[i - 1][j - 1];
            else
                tabulation[i][j] = max(tabulation[i - 1][j], tabulation[i][j - 1]);
        }
    }

    return tabulation[m][n];
}

int main()
{

    string s1 = "CDAABBBB";
    string s2 = "BCAABBBB";
    int m = s1.length();
    int n = s2.length();
    // if (isSeq("DBA", "CDA"))
    //     cout << "YES\n";
    // else
    //     cout << "NO\n";
    // cout << lcs(s1, s2, m, n);
    lcs_print(s1, s2, m, n);
    // cout << endl;

    // for (auto c : memo)
    //     cout << c.first << " " << c.second << endl;
    return 0;
}