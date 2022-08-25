#include <iostream>
#include <vector>

using namespace std;

int lomuto(vector<int> &arr, int l, int r)
{
    int p = l;

    for (int i = l; i < arr.size() - 1; ++i)
    {
        if (arr[i] < arr[r])
        {
            swap(arr[p], arr[i]);
            ++p;
        }
    }

    swap(arr[p], arr[r]);

    return p;
}
void qsort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int p = lomuto(arr, l, r);
        qsort(arr, l, p - 1);
        qsort(arr, p + 1, r);
    }
}

int main()
{
    vector<int> arr = {5, 5, 5, 5, 5, 4};
    qsort(arr, 0, 5);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}