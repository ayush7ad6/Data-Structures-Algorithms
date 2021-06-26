#include <stack>

struct tri
{
    int key;
    tri *left, *right;
    tri(int x)
    {
        key = x;
        left = right = NULL;
    }
};

//////////////////////////////////////////////////

void inorder(tri *root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);

}

void preorder(tri *root)
{
    if(root == NULL)
    {
        return;
    }

    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(tri *root)
{
    if(root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";

}

int getSize(tri *root)
{
    if(root == NULL)
        return 0;
    return 1+getSize(root->left) + getSize(root->right);
}


int getMax(tri *root)                           //get the maximum element
{
    if(root == NULL)
        return INT_MIN;
    int res = root->key;

    if(res>=getMax(root->left) && res>=getMax(root->right))
        return res;
    else if(getMax(root->left)>=res && getMax(root->left)>=getMax(root->right))
        return getMax(root->left);
    else if(getMax(root->right)>=res && getMax(root->right)>=getMax(root->left))
        return getMax(root->right);


}


int getHeight(tri *root)                            //get height of the tree
{
    if(root == NULL)
        return 0;
    return 1 + max(getHeight(root->left),getHeight(root->right));
}


void iInorder(tri *root)
{
    stack<tri*> s;
    tri *temp = root;
    while(temp!=NULL || s.empty()==false)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        cout<<temp->key<<" ";
        temp = temp->right;

    }
}


void iPreorder(tri *root)
{
    stack<tri*> s;
    tri *temp = root;
    while(temp!=NULL || s.empty()==false)
    {
        while(temp!=NULL)
        {
            cout<<temp->key<<" ";
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        temp = temp->right;

    }
}/////////////B I N A R Y  S E A R C H  T R E E/////////////////////////////////////////////////



tri *insert(tri *root, int x)        //insert node
{

    if(root == NULL)
        return new tri(x);

    if(root->key > x)
    {
        root->left = insert(root->left, x);
    }
    else if(root->key < x)
        root->right = insert(root->right, x);
    return root;
}

tri *iInsert(tri *root, int x)                          //iterative insert B E T T E R
{
    //cout<<x<<" ";
    tri *add = new tri(x);
    tri *temp = root;
    tri *curr = NULL;              //to keep the last visited node
    //cout<<x<<" ";
    while(temp!=NULL)
    {
        curr = temp;
        if(temp->key > x)
        {
            temp = temp ->left;
        }

        else if(temp->key < x)
        {
            temp = temp -> right;
        }
        else return root;
    }
    //cout<<x<<" ";
    if(curr == NULL)
        return add;
    else if(curr -> key > x)
        curr->left = add;
    else if(curr -> key < x)
        curr->right = add;
    else return root;
}

bool search(tri *tree, int x)                   //recursive search
{
    if(tree == NULL)
        return false;

    if(tree->key > x)
        return search(tree->left, x);
    else if(tree->key < x)
        return search(tree->right, x);
    else
        return true;
}

bool iSearch(tri *root, int x)              //iterative search
{
    if(root == NULL)
        return false;
    tri *temp = root;
    while(temp!=NULL)
    {
        if(temp->key == x)
            return true;
        else if(temp -> key > x)
            temp = temp->left;
        else if(temp ->key <x)
            temp = temp->right;
    }
    return false;
}


tri *getSucc(tri *root)                         //get successor
{
    root = root->right;
    while(root!=NULL && root->left!=NULL)
        root = root ->left;
    return root;
}

tri *Delete(tri *root, int x)                   //delete a node
{
    if(root==NULL)
        return root;
    tri *curr = root;
    if(root->key > x)
        root->left = Delete(root->left, x);
    else if(root->key < x)
        root ->right = Delete(root->right,x);
    else
    {
        if(root->left == NULL)
        {
            tri *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left == NULL)
        {
            tri *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            tri *succ = getSucc(root);
            root->key = succ->key;
            root->right = Delete(root->right, succ->key);
        }
    }

}
