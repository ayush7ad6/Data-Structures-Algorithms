#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int s, d, w;

    edge(int src, int dest, int wt)
    {
        s = src;
        d = dest;
        w = wt;
    }
};

void addEdge(vector<pair<int, int>> e[], int u, int v, int w)
{
    // edge eg(u, v, w);
    e[u].push_back({v, w});
    e[v].push_back({u, w});
}

vector<int> dijkstra(vector<pair<int, int>> adj[], int V, int s)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    pq.push({0, s});
    // for (int i = 0; i < V; ++i)
    // {
    //     if (i != s)
    //         pq.push({INT_MAX, i});
    // }

    int vis[V] = {0};
    int changed = 1;

    while (pq.empty() == false)
    {
        auto curr = pq.top();
        cout << curr.first << " " << curr.second << endl;
        pq.pop();
        if (vis[curr.second] == 1)
        {
            cout << curr.second << " popped" << endl;
            continue;
        }

        vis[curr.second] = 1;
        changed = 0;
        for (auto u : adj[curr.second])
        {
            if (vis[u.first] == 0 && ((dist[curr.second] + u.second) < dist[u.first]))
            {
                cout << "changed " << u.first << " from " << dist[u.first] << " to ";
                dist[u.first] = dist[curr.second] + u.second;
                cout << dist[u.first] << endl;
                pq.push({dist[u.first], u.first});
            }
        }
        // for (int i = 0; i < V; ++i)
        //     if (vis[i] == 0)
        //         changed = 1;
    }

    return dist;
}

int main()
{
    int V = 9;
    vector<pair<int, int>> edges[V];
    addEdge(edges, 0, 1, 4);
    addEdge(edges, 0, 2, 8);
    addEdge(edges, 1, 2, 11);
    addEdge(edges, 1, 3, 8);
    addEdge(edges, 2, 4, 7);
    addEdge(edges, 2, 5, 1);
    addEdge(edges, 3, 4, 2);
    addEdge(edges, 3, 6, 7);
    addEdge(edges, 3, 7, 4);
    addEdge(edges, 4, 5, 6);
    addEdge(edges, 5, 7, 2);
    addEdge(edges, 6, 7, 14);
    addEdge(edges, 6, 8, 9);
    addEdge(edges, 7, 8, 10);

    for (auto i : edges)
    {
        for (auto v : i)
        {
            cout << v.first << " " << v.second << "   ";
        }
        cout << endl;
    }

    cout << endl
         << endl;

    vector<int> dist = dijkstra(edges, V, 0);
    cout << endl
         << endl;
    for (auto i : dist)
        cout << i << " ";

    return 0;
}