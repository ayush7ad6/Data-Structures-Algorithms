#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void showTree(TreeNode *root)
{
    if (root == NULL)
        return;

    showTree(root->left);
    cout << root->val << " ";
    showTree(root->right);
}