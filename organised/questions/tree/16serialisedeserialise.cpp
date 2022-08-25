#include <bits/stdc++.h>
#include "tree.cpp"
using namespace std;

void serialise(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(-1);
        return;
    }

    arr.push_back(root->val);
    serialise(root->left, arr);
    serialise(root->right, arr);
}
TreeNode *head = NULL;
int ind = 0;
TreeNode *deserialise(vector<int> arr)
{
    if (ind == arr.size())
        return NULL;
    if (arr[ind] == -1)
    {
        ind++;
        return NULL;
    }

    TreeNode *root = new TreeNode(arr[ind]);
    ++ind;
    root->left = deserialise(arr);
    root->right = deserialise(arr);

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);

    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(50);

    // root->right->left = new TreeNode(40);
    // root->right->left->left = new TreeNode(60);

    // root->left->left->left = new TreeNode(10);
    // root->left->left->right = new TreeNode(50);
    // root->left->left->left = new TreeNode(40);
    // root->left->left->left->left = new TreeNode(60);
    // root->left->left->left->left->left = new TreeNode(60);

    // root->right->right = new TreeNode(60);
    // root->right->right->left = new TreeNode(70);
    // root->right->right->right = new TreeNode(80);

    // root->left->right->left = new TreeNode(12);
    // root->left->right->right = new TreeNode(13);

    vector<int> arr;
    serialise(root, arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl
         << endl;
    root = deserialise(arr);
    arr.clear();
    serialise(root, arr);

    for (auto i : arr)
        cout << i << " ";
    cout << endl
         << endl;

    showTree(root);
    return 0;
}