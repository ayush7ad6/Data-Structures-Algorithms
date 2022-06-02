#include <bits/stdc++.h>

using namespace std;
// D E T E C T    C Y C L E    B F S
bool cyclePresentBFS(vector<int> adj[], int v, int s, bool visited[])
{
    queue<int> q;
    int parent[v];
    // int parent = s;
    q.push(s);
    parent[s] = s;
    visited[s] = true;
    while (q.empty() == false)
    {
        auto u = q.front();
        q.pop();
        // visited[u] = true;
        // auto parent = u;
        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
            else if (v != parent[u])
                return true;
        }
    }

    return false;
}
bool cyclePresent(vector<int> adj[], int v)
{
    bool visited[v] = {0};

    for (int i = 0; i < v; ++i)
        if (visited[i] == false)
            if (cyclePresentBFS(adj, v, i, visited) == true)
            {
                cout << "AT:" << i << " ";
                return true;
            }
    return false;
}

// D E T E C T   C Y C L E   D F S
bool cyclePresentRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto v : adj[s])
    {
        if (visited[v] == false)
        {
            if (cyclePresentRec(adj, v, visited, s) == true)
                return true;
        }
        else if (parent != v)
            return true;
    }
    return false;
}

bool cyclePresentDFS(vector<int> adj[], int V)
{
    bool visited[V] = {0};
    // for (int i = 0; i < V; ++i)
    //     visited[i] = false;
    for (int i = 0; i < V; ++i)
        if (visited[i] == false)
            if (cyclePresentRec(adj, i, visited, -1) == true)
            {
                cout << "AT: " << i;
                return true;
            }
    return false;
}