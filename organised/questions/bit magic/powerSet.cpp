#include <bits/stdc++.h>

using namespace std;

void powerSet(string s, int n)
{
    // cout << n;
    if (n > (pow(2, s.length()) - 1))
        return;
    int k = 0;
    int temp = n;
    while (n > 0)
    {
        if (n & 1)
        {
            cout << s[k];
        }
        ++k;
        n = n >> 1;
    }

    cout << endl;
    powerSet(s, temp + 1);
}

int main()
{
    string s = "ayush";
    powerSet(s, 0);

    return 0;
}