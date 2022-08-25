#include <iostream>

using namespace std;

int constructST(int arr[], int tree[], int ss, int se, int si)
{
    if (ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se) / 2;
    tree[si] = constructST(arr, tree, ss, mid, 2 * si + 1) + constructST(arr, tree, mid + 1, se, 2 * si + 2);

    return tree[si];
}

int getSum(int tree[], int qs, int qe, int ss, int se, int si)
{
    if (qs > se || qe < ss)
        return 0;

    if (qs <= ss && qe >= se)
        return tree[si];

    int mid = (ss + se) / 2;

    return getSum(tree, qs, qe, ss, mid, 2 * si + 1) + getSum(tree, qs, qe, mid + 1, se, 2 * si + 2);
}

void update(int tree[], int ss, int se, int i, int si, int diff)
{
    // cout << ss << " " << se << " " << si << endl;
    if (i < ss || i > se)
        return;
    // cout << si << endl;
    tree[si] = tree[si] + diff;

    if (se > ss)
    {
        int mid = (ss + se) / 2;
        update(tree, ss, mid, i, 2 * si + 1, diff);
        update(tree, mid + 1, se, i, 2 * si + 2, diff);
    }
}
int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int tree[4 * n] = {0};

    constructST(arr, tree, 0, n - 1, 0);

    for (auto i : tree)
        cout << i << " ";

    int qs = 0;
    int qe = 1;
    cout << endl
         << getSum(tree, qs, qe, 0, n - 1, 0);
    cout << endl;
    update(tree, 0, n - 1, 1, 0, -20);

    cout << endl;
    for (auto i : tree)
        cout << i << " ";
    cout << endl
         << getSum(tree, qs, qe, 0, n - 1, 0);
    return 0;
}