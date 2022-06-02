#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v, bool dir = false)
{
    if (dir == false)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    else
    {
        adj[u].push_back(v);
    }
}

void showGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; ++i)
    {
        cout << i << "-> ";
        for (auto y : adj[i])
            cout << y << " ";
        cout << endl;
    }
}

// B  F  S
void bfs(vector<int> adj[], int v, int s, bool visited[])
{
    // bool visited[v] = {0};

    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void bfsDis(vector<int> adj[], int v)
{
    bool visited[v] = {0};

    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == false)
            bfs(adj, v, i, visited);
    }
}

int connectedComp(vector<int> adj[], int v)
{
    bool visited[v] = {0};
    int con = 0;
    for (int i = 0; i < v; ++i)
    {
        if (visited[i] == false)
        {
            bfs(adj, v, i, visited);
            ++con;
        }
    }

    return con;
}

// D  F  S
void dfsRec(vector<int> adj[], int v, int s, bool visited[])
{
    cout << s << " ";
    visited[s] = true;
    for (auto u : adj[s])
        if (visited[u] == false)
            dfsRec(adj, v, u, visited);
}
void dfs(vector<int> adj[], int v)
{
    bool visited[v] = {0};
    for (int i = 0; i < v; ++i)
        if (visited[i] == false)
            dfsRec(adj, v, i, visited);
}