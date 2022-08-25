#include <iostream>
#include <vector>

using namespace std;

int sqrt(int n)
{
    int f = 1, r = n;

    int mid;

    while (f <= r)
    {
        mid = (f + r) / 2;

        if ((mid * mid) == n)
            return mid;
        else if ((mid * mid) < n)
            f = mid + 1;
        else
            r = mid - 1;
    }

    return r;
}

int main()
{
    cout << sqrt(10) << endl;
    cout << sqrt(14) << endl;
    cout << sqrt(25) << endl;
    cout << sqrt(99) << endl;
    return 0;
}