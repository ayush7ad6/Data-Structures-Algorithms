// find the maximum common subsequence
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> memo;

bool isSeq(string s, string seq)
{
    if (s.length() < seq.length())
        return false;
    int itr = 0, i = 0;

    while (i < s.length() && itr < seq.length())
    {
        if (s[i] == seq[itr])
            ++itr;
        ++i;
    }

    if (itr == seq.length())
        return true;

    return false;
}

int longest = 0;
int MCS(string s, string seq, int i = 0, string temp = "")
{
    cout << "curr: " << temp << endl;
    if (memo.find(temp) == memo.end())
    {
        cout << "for: " << temp << endl;
        int currLen;
        if (i >= s.length())
        {
            if (isSeq(seq, temp))
                currLen = temp.length();
            else
                currLen = 0;
        }
        else
        {
            currLen = max(MCS(s, seq, i + 1, temp), MCS(s, seq, i + 1, temp + s[i]));
        }
        memo[temp] = currLen;
    }
    // cout << i << " " << temp << " " << memo[temp] << endl;
    longest = max(memo[temp], longest);
    return memo[temp];
}
int dp[100][100] = {0};
int lcs(string s1, string s2, int m, int n)
{
    if (dp[m][n] == -1)
    {
        int res;
        if (m <= 0 || n <= 0)
            res = 0;
        else if (s1[m - 1] == s2[n - 1])
            res = 1 + lcs(s1, s2, m - 1, n - 1);

        else
            res = max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));

        dp[m][n] = res;
    }

    return dp[m][n];
}
int main()
{
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            dp[i][j] = -1;
    string s1 = "CDA";
    string s2 = "BCA";
    int m = s1.length();
    int n = s2.length();
    // if (isSeq("DBA", "CDA"))
    //     cout << "YES\n";
    // else
    //     cout << "NO\n";
    cout << lcs(s1, s2, m, n);
    // cout << endl;

    // for (auto c : memo)
    //     cout << c.first << " " << c.second << endl;
    return 0;
}