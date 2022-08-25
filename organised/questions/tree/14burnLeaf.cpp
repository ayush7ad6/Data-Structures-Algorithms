#include <bits/stdc++.h>
#include "tree.cpp"

using namespace std;

bool findPath(TreeNode *root, int leaf, vector<TreeNode *> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root);
    if (root->val == leaf)
        return true;

    if (findPath(root->left, leaf, path) || findPath(root->right, leaf, path))
        return true;

    path.pop_back();
    return false;
}

int height(TreeNode *root, TreeNode *prev)
{
    if (root == NULL)
        return 0;
    if (root == prev)
        return 0;

    return 1 + max(height(root->left, prev), height(root->right, prev));
}

int burnLeaf(TreeNode *root, int leaf)
{
    vector<TreeNode *> path;

    findPath(root, leaf, path);
    int n = path.size() - 2;
    cout << "N: " << path.size() << endl;
    for (auto x : path)
        cout << x->val << " ";

    cout << endl;
    int ans = 0, curr;
    for (int i = 0; i < path.size() - 1; ++i)
    {
        curr = (height(path[i], path[i + 1]));
        cout << curr << " ";
        ans = max(curr + n, ans);
        --n;
    }

    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    // root->right = new TreeNode(30);

    root->left->left = new TreeNode(40);
    // root->left->right = new TreeNode(50);

    // root->right->left = new TreeNode(40);
    // root->right->left->left = new TreeNode(60);

    root->left->left->left = new TreeNode(10);
    root->left->left->right = new TreeNode(50);
    root->left->left->left = new TreeNode(40);
    root->left->left->left->left = new TreeNode(60);
    root->left->left->left->left->left = new TreeNode(60);

    // root->right->right = new TreeNode(60);
    // root->right->right->left = new TreeNode(70);
    // root->right->right->right = new TreeNode(80);

    // root->left->right->left = new TreeNode(12);
    // root->left->right->right = new TreeNode(13);

    cout << endl
         << endl
         << burnLeaf(root, 50);
    return 0;
}