#include <bits/stdc++.h>

using namespace std;

bool dfsRec(vector<int> adj[], int V, int source, int destination, string &path, vector<bool> &visited, int weight[])
{
    // cout << source << " ";
    if (source == destination)
    {
        // path.push_back(source);
        return true;
    }

    visited[source] = true;
    // path.push_back(source);
    for (auto v : adj[source])
    {
        if (visited[v] == false)
        {
            path += to_string(weight[v]);
            if (dfsRec(adj, V, v, destination, path, visited, weight))
                return true;
            path.pop_back();
        }
    }

    return false;
}

void dfs(vector<int> adj[], int V, int weight[], vector<vector<int>> queries)
{

    // vector<int> path;
    vector<vector<string>> paths(V, vector<string>(V, ""));
    for (int i = 1; i < V; ++i)
    {
        for (int j = 1; j < V; ++j)
        {
            // cout << i << "," << j << "-> ";
            string path;
            int src = i;
            int dst = j;
            vector<bool> vis(V, false);
            path += to_string(weight[src]);
            dfsRec(adj, V, src, dst, path, vis, weight);
            // cout << path << endl;
            paths[i][j] = path;
        }
    }

    // for (int i = 1; i < V; ++i)
    // {
    //     for (int j = 1; j < V; ++j)
    //     {
    //         cout << paths[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (auto i : queries)
    {
        int r = i[0];
        int c = i[1];
        if (paths[r][c] == "")
        {
            swap(r, c);
        }

        int count = 0;
        for (auto ch : paths[c][r])
        {
            if ((int)(ch - '0') <= i[2])
                ++count;
        }
        cout << count << " ";
    }
}

int main()
{
    int V = 6;
    int weight[V] = {0, 4, 7, 8, 6, 4};
    vector<int> adj[V];

    adj[1] = {5};
    adj[2] = {3, 4, 5};
    adj[3] = {2};
    adj[4] = {2};
    adj[5] = {1, 2};
    vector<vector<int>> queries = {{4, 2, 1}, {2, 3, 7}, {2, 4, 8}, {5, 3, 1}, {3, 4, 8}};
    dfs(adj, V, weight, queries);
    return 0;
}