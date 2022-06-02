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
int maxlevel = 0;
void leftView(TreeNode *root, int level = 1)
{
    if (root == NULL)
        return;
    if (level > maxlevel)
    {
        cout << root->val << " ";
        maxlevel = level;
    }
    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // root->left->left->left = new TreeNode(10);
    // root->left->left->right = new TreeNode(11);

    // root->left->right->left = new TreeNode(12);
    // root->left->right->right = new TreeNode(13);

    // printKthLevel(root, 3);
    leftView(root);
    return 0;
}