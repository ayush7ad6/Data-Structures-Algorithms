#include <iostream>
#include <vector>

using namespace std;

void moveZerostoEnd(vector<int> &arr)
{
    int nonZeroInd = 0;

    for (auto i = 0; i < arr.size(); ++i)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[nonZeroInd++]);
        }
    }

    for (int i = nonZeroInd + 1; i < arr.size(); ++i)
        arr[i] = 0;

    for (auto &i : arr)
        cout << i << " ";
}

int main()
{
    vector<int> arr = {0, 0, 8, 5, 0, 10, 0, 20};

    moveZerostoEnd(arr);
    return 0;
}