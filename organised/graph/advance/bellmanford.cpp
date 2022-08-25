#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

void show(vector<pair<int, int>> adj[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        cout << i << "-> ";
        for (auto u : adj[i])
            cout << u.first << " " << u.second << "  ";
        cout << endl;
    }
}

vector<int> bellmanFord(vector<pair<int, int>> adj[], int s, int V)
{
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;

    for (int i = 0; i < V; ++i)
    {
        for (int node = 0; node < V; ++node)
        {
            for (auto u : adj[node])
            {
                if (dist[node] == INT_MAX)
                    break;
                if (dist[node] + u.second < dist[u.first])
                    dist[u.first] = dist[node] + u.second;
            }
        }
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

    show(edges, V);
    cout << endl
         << endl;
    vector<int> dist;
    dist = bellmanFord(edges, 8, V);
    cout << endl
         << endl;
    for (auto i : dist)
        cout << i << " ";
    return 0;
}