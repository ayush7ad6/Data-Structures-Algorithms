#include <bits/stdc++.h>
#include "tree.h"
using namespace std;

int heigth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(heigth(root->left), heigth(root->right));
}
bool isBalanced(TreeNode *root)
{

    if (root == NULL)
        return true;

    int left = heigth(root->left);
    int right = heigth(root->right);

    if (abs(left - right) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

int balanced(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int l = balanced(root->left);
    if (l == -1)
        return -1;
    int r = balanced(root->right);
    if (r == -1)
        return -1;

    if (abs(l - r) > 1)
        return -1;
    return 1 + max(l, r);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // root->right->left = new TreeNode(8);
    // root->right->right = new TreeNode(9);

    root->left->left->left = new TreeNode(10);
    root->left->left->right = new TreeNode(11);

    // root->left->right->left = new TreeNode(12);
    // root->left->right->right = new TreeNode(13);

    cout << balanced(root);
    return 0;
}