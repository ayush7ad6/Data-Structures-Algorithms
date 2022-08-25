#include <iostream>
#include <vector>

using namespace std;

void merge(vector<pair<int, int>> &, int, int, int, vector<int> &);

void mergeSort(vector<pair<int, int>> &arr, int l, int r, vector<int> &count)
{
    if (l >= r)
        return;

    int mid = (r + l) / 2;

    mergeSort(arr, l, mid, count);
    mergeSort(arr, mid + 1, r, count);

    merge(arr, l, mid, r, count);
}

void merge(vector<pair<int, int>> &arr, int const left, int const mid,
           int const right, vector<int> &count)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int, int>> larr(n1);
    vector<pair<int, int>> rarr(n2);

    cout << "left: ";
    for (int i = 0; i < n1; ++i)
    {
        larr[i] = arr[i + left];
        cout << larr[i].first << " ";
    }
    cout << endl
         << "right: ";

    for (int j = 0; j < n2; ++j)
    {
        rarr[j] = arr[j + mid + 1];
        cout << rarr[j].first << " ";
    }
    cout << endl
         << endl;

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (larr[i] <= rarr[j])
        {
            arr[k] = larr[i];
            ++i;
            ++k;
        }
        else
        {
            for (int x = i; x < n1; ++x)
            {
                count[arr[x].second]++;
            }
            arr[k] = rarr[j];
            ++j;
            ++k;
        }
    }

    while (i < n1)
        arr[k++] = larr[i++];

    while (j < n2)
        arr[k++] = rarr[j++];
}

int main()
{
    vector<int> arr = {20, 4, 1, 3, 5};
    // vector<int> arr = {5, 3, 1};
    int n = arr.size() - 1;
    vector<pair<int, int>> a;
    for (int i = 0; i <= n; ++i)
    {
        a.push_back({arr[i], i});
    }

    vector<int> count(arr.size(), 0);
    mergeSort(a, 0, n, count);

    for (auto i : count)
        cout << i << " ";
    return 0;
}
