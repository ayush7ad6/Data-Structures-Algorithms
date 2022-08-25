#include <iostream>
#include <vector>

using namespace std;

void transpose(int **arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{
    int **arr;
    int n = 4;
    int val = 1;

    arr = new int *[n];
    for (auto i = 0; i < n; ++i)
    {
        arr[i] = new int[n];
        for (auto j = 0; j < n; ++j)
        {
            arr[i][j] = val++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    transpose(arr, n);
    for (auto i = 0; i < n; ++i)
    {
        // arr[i] = new int[n];
        for (auto j = 0; j < n; ++j)
        {
            // arr[i][j] = val++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}