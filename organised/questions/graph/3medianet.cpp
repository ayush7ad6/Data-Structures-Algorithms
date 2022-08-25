#include <bits/stdc++.h>

using namespace std;

void func(int A, vector<int> &B, vector<vector<int>> &C, int D)
{
    vector<vector<int>> adj[A + 1];

    for (auto i : C)
    {
        vector<int> node;
        node.push_back(i[1]);
        // node.push_back(i[2]);
        node.push_back(B[i[1] - 1] + i[2] + i[2] * D);

        adj[i[0]].push_back(node);
        adj[i[1]].push_back({i[0], B[i[0] - 1] + i[2] + i[2] * D});
    }

    for (int i = 1; i <= A; ++i)
    {
        cout << i << "->";
        for (auto v : adj[i])
        {
            cout << v[0] << "," << v[1] << "  "; // << "," << v[2] << "  ";
        }
        cout << endl;
    }

    for (int i = 1; i <= A; ++i)
    {
        int mincost = INT_MAX;
        for (auto v : adj[i])
        {
            mincost = min(B[i - 1], v[1]);
        }
        cout << mincost << endl;
    }
    // vector<vector<int>> prices(A + 1, vector<int>(A + 1, 0));

    // for (int i = 1; i <= A; ++i)
    //     prices[i][i] = B[i];

    // for (int i = 1; i <= A; ++i)
    // {
    //     cout << i << "->";
    //     int mincost = prices[i][i];
    //     for (auto v : adj[i])
    //     {
    //         prices[i][v[0]] = v[1] + B[v[0]] * v[2];
    //         mincost = min(mincost, prices[i][v[0]]);
    //     }
    //     cout << mincost << endl;
    // }
}

int main()
{

    // int A = 4;
    // vector<int> B = {3, 1, 10, 1};
    // vector<vector<int>> C = {{2, 1, 2}, {3, 1, 2}, {4, 1, 4}, {3, 2, 1}, {4, 2, 2}, {4, 3, 1}};
    // int D = 1;

    int A = 2;
    vector<int> B = {1, 3};
    vector<vector<int>> C = {{2, 1, 3}};
    int D = 1;

    func(A, B, C, D);
    return 0;
}