#include <bits/stdc++.h>

using namespace std;

// B R I A N   K E R N I N G A M ' S    A L G O R I T H M
bool powerOf2(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

int main()
{
    cout << powerOf2(10);
    return 0;
}