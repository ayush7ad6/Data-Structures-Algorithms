#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lps(string s)
{
    vector<int> ans;

    for (int len = 1; len <= s.size(); ++len)
    {
        int m = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            string t1 = s.substr(0, i + 1);
            string t2 = s.substr(len - 1 - i, i + 1);
            // cout << t1 << " " << t2 << " ";
            if (t1 == t2)
                m = max(m, (int)t1.size());
        }
        cout << m << " ";
    }

    return ans;
}

vector<int> lps_On(string s)
{
    vector<int> lps(s.size(), 0);

    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < s.size())
    {
        // cout << i << " " << len << endl;
        // len = lps[i - 1];
        if (s[i] == s[len])
        {
            lps[i] = len + 1;
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

    for (auto e : lps)
        cout << e << " ";
}
int main()
{
    string s = "abcbabca";
    lps_On(s);
    return 0;
}