#include <iostream>
#include <vector>
#include <climits>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void reverseEdge(vector<int> adj[], vector<int> revAdj[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        for (auto u : adj[i])
            addEdge(revAdj, u, i);
    }
}

void dfsRec(vector<int> adj[], int s, bool visited[], stack<int> &st)
{
    visited[s] = true;

    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            dfsRec(adj, u, visited, st);
        }
    }

    st.push(s);
}

vector<int> dfs(vector<int> adj[], int V)
{
    stack<int> st;
    vector<int> dfsArr;
    bool vis[V] = {false};

    // dfsRec(adj, 2, vis, st);
    for (int i = 0; i < V; ++i)
    {
        if (vis[i] == false)
            dfsRec(adj, i, vis, st);
    }

    while (st.empty() == false)
    {
        cout << (char)('A' + st.top()) << " ";
        dfsArr.push_back(st.top());
        st.pop();
    }

    return dfsArr;
}

void kosaRajuDFS(vector<int> adj[], int s, bool visited[], vector<int> &connected)
{
    visited[s] = true;
    connected.push_back(s);
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            kosaRajuDFS(adj, u, visited, connected);
        }
    }
}
vector<vector<int>> kosaRaju(vector<int> adj[], int V, vector<int> dfsArr)
{
    vector<vector<int>> connectedComponents;
    bool visited[V] = {false};

    for (auto n : dfsArr)
    {
        vector<int> connected;
        if (visited[n] == false)
        {
            kosaRajuDFS(adj, n, visited, connected);
        }
        for (auto x : connected)
            cout << (char)('A' + x) << " ";
        if (connected.size())
            cout << endl;
        connectedComponents.push_back(connected);
    }

    return connectedComponents;
}

int main()
{
    int V = 6;
    vector<int> adj[V];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 4);

    vector<int> dfsArr = dfs(adj, V);

    vector<int> revAdj[V];

    reverseEdge(adj, revAdj, V);
    cout << "\n\nKosaraju Second traversal\n";
    kosaRaju(revAdj, V, dfsArr);
    return 0;
}