#include <bits/stdc++.h>
#include "tree.cpp"

using namespace std;

int ans = 0;
int diameter(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int l = diameter(root->left);
    int r = diameter(root->right);
    int h = 1 + max(l, r);
    ans = max(ans, 1 + l + r);

    return h;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    root->left->left->left = new TreeNode(10);
    root->left->left->right = new TreeNode(11);

    root->left->right->left = new TreeNode(12);
    root->left->right->right = new TreeNode(13);

    cout << diameter(root);
    cout << endl
         << ans;
    return 0;
}