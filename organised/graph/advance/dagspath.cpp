#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
}

vector<int> kahnAlgo(vector<vector<int>> adj[], int V)
{
    int indegree[V] = {0};
    vector<int> topologicalSort;

    for (int i = 0; i < V; ++i)
    {
        for (auto v : adj[i])
            ++indegree[v[0]];
    }

    queue<int> q;

    for (int i = 0; i < V; ++i)
        if (indegree[i] == 0)
            q.push(i);

    while (q.empty() == false)
    {
        auto curr = q.front();
        q.pop();
        topologicalSort.push_back(curr);
        for (auto v : adj[curr])
        {
            --indegree[v[0]];
            if (indegree[v[0]] == 0)
                q.push(v[0]);
        }
    }

    return topologicalSort;
}

int *shortestPathDAG(vector<vector<int>> adj[], vector<int> tp, int s, int V)
{
    int *dist = new int[V];
    for (int i = 0; i < V; ++i)
        dist[i] = INT_MAX;
    dist[s] = 0;

    for (auto u : tp)
    {
        if (dist[u] == INT_MAX)
            continue;
        for (auto v : adj[u])
        {
            cout << dist[u] << " ";
            if ((dist[u] + v[1]) < dist[v[0]])
                dist[v[0]] = dist[u] + v[1];
        }
    }

    return dist;
}

int main()
{
    int V = 6;
    vector<vector<int>> adj[V];

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 5, 3, 1);

    vector<int> tpsort = kahnAlgo(adj, V);

    for (auto x : tpsort)
        cout << x << " ";
    cout << endl;
    int *dist;

    dist = shortestPathDAG(adj, tpsort, 4, V);
    cout << endl;
    for (int i = 0; i < V; ++i)
        cout << dist[i] << " ";
    cout << endl;
    return 0;
}