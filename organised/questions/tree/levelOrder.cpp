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

void levelOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (q.empty() == false)
    {
        int n = q.size();
        for (int i = 0; i < n; ++i)
        {
            auto curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
        cout << endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    // root->left->/ = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    levelOrder(root);
    return 0;
}