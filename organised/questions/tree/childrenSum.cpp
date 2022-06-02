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

bool isChildrenSum(TreeNode *root)
{
    if (root == NULL)
        return true;
    int lc = root->left ? root->left->val : 0;
    int rc = root->right ? root->right->val : 0;

    if ((root->left == NULL && root->right == NULL) || (root->val == (lc + rc)))
    {
        return isChildrenSum(root->left) && isChildrenSum(root->right);
    }
    cout << root->val << " ";
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);

    cout << isChildrenSum(root);
    return 0;
}