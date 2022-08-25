#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> patternMatching(string s, string p)
{
    int m = p.size();
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < n - m + 1; ++i)
    {
        string sub = s.substr(i, m);
        // cout << sub << endl;
        if (sub == p)
        {
            cout << i << " ";
            ans.push_back(i);
        }
    }

    return ans;
}

vector<int> patternMatching(string s, string p, bool hashing = true)
{
    int ps = p.size();
    int ss = s.size();

    int phash = 0;
    for (auto ch : p)
        phash += (ch - 'a');

    int currhash = 0;
    for (int i = 0; i < ps; ++i)
    {
        currhash += (s[i] - 'a');
    }

    int f = 0, r = ps - 1;
    while (r < ss - 1)
    {
        if (currhash == phash)
        {
            bool flag = true;
            for (int i = f; i <= r; ++i)
            {
                if (s[i] != p[i - f])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << f << " ";
        }

        currhash -= (s[f] - 'a');
        ++f;
        ++r;
        currhash += (s[r] - 'a');
    }
    if (currhash == phash)
    {
        bool flag = true;
        for (int i = f; i <= r; ++i)
        {
            if (s[i] != p[i - f])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << f << " ";
    }
    return {};
}

void rabinKarp(string s, string p)
{
    int ss = s.size();
    int ps = p.size();

    int q = 73;
    int po = 1;
    int d = 5;
    for (int i = 0; i < ps - 1; ++i)
        po = (po * d);

    int ph = 0, th = 0;
    for (int i = 0; i < ps; ++i)
    {
        ph = (ph * d + (p[i] - 'a' + 1));
        th = (th * d + (s[i] - 'a' + 1));
    }
    // cout << ph << " " << th << endl;
    for (int i = 0; i < ss - ps + 1; ++i)
    {
        // cout << th << endl;
        if (ph == th)
        {
            bool flag = true;
            for (int j = 0; j < ps; ++j)
            {
                if (p[j] != s[j + i])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << i << " ";
        }

        if (i < ss - ps)
        {
            th = (d * (th - (s[i] - 'a' + 1) * po) + (s[i + ps] - 'a' + 1));
        }
        // if (th < 0)
        //     th += q;
    }
}
int main()
{
    string s = "abdabcabc";
    string p = "abc";

    rabinKarp(s, p);
    return 0;
}