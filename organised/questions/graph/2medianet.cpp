#include <bits/stdc++.h>

using namespace std;

bool dfsRec(vector<int> adj[], int source, int destination, vector<bool> &vis, vector<int> &path)
{
    if (source == destination)
    {
        // path.push_back(source);
        return true;
    }

    vis[source] = true;

    for (auto v : adj[source])
    {
        if (vis[v] == false)
        {
            path.push_back(v);
            if (dfsRec(adj, v, destination, vis, path))
                return true;

            path.pop_back();
        }
    }

    return false;
}

void func(int A, vector<int> &B, int C, vector<int> &D, vector<int> &E)
{
    int V = A;
    vector<int> adj[A + 1];

    for (int i = 0; i < B.size(); ++i)
    {
        adj[B[i]].push_back(i + 1 + 1);
    }

    for (int i = 1; i <= A; ++i)
    {
        cout << i << "->";
        for (auto v : adj[i])
            cout << v << " ";
        cout << endl;
    }

    for (int q = 0; q < C; ++q)
    {
        vector<int> path;
        vector<bool> vis(A + 1, false);
        path.push_back(1);
        dfsRec(adj, 1, D[q], vis, path);
        // cout << "path:\n";

        // for (auto p : path)
        //     cout << p << " ";
        // cout << endl;
        int maxans = 0;

        for (auto i : path)
            maxans = max(maxans, E[q] ^ i);
        cout << maxans << endl;
    }
}

int main()
{
    // int A = 3;
    // vector<int> B = {1, 1};
    // int C = 2;
    // vector<int> D = {2, 3};
    // vector<int> E = {3, 1};
    // func(A, B, C, D, E);

    int A = 8;
    vector<int> B = {1, 1, 2, 2, 3, 3, 1};
    int C = 5;
    vector<int> D = {2, 3, 5, 6, 8};
    vector<int> E = {1, 1, 5, 4, 10};
    func(A, B, C, D, E);
    return 0;
}