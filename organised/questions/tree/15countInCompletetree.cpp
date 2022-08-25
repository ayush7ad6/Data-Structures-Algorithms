#include <bits/stdc++.h>
#include "tree.cpp"

using namespace std;

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    TreeNode *temp = root;
    int lh = 0;
    while (temp)
    {
        ++lh;
        temp = temp->left;
    }

    temp = root;
    int rh = 0;
    while (temp)
    {
        ++rh;
        temp = temp->right;
    }

    if (lh == rh)
        return pow(2, lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(20);
    // root->right = new TreeNode(30);

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

    cout << countNodes(root);
    return 0;
}
