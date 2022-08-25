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
int kthsmallest(vector<int> &arr, int k)
{
    int begin = 0, end = arr.size() - 1;
    while (end >= begin)
    {
        int p = lomuto(arr, begin, end);
        if (p == k - 1)
            return p;

        if (p > k - 1)
            end = p - 1;
        else
            begin = p + 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int i = kthsmallest(arr, 56);
    cout << i << endl;
    if (i >= 0)
        cout << arr[i];
    return 0;
}