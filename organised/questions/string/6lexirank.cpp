#include <iostream>
#include <string>

using namespace std;

int f(int n)
{
    int prev = 1;
    int prevprev = 1;
    for (int i = 2; i <= n; ++i)
    {
        prevprev = prev;
        prev = prev * i;
    }

    return prev;
}
int lexicographicalRank(string s)
{
    int freq[256] = {0};
    for (auto ch : s)
        freq[ch]++;
    for (int i = 1; i < 256; ++i)
        freq[i] += freq[i - 1];

    // int mul = fact(s.size() - 1);
    int res = 0;
    int fact = f(s.length());
    // cout << fact;
    for (int i = 0; i < s.length(); ++i)
    {
        fact = fact / (s.size() - i);
        res += (freq[s[i] - 1] * fact);
        for (int j = s[i]; j < 256; ++j)
            freq[j]--;
    }

    return res + 1;
}

int main()
{
    string s = "STRING";

    cout << lexicographicalRank(s);
    return 0;
}