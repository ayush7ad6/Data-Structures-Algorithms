#include <bits/stdc++.h>

using namespace std;
// N A I V E
void countBits(int n)
{
    int count = 0;
    while (n)
    {
        if (n & 1)
            ++count;
        n = n >> 1;
    }

    cout << count << " bits set" << endl;
    return;
}
// B R I A N   K E R N I N G A M ' S  A L G O
void countBits(int n, bool BrianAlgo)
{
    if (BrianAlgo == true)
    {
        int res = 0;
        while (n)
        {
            n = n & (n - 1);
            ++res;
        }

        cout << res << " bits set acc to Brian Kerningam's Algo\n";
    }
}

// C O N S T A N T   T I M E
int table[256];
void preprocess()
{
    table[0] = 0;
    for (int i = 1; i < 256; ++i)
        table[i] = i & 1 + table[i / 2];
}
void countBits(int n, bool BrianAlgo, bool constant)
{
    preprocess();
    int res = table[n & 0xff];
    n = n >> 8;
    res += table[n & 0xff];
    n = n >> 8;
    res += table[n & 0xff];
    n = n >> 8;
    res += table[n & 0xff];
    cout << res << " bits are set acc to the lookup talbe\n";
    return;
}
int main()
{
    countBits(511, false, true);
    return 0;
}
