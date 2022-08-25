#include <iostream>
#include <string.h>

using namespace std;

int lcs(string s, int m, int n)
{
    if (n == 0 || m == 0)
        return 0;

    if (n != m && s[m - 1] == s[n - 1])
        return 1 + lcs(s, m - 1, n - 1);

    return max(lcs(s, m - 1, n), lcs(s, m, n - 1));
}

int main()
{
    string s = "aabb";
    cout << lcs(s, 4, 4);
    return 0;
}