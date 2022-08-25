#include <bits/stdc++.h>
#include "tree.cpp"

using namespace std;

void spiralTree(TreeNode *root)
{
    if (root == NULL)
        return;

    stack<TreeNode *> s, t;
    s.push(root);
    while (!s.empty() || !t.empty())
    {

        while (s.empty() == false)
        {
            cout << s.top()->val << " ";
            if (s.top()->left)
                t.push(s.top()->left);
            if (s.top()->right)
                t.push(s.top()->right);

            s.pop();
        }

        while (t.empty() == false)
        {
            cout << t.top()->val << " ";
            if (t.top()->right)
                s.push(t.top()->right);
            if (t.top()->left)
                s.push(t.top()->left);

            t.pop();
        }
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

    spiralTree(root);

    return 0;
}
