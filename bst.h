

struct bst
{
    int key;
    bst *left;
    bst *right;
    bst(int x)
    {
        key = x;
        left = right = NULL;
    }

};

bst *insert(bst *root, int x)        //insert node
{

    if(root == NULL)
        return new bst(x);

    if(root->key > x)
    {
        return root->left = insert(root->left, x);
    }
    else if(root->key < x)
        return root->right = insert(root->right, x);
}


bool search(bst *tree, int x)
{
    if(tree == NULL)
        return false;

    if(tree->key > x)
    {
        return search(tree->left, x);
    }
    else if(tree->key < x)
        return search(tree->right, x);
    else
        return true;
}


