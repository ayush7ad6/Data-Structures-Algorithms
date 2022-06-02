#include <bits/stdc++.h>

using namespace std;

void checkKthBit(int n, int k)
{
    if (1 & (n >> (k - 1)))
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}

int main()
{
    int n = 5;
    checkKthBit(n, 3);
    return 0;
}