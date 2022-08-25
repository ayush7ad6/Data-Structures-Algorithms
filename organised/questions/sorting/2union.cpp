#include <iostream>
#include <vector>

using namespace std;

void unionOfArrays(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;
    int m = a.size(), n = b.size();

    while (i < m && j < n)
    {
        if (i > 0 && a[i - 1] == a[i])
        {
            ++i;
            continue;
        }

        if (j > 0 && b[j - 1] == b[j])
        {
            ++j;
            continue;
        }
        if (a[i] < b[j])
        {
            cout << a[i] << " ";
            ++i;
        }
        else if (a[i] > b[j])
        {
            cout << b[j] << " ";
            ++j;
        }
        else
        {
            cout << a[i] << " ";
            ++i;
            ++j;
        }
    }

    while (i < m)
    {
        if (i == 0 || a[i - 1] != a[i])
            cout << a[i] << " ";
        ++i;
    }

    while (j < n)
    {
        if (j == 0 || b[j - 1] != a[j])
            cout << b[j] << " ";
        ++j;
    }

    cout << endl;
}

int main()
{
    vector<int> a = {3, 5, 10, 10, 10, 15, 15, 20};
    vector<int> b = {5, 10, 10, 15, 30};

    unionOfArrays(a, b);
    return 0;
}