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

TreeNode *floor(TreeNode *root, int x)
{
    if (!root)
        return NULL;

    int r = root->val;

    if (r <= x)
    {
        auto sub = floor(root->right, x);
        if (sub && sub->val > r)
            return sub;
        return root;
    }

    return floor(root->left, x);
}

TreeNode *floor_itr(TreeNode *root, int x)
{
    if (!root)
        return NULL;
    TreeNode *curr = NULL;
    while (root)
    {
        if (root->val == x)
            return root;
        if (root->val < x)
        {
            curr = root;
            root = root->right;
        }
        else
        {
            root = root->left;
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

    // auto ans = floor(root, 35);
    auto ans = floor_itr(root, 30);
    if (ans)
        cout << ans->val << endl;
    else
        cout << "NULL";
    return 0;
}