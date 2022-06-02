#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

// O P E R A T I O N S
bool search(TreeNode *root, int val)
{
    if (root == NULL)
        return false;

    if (root->val == val)
        return true;

    if (root->val > val)
        return search(root->left, val);
    return search(root->right, val);
}

TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);

    if (root->val > val)
        root->left = insert(root->left, val);
    if (root->val < val)
        root->right = insert(root->right, val);

    return root;
}
// AUX function for delete()

TreeNode *getSuccessor(TreeNode *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}
TreeNode *del(TreeNode *root, int val)
{
    if (root == NULL)
        return root;
    if (root->val < val)
        root->right = del(root->right, val);
    else if (root->val > val)
        root->left = del(root->left, val);
    else
    {
        if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        TreeNode *temp = getSuccessor(root);
        root->val = temp->val;
        root->right = del(root->right, temp->val);
    }

    return root;
}

// T R A V E R S A L S
void inorder(TreeNode *root)
{
    // cout << "In Order Traversal: ";
    if (!root)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postorder(TreeNode *root)
{
    // cout << "Post Order Traversal: ";
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void preorder(TreeNode *root)
{
    // cout << "Pre Order Traversal: ";
    if (!root)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void levelOrder(TreeNode *root)
{
    cout << "Level Order Traversal: ";
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (q.empty() == false)
    {
        // int n = q.size();
        // for (int i = 0; i < n; ++i)
        // {

        // }
        auto temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

// S I Z E   O F    BST

int sizeBST(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + sizeBST(root->left) + sizeBST(root->right);
}

// M A X   I N    BST

int maxBST(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->val, max(maxBST(root->left), maxBST(root->right)));
}

// H E I G H T    O F   BST

int heightBST(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightBST(root->left), heightBST(root->right));
}

// I T E R A T I V E
