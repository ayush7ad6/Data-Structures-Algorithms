#include <bits/stdc++.h>

using namespace std;

int rBinarySearch(vector<int> &arr, int l, int r, int val)
{
    int mid = r - (l + r) / 2;

    if (arr[mid] == val)
        return mid;

    if (arr[mid] > val)
        return rBinarySearch(arr, l, mid - 1, val);

    return rBinarySearch(arr, mid + 1, r, val);
}
