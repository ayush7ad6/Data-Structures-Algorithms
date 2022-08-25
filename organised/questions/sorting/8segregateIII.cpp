#include <iostream>
#include <vector>

using namespace std;

void oneTwoThree(vector<int> &arr)
{
    int zero = -1, two = arr.size();

    for (int i = 0; i < two; ++i)
    {
        if (arr[i] == 0)
        {
            ++zero;
            swap(arr[zero], arr[i]);
        }
        else if (arr[i] == 2)
        {
            --two;
            swap(arr[two], arr[i]);
        }

        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }

    // cout << zero << " " << two << endl;
    // for (int i = zero + 1; i < two; ++i)
    //     arr[i] = 1;
}

void threeWayPartition(vector<int> &arr, int val)
{
    int sind = -1, lind = arr.size();

    for (int i = 0; i < lind; ++i)
    {
        if (arr[i] < val)
            swap(arr[i], arr[++sind]);
        else if (arr[i] > val)
            swap(arr[i], arr[--lind]);
    }
}

void aroundRange(vector<int> &arr, int low, int high)
{
    int highInd = arr.size() - 1, lowInd = 0, mid = 0;

    while (highInd >= mid)
    {
        if (arr[mid] < low)
        {
            swap(arr[mid], arr[lowInd]);
            ++mid;
            ++lowInd;
        }
        else if (arr[mid] >= low && arr[mid] <= high)
        {
            ++mid;
        }
        else
        {
            swap(arr[mid], arr[highInd]);
            --highInd;
        }
    }
}

int main()
{
    // vector<int> arr = {0, 1, 2, 0, 0, 1};
    // oneTwoThree(arr);

    // vector<int> arr = {2, 1, 1, 2, 2, 10, 20, 30};
    // threeWayPartition(arr, 2);

    vector<int> arr = {10, 5, 6, 3, 20, 9, 40};
    aroundRange(arr, 5, 10);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}