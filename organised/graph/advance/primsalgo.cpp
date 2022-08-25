#include <bits/stdc++.h>

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
        for (auto v : adj[i])
            cout << v.first << "-" << v.second << " ";

        cout << endl;
    }
}
vector<pair<int, int>> *primsAlgo(vector<pair<int, int>> adj[], int V)
{
    vector<pair<int, int>> *mst = new vector<pair<int, int>>[V];

    vector<int> mstArr;
    mstArr.push_back(3);

    // int edge = 0;

    while (mstArr.size() != V)
    {
        int n = mstArr.size();
        vector<int> small = {-1, -1, INT_MAX};
        for (int i = 0; i < n; ++i)
        {
            cout << mstArr[i] << "-> ";
            for (auto v : adj[mstArr[i]])
            {
                if (find(mstArr.begin(), mstArr.end(), v.first) == mstArr.end() && small[2] > v.second)
                {
                    small[0] = mstArr[i];
                    small[1] = v.first;
                    small[2] = v.second;
                }
            }
            cout << small[0] << " " << small[1] << " " << small[2] << endl;
        }
        cout << endl;
        mstArr.push_back(small[1]);
        mst[small[0]].push_back({small[1], small[2]});
		mst[small[1]].push_back({small[0], small[2]});
    }
    cout << endl;
    for (auto x : mstArr)
        cout << x << " ";
    // if (find(mstArr.begin(), mstArr.end(), 1) == mstArr.end())
    //     cout << "NO";
    cout << endl
         << endl;
    return mst;
}

int main()
{
    int V = 4;
    vector<pair<int, int>> adj[V];

    addEdge(adj, 0, 1, 1);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 0, 3, 2);
    addEdge(adj, 1, 3, 3);
    addEdge(adj, 3, 2, 5);
    show(adj, V);
    cout << endl
         << endl;
    vector<pair<int, int>> *mst;

    mst = primsAlgo(adj, V);
    for (int i = 0; i < V; ++i)
    {
        cout << i << "-> ";
        for (auto v : mst[i])
            cout << v.first << "-" << v.second << " ";
        cout << endl;
    }
    return 0;
}