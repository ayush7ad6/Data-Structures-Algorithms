#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> lps(string s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;

    int i = 1;
    while (i < n)
    {
        if (s[i] == s[len])
        {
            s[i] = len + 1;
            ++len;
            ++i;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                ++i;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
    return lps;
}

vector<int> kmp(string pattern, string text)
{
    int pn = pattern.size();
    int tn = text.size();

    vector<int> lpsArr = lps(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0, j = 0;

    vector<int> ans;
    while (i < n)
    {
        if (pattern[j] == text[i])
            ++i, ++j;

        if (j == m)
        {
            ans.push_back(i - j);
            j = lpsArr[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j == 0)
                ++i;
            else
            {
                j = lpsArr[j - 1];
            }
        }
    }

    return ans;
}

int main()
{
    string s = "ababcababaad";
    string p = "aba";

    vector<int> ans = kmp(p, s);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}