#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode()
    {
        val = 0;
        left = right = NULL;
    }
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }

    TreeNode(int x, TreeNode *l, TreeNode *r)
    {
        val = x;
        left = l;
        right = r;
    }
};

TreeNode *ceil(TreeNode *root, int x)
{
    if (!root)
        return NULL;

    int r = root->val;

    if (r >= x)
    {
        auto sub = ceil(root->left, x);
        if (sub && sub->val < r)
            return sub;
        return root;
    }

    return ceil(root->right, x);
}

TreeNode *ceil_itr(TreeNode *root, int x)
{
    if (!root)
        return NULL;
    TreeNode *curr = NULL;
    while (root)
    {
        if (root->val == x)
            return root;
        if (root->val > x)
        {
            curr = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return curr;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(30);
    // root->left->left = new TreeNode(4);
    // root->left->/ = new TreeNode(5);
    // root->left->left->left = new TreeNode(6);
    // root->left->left->right = new TreeNode(7);

    // auto ans = ceil(root, 3);
    auto ans = ceil_itr(root, 3);
    if (ans)
        cout << ans->val << endl;
    else
        cout << "NULL";
    return 0;
}