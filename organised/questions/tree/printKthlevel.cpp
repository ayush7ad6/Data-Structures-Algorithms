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

void levelOrder(TreeNode *root, int k)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    int kth = 0;
    while (q.empty() == false)
    {
        int n = q.size();
        ++kth;
        for (int i = 0; i < n; ++i)
        {
            auto curr = q.front();
            q.pop();
            if (k == kth)
                cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
        if (k == kth)
            break;
        cout << endl;
    }
}

void printKthLevel(TreeNode *root, int k, int n = 0)
{
    if (root == NULL)
        return;
    if (k == n)
    {
        cout << root->val << " ";
    }
    else
    {
        printKthLevel(root->left, k, n + 1);
        printKthLevel(root->right, k, n + 1);
    }
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

    printKthLevel(root, 2);
    return 0;
}