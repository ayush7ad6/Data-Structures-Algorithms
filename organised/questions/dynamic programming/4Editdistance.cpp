#include <bits/stdc++.h>

using namespace std;

int editDistance(string a, string b, int m, int n)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    if (a[m - 1] == b[n - 1])
        return editDistance(a, b, m - 1, n - 1);

    return 1 + min(editDistance(a, b, m, n - 1), min(editDistance(a, b, m - 1, n - 1), editDistance(a, b, m - 1, n))); // insert replace delete
}
