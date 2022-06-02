#include "searching.cpp"
#include "sorting.cpp"
#include "linkedlist.cpp"
#include "Tree/bst.cpp"
#include "Tree/heap.cpp"
#include "Graph/graph.h"
#include "Graph/undirected.h"
#include "Graph/directed.h"

using namespace std;

int main()
{
    // TreeNode *root = new TreeNode(1);
    // root = insert(root, 4);
    // root = insert(root, 2);
    // root = insert(root, 5);
    // root = insert(root, 3);
    // root = insert(root, 6);
    // inorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // preorder(root);
    // cout << endl;
    // levelOrder(root);
    // insert(root, 1111);
    // cout << "\nSize of BST: " << sizeBST(root);
    // cout << "\nMax in BST: " << maxBST(root);
    // cout << "\nHeight of BST: " << heightBST(root);

    // H E A P

    // minHeap mh;
    // mh.insert(1);
    // mh.insert(10);
    // mh.insert(2);
    // mh.insert(3);
    // mh.insert(45);
    // mh.insert(23);
    // mh.insert(-1);
    // // cout << mh.getSize();
    // mh.print();
    // cout << endl;
    // mh.insertAt(0, 1000);
    // mh.print();
    // mh.minHeapify(0);
    // cout << endl;
    // mh.print();
    // cout << endl;
    // mh.extractMin();
    // mh.print();
    // cout << endl;

    // mh.decreaseKey(3, -111);
    // mh.print();
    // mh.del(2);
    // cout << endl;
    // mh.print();

    // vector<int> narr = {3, 45, 21, 3, -1, 23323, -909, 23, 44, 22, 11, 90};
    // cout << endl;
    // buildHeap(narr);
    // for (auto x : narr)
    //     cout << x << " ";

    //                  G  R  A  P  H
    int v = 7;
    vector<int> adj[v];
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 6);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    showGraph(adj, v);
    cout << endl
         << "BFS:";
    // bfs(adj, v, 0);
    cout << endl;
    bfsDis(adj, v);
    // cout << endl;
    cout << "\nConnected Components: " << connectedComp(adj, v);

    cout << endl;
    cout << "DFS: ";
    dfs(adj, v);

    cout << endl;

    int vn = 5;
    vector<int> arr[vn];
    addEdge(arr, 0, 1, true);
    addEdge(arr, 1, 2, true);
    addEdge(arr, 2, 3, true);
    // addEdge(arr, 3, 0, true);

    addEdge(arr, 4, 2, true);
    addEdge(arr, 0, 2, true);

    // addEdge(arr, 4, 3, true);
    showGraph(arr, vn);
    // cyclePresentDir(arr, vn);
    cout << cyclePresentKahn(arr, vn);
    cout << "\nTopological Sorting: ";
    topologicalBFS(arr, vn);
    cout << endl
         << "Topological Sorting using DFS: ";
    topologicalDFS(arr, vn);
    return 0;
}