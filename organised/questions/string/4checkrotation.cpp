#include <iostream>
#include <vector>
#include <string>

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

bool kmp(string pattern, string text)
{
    int pn = pattern.size();
    int tn = text.size();

    vector<int> lpsArr = lps(pattern);
    int n = text.size();
    int m = pattern.size();
    int i = 0, j = 0;

    // vector<int> ans;
    while (i < n)
    {
        if (pattern[j] == text[i])
            ++i, ++j;

        if (j == m)
        {
            // j = lpsArr[j - 1];
            return true;
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

    return false;
}

bool checkRotation(string s1, string s2)
{
    string s = s1 + s1;
    return kmp(s2, s);
}

bool sweet_checkRotation(string a, string b)
{
    if (a.length() != b.length())
        return false;

    return (a + a).find(b) != string::npos;
}
int main()
{
    string s1 = "abaaa";
    string s2 = "baaaa";
    // cout << checkRotation(s1, s2);
    cout << sweet_checkRotation(s1, s2);
    return 0;
}