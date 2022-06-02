#include <bits/stdc++.h>

using namespace std;

// C Y C L E   D E T E C T I O N
bool cyclePresentDirRec(vector<int> adj[], int s, bool visited[], bool recStack[])
{
    visited[s] = true;
    recStack[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false)
        {
            if (cyclePresentDirRec(adj, u, visited, recStack) == true)
                return true;
        }
        else if (recStack[u] == true)
            return true;
    }
    recStack[s] = false;
    return false;
}

bool cyclePresentDir(vector<int> adj[], int V)
{
    bool visited[V] = {0};
    bool recStack[V] = {0};
    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false)
        {
            if (cyclePresentDirRec(adj, i, visited, recStack) == true)
            {
                cout << "AT: " << i;
                return true;
            }
        }
    }

    return false;
}
// C Y C L E   D E T E C T I O N   K A H N ' S
bool cyclePresentKahn(vector<int> adj[], int V)
{
    int indegree[V] = {0};
    for (int i = 0; i < V; ++i)
    {
        for (auto x : adj[i])
            ++indegree[x];
    }

    // for (auto x : indegree)
    //     cout << x << " ";
    // cout << endl;

    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            // cout << i << " added to q\t ";
        }
    }
    int count = 0;
    // ++count;
    while (q.empty() == false)
    {
        auto v = q.front();
        q.pop();
        ++count;
        for (auto u : adj[v])
        {
            --indegree[u];
            if (indegree[u] == 0)
            {
                q.push(u);
            }
        }
    }

    return count != V;
}

// T O P O L O G I C A L   S O R T I N G
void topologicalBFS(vector<int> adj[], int V)
{
    int indegree[V] = {0};
    for (int i = 0; i < V; ++i)
    {
        for (auto u : adj[i])
            ++indegree[u];
    }

    queue<int> q;
    for (auto i = 0; i < V; ++i)
        if (indegree[i] == 0)
            q.push(i);

    while (q.empty() == false)
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (auto u : adj[v])
        {
            --indegree[u];
            if (indegree[u] == 0)
                q.push(u);
        }
    }
}

// T O P O L O G I C A L   S O R T I N G DFS
void topologicalRec(vector<int> adj[], int s, bool visited[], stack<int> &tpStack)
{
    visited[s] = true;
    for (auto u : adj[s])
    {
        if (visited[u] == false)
            topologicalRec(adj, u, visited, tpStack);
    }

    tpStack.push(s);
}
void topologicalDFS(vector<int> adj[], int V)
{
    stack<int> tpstack;
    bool visited[V] = {0};
    for (int i = 0; i < V; ++i)
        if (visited[i] == false)
            topologicalRec(adj, i, visited, tpstack);

    while (tpstack.empty() == false)
    {
        cout << tpstack.top() << " ";
        tpstack.pop();
    }
}