#include <bits/stdc++.h>

using namespace std;

/// lomuto paritioning

int lomuto(vector<int> &arr, int l, int r)
{
    int pivot = arr[r];
    int p = l - 1;

    for (int i = l; i < r - 1; ++i)
    {
        if (arr[i] < pivot)
        {
            ++p;
            swap(arr[i], arr[p]);
        }
    }

    swap(arr[p + 1], arr[r]);

    return p + 1;
}
////////////quick sort

void qSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int p = lomuto(arr, l, r);
    qSort(arr, l, p - 1);
    qSort(arr, p + 1, r);
}
//////////Counting sort

void countingSort(vector<int> &arr, int n, int k)
{
    int count[k] = {0};

    for (auto i : arr)
    {
        count[i]++;
    }

    int ind = 0;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < count[i]; ++j)
        {
            arr[ind++] = i;
        }
    }

    return;
}