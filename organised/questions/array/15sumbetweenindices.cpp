/*
    Find sum between the given indices inclusive
*/
#include <iostream>
#include <vector>

using namespace std;

int sumBetweenIndices(vector<int> arr, int x, int y)
{

    for (int i = 1; i < arr.size(); ++i)
    {
        arr[i] += arr[i - 1];
        // cout << arr[i] << " ";
    }

    // cout << endl;

    if (x == 0)
        return arr[y];

    return arr[y] - arr[x - 1];
}

int main()
{
    vector<int> arr = {2, 8, 3, 9, 6, 5, 4};
    cout << sumBetweenIndices(arr, 0, 3) << endl;
    cout << sumBetweenIndices(arr, 1, 3) << endl;
    cout << sumBetweenIndices(arr, 2, 6) << endl;
    return 0;
}