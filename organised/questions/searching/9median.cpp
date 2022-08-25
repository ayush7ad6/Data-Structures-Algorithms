#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double median(vector<int> &a, vector<int> &b)
{
    vector<int> &p = a;
    vector<int> &q = b;

    int m = a.size();
    int n = b.size();

    if (m > n)
    {
        p = b;
        q = a;
        swap(a, b);
    }

    int begin = 0, end = m - 1;
    while (begin <= end)
    {
        int i1 = (begin + end) / 2;
        int i2 = (m + n + 1) / 2 - i1;

        int max1 = (i1 == 0) ? INT_MIN : p[i1 - 1];
        int min1 = (i1 == m) ? INT_MAX : p[i1];

        int max2 = (i2 == 0) ? INT_MIN : q[i2 - 1];
        int min2 = (i2 == n) ? INT_MAX : q[i2];

        if (max1 < min2 && min1 > max2)
        {
            if ((m + n) & 1)
                return (double)max(max1, max2);
            return ((double)max(max1, max2) + min(min1, min2)) / 2;
        }
        else if (max1 > min2)
            end = i1 - 1;
        else
            begin = i1 + 1;
    }

    return INT_MIN;
}

int main()
{
    vector<int> a = {20, 40, 50, 60};
    vector<int> b = {5, 6, 7, 8, 9, 10};

    cout << median(a, b);
    return 0;
}