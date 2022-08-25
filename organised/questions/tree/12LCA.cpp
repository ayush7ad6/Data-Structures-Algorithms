#include <bits/stdc++.h>
#include "tree.cpp"
using namespace std;
int lcaOpt(TreeNode *root, int a, int b)
{
    if (root == NULL)
        return -1;

    if (root->val == a || root->val == b)
        return root->val;

    int l = lcaOpt(root->left, a, b);
    int r = lcaOpt(root->right, a, b);

    if (l != -1 && r != -1)
        return root->val;
    if (l == -1)
        return r;
    return l;
}
bool findPath(TreeNode *root, int a, vector<int> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root->val);

    if (root->val == a)
    {
        return true;
    }

    if (findPath(root->left, a, path) || findPath(root->right, a, path))
        return true;

    path.pop_back();
    return false;
}
int lca(TreeNode *root, int a, int b)
{
    vector<int> p1, p2;
    findPath(root, a, p1);
    findPath(root, b, p2);

    for (int i = 0; i < p1.size() - 1 && i < p2.size() - 1; ++i)
    {
        if (p1[i + 1] != p2[i + 1])
            return p1[i];
    }

    return -1;
}

bool practice(TreeNode *root, int x, vector<int> &path)
{
    if (!root)
        return false;

    path.push_back(root->val);
    if (root->val == x)
        return true;

    if (practice(root->left, x, path) || practice(root->right, x, path))
        return true;

    path.pop_back();

    return false;
}
int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);

    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(40);
    root->right->left->left = new TreeNode(60);

    // root->left->left->left = new TreeNode(10);
    // root->left->left->right = new TreeNode(11);

    root->right->right = new TreeNode(50);
    root->right->right->left = new TreeNode(70);
    root->right->right->right = new TreeNode(80);

    // root->left->right->left = new TreeNode(12);
    // root->left->right->right = new TreeNode(13);

    // cout << lcaOpt(root, 60, 80);
    vector<int> path;
    practice(root, 40, path);
    for (auto i : path)
        cout << i << " ";
    return 0;
}