#include <iostream>
#include <vector>

using namespace std;

bool isValid(pair<int, int> a, pair<int, int> b)
{
    if (b.first == a.first && b.second != a.second)
        return true;
    if (b.first > a.first && b.second >= a.second)
        return true;

    if (b.first < a.first && b.second <= a.second)
        return true;

    return false;
}
int buildBridges(vector<pair<int, int>> &arr)
{
    int n = arr.size();
    int lis[n];

    int maxBridges = 0;

    for (int i = 0; i < n; ++i)
    {
        lis[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (isValid(arr[i], arr[j]))
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }

        maxBridges = max(maxBridges, lis[i]);
    }

    return maxBridges;
}

int main()
{
    vector<pair<int, int>> arr = {{8, 1}, {1, 2}, {4, 3}, {3, 4}, {2, 6}, {6, 7}, {7, 8}, {5, 5}};

    cout << "Max bridges: " << buildBridges(arr);
    return 0;
}