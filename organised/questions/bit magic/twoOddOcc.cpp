#include <bits/stdc++.h>

using namespace std;

void oddAppearing(vector<int> arr)
{
    int xorr = 0;
    for (auto x : arr)
        xorr ^= x;

    xorr = xorr & ~(xorr - 1); // TURNING ON THE RIGHTMOST BIT

    int a = 0, b = 0;
    for (auto x : arr)
    {
        if ((xorr & x) != 0)
            a ^= x;
        else
            b ^= x;
    }

    cout << a << " " << b << endl;
}

int main()
{
    oddAppearing({1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 4, 4});
    return 0;
}