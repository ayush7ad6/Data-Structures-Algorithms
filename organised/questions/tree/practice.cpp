#include <iostream>
#include "tree.cpp"

using namespace std;

void func(TreeNode *root, int k)
{
    if (!root)
        return;

    if (k == 0)
    {
        cout << root->val << " ";
        return;
    }

    func(root->left, k - 1);
    func(root->right, k - 1);
}

int main()
{
    return 0;
}