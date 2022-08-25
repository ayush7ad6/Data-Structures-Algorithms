#include <bits/stdc++.h>
#include "tree.cpp"
using namespace std;

TreeNode *makeTree(vector<int> preorder, vector<int> inorder)
{
    if (preorder.size() == 0)
        return NULL;
    if (preorder.size() == 1)
        return new TreeNode(preorder[0]);

    int r = preorder[0];
    int rInd = find(inorder.begin(), inorder.end(), r) - inorder.begin();

    vector<int> leftIn(inorder.begin(), inorder.begin() + rInd);
    vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + rInd);

    vector<int> rightIn(inorder.begin() + rInd + 1, inorder.end());
    vector<int> rightPre(preorder.begin() + rInd + 1, preorder.end());

    cout << "leftInorder: ";
    for (auto i : leftIn)
        cout << i << " ";

    cout << endl;
    cout << "LeftPre: ";
    for (auto i : leftPre)
        cout << i << " ";
    cout << endl;

    cout << "rightInorder: ";
    for (auto i : rightIn)
        cout << i << " ";

    cout << endl;
    cout << "rightPre: ";
    for (auto i : rightPre)
        cout << i << " ";
    cout << endl
         << endl
         << endl;

    TreeNode *root = new TreeNode(r);
    root->left = makeTree(leftPre, leftIn);
    root->right = makeTree(rightPre, rightIn);

    return root;
}
int pInd = 0;
TreeNode *makeTree(int pre[], int in[], int l, int r)
{
    if (l > r)
        return NULL;
    TreeNode *root = new TreeNode(pre[pInd++]);
    int ind;
    for (int i = l; i <= r; ++i)
    {
        if (in[i] == root->val)
        {
            ind = i;
            break;
        }
    }

    root->left = makeTree(pre, in, l, ind - 1);
    root->right = makeTree(pre, in, ind + 1, r);

    return root;
}
int main()
{
    int preorder[] = {1, 2, 3, 4, 5, 6, 7};
    int inorder[] = {3, 2, 4, 1, 6, 5, 7};
    TreeNode *root = makeTree(preorder, inorder, 0, 6);
    showTree(root);

    return 0;
}