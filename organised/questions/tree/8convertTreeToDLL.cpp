#include <bits/stdc++.h>
#include "tree.cpp"

using namespace std;

TreeNode *previous = NULL;

TreeNode *treeToDLL(TreeNode *root)
{
    if (root == NULL)
        return root;

    TreeNode *head = treeToDLL(root->left);
    if (previous == NULL)
        head = root;
    else
    {
        root->left = previous;
        previous->right = root;
    }
    previous = root;
    treeToDLL(root->right);
    return head;
}
// TreeNode* prev = NULL;
TreeNode *practice(TreeNode *root)
{
    if (!root)
        return NULL;

    TreeNode *head = practice(root->left);

    if (previous == NULL)
        head = root;
    else
    {
        root->left = previous;
        previous->right = root;
    }

    previous = root;
    practice(root->right);
    return head;
}
int main()
{
    vector<TreeNode *> arr;
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
    TreeNode *dll;
    // dll = treeToDLL(root);
    dll = practice(root);
    while (dll)
    {
        cout << dll->val << " ";
        dll = dll->right;
    }
    return 0;
}