#include <iostream>
#include <vector>

using namespace std;

void intersection(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        while (i > 0 && a[i - 1] == a[i])
            ++i;
        if (a[i] < b[j])
            ++i;
        else if (a[i] > b[i])
            ++j;
        else
        {
            cout << a[i] << " ";
            ++i;
            ++j;
        }
    }
}

int main()
{
    vector<int> a = {3, 5, 10, 10, 10, 15, 15, 20};
    vector<int> b = {5, 10, 10, 15, 30};

    intersection(a, b);
    return 0;
}