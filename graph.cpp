#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;



//vector<int> a[5];
//    addEdge(a,0,1);
//    addEdge(a,3,2);
//    addEdge(a,3,4);
//    addEdge(a,1,3);
//    addEdge(a,2,3);
//    addEdge(a,2,4);
//    addEdge(a,3,4);
//    printAdj(a,5);
//
//    cout<<endl<<countDisrec(a,5);

void DaddEdge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
}
void addEdge(vector<int>adj[],int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void printAdj(vector<int>adj[], int v)
{
    for(int i = 0; i<v; ++i)
    {
        cout<<i<<": ";
        for(auto x : adj[i])
            cout<<x<<" ";
        cout<<endl;
    }
}
void BFS(vector<int> adj[],int v,int s)
{
    bool visited[v];
    queue<int> q;

    for(int i = 0; i<v; ++i)
        visited[i] = false;

    q.push(s);
    visited[s] = true;

    while(q.empty() == false)
    {
        int u = q.front();
        cout<<q.front()<<" ";
        q.pop();
        for(auto x : adj[u])
        {
            if(visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }

    }
}





void BFS_(vector<int> adj[], int s, bool visited[])    //follow up for BFSrec()
{
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while(q.empty() == false)
    {
        int u = q.front();
        cout<<q.front()<<" ";
        q.pop();
        for(auto x : adj[u])
        {
            if(visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }

    }
}


void BFSrec(vector<int> adj[], int v)                  //traversal without source
{
    bool visited[v];
    for(int i = 0; i<v; ++i)
        visited[i] = false;

    for(int i=0; i<v; ++i)
    {
        if(visited[i]==false)
            BFS_(adj,i,visited);
    }
    cout<<endl;
}


void countDis(vector<int> adj[], int s, bool visited[])    //follow up for ^
{
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while(q.empty() == false)
    {
        int u = q.front();
        //cout<<q.front()<<" ";
        q.pop();
        for(auto x : adj[u])
        {
            if(visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }
        }

    }
}

int countDisrec(vector<int> adj[], int v)                  //counting disconnected components
{
    bool visited[v];
    int count = 0;

    for(int i = 0; i<v; ++i)
        visited[i] = false;

    for(int i=0; i<v; ++i)
    {
        if(visited[i]==false)
        {
            count++;
            countDis(adj,i,visited);
        }

    }

    return count;
}

void DFSrec(vector<int> adj[], int s, bool visited[]) //follow up function for ^
{
    visited[s] = true;
    cout<<s<<" ";
    for(int x : adj[s])
        if(visited[x]==false)
            DFSrec(adj,x,visited);
}

void DFS(vector<int> adj[], int v)              //dfs function 1
{
    bool visited[v];
    for(int i=0; i<v; ++i)
        visited[i] = false;
    for(int j=0; j<v; ++j)
        if(visited[j]==false)
            DFSrec(adj,j,visited);
        cout<<endl;
}
bool cycleDFSrec(vector<int>adj[], int s, bool visited[], int parent) //follow up
{
    visited[s] = true;
    for(int x : adj[s])
    {
        if(visited[x]==false)
        {
            if(cycleDFSrec(adj,x,visited,s)==true)
                return true;
        }
        else if(x!=parent)
            return true;
    }
    return false;

}

bool cycleDFS(vector<int>adj[],int v)                          //detect cyle undirected
{
    bool visited[v];
    for(int i=0; i<v; ++i)
        visited[i] = false;
    for(int i=0; i<v; ++i)
        if(visited[i]==false)
            if(cycleDFSrec(adj,i,visited,-1)==true)
                return true;
    return false;
}


bool cycleDirDFSrec(vector<int> adj[],int s,bool visited[],bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for(int x : adj[s])
    {
        if(visited[x]==false && cycleDirDFSrec(adj,x,visited,recSt))
            return true;
        else if(recSt[x]==true)
            return true;
    }
    recSt[s] = false;
    return false;
}
bool cycleDirDFS(vector<int>adj[], int v)
{
    bool visited[v], recSt[v];
    for(int i=0; i<v; ++i)
    {
        visited[i] = false;
        recSt[i] = false;
    }

    for(int i=0; i<v; ++i)
        if(visited[i]== false)
            if(cycleDirDFSrec(adj,i,visited,recSt)==true)
                return true;
    return false;
}




