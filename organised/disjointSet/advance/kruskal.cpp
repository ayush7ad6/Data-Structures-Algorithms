#include <bits/stdc++.h>
#include "..\unioByRank.cpp"

using namespace std;

struct edge
{
    int s, d;
    int wt;
    edge(int src, int dest, int weigth)
    {
        s = src;
        d = dest;
        wt = weigth;
    }
};

void addEdge(vector<edge> &edges, int u, int v, int wt)
{
    edge e(u, v, wt);
    edges.push_back(e);
}

void show(vector<edge> e)
{
    for (auto edge : e)
        cout << edge.s << " " << edge.d << " " << edge.wt << endl;
}

// sortin the edges vector based on the weigth

bool compareEdge(edge e1, edge e2)
{
    return e1.wt < e2.wt;
}

// kruskal

int kruskal(vector<edge> edges, int V)
{
    int res = 0;
    int count = 0;
    UnionByRank unionFind(V);

    sort(edges.begin(), edges.end(), compareEdge);

    for (auto e : edges)
    {
        if (unionFind.find(e.d) != unionFind.find(e.s))
        {
            res += e.wt;
            ++count;
            unionFind.unionSet(e.d, e.s);
        }
        if (count == V - 1)
            return res;
    }

    return -1;
}

int main()
{
    vector<edge> edges;
    addEdge(edges, 0, 1, 5);
    addEdge(edges, 0, 4, 1);
    addEdge(edges, 0, 3, 9);
    addEdge(edges, 1, 2, 3);
    addEdge(edges, 1, 3, 1);
    addEdge(edges, 2, 4, 7);
    addEdge(edges, 2, 3, 14);
    show(edges);

    cout << endl
         << endl;
    // sort(edges.begin(), edges.end(), compareEdge);
    // show(edges);
    cout << kruskal(edges, 5);
    return 0;
}