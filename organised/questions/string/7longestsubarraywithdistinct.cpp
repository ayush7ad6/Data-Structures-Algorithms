#include <bits/stdc++.h>

using namespace std;

int longestSubarrayWithDistinct(string s)
{
    int res = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        int freq[256] = {0};
        for (int j = i; j < s.length(); ++j)
        {
            if (freq[s[j]])
                break;
            res = max(res, j - i + 1);
            freq[s[j]] = 1;
        }
    }

    return res;
}

int longestSubarrayWithDistinct_opt(string s)
{
    vector<int> prev(256, -1);

    // prev[0] = 0;
    int res = 0;
    int start = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        // if (prev[s[i]] == -1)
        // {
        //     prev[s[i]] = i;
        //     res = max(res, i - start + 1);
        // }
        // else
        // {
        //     start = prev[s[i]] + 1;
        //     res = max(res, i - start - 1);
        //     prev[s[i]] = i;
        // }
        start = max(start, prev[s[i]] + 1);
        res = max(res, i - start + 1);
        prev[s[i]] = i;
        cout << res << " ";
    }

    return res;
}

int main()
{
    string s = "abcadbd";
    cout << longestSubarrayWithDistinct_opt(s);
    return 0;
}