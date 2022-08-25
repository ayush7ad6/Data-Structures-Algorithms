#include <bits/stdc++.h>

using namespace std;

class Unionfind
{
public:
    vector<int> arr;
    Unionfind(int x) : arr(x)
    {
        for (int i = 0; i < x; ++i)
            arr[i] = i;
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
        arr[py] = px;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
    void show()
    {
        for (auto i : arr)
            cout << i << " ";
    }
};