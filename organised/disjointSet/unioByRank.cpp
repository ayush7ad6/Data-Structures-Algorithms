#include <bits/stdc++.h>

using namespace std;

class UnionByRank
{
public:
    vector<int> arr;
    vector<int> rank;
    UnionByRank(int x) : arr(x), rank(x)
    {
        for (int i = 0; i < x; ++i)
        {
            arr[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x == arr[x])
            return x;

        return find(arr[x]);
    }

    void unionSet(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;
        if (rank[px] > rank[py])
            arr[py] = px;
        else if (rank[py] > rank[px])
            arr[px] = py;
        else
        {
            arr[py] = px;
            ++rank[px];
        }
    }

    void show()
    {
        for (auto i : arr)
            cout << i << " ";
    }
    void showrank()
    {
        for (auto i : rank)
            cout << i << " ";
    }
};