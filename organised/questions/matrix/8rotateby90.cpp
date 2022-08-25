#include <iostream>
#include <vector>

using namespace std;

void transpose(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void rotateBy90(vector<vector<int>> &arr)
{
    int n = arr.size();
    transpose(arr);

    for (int i = 0; i < n; ++i)
    {
        int f = 0, r = n - 1;
        while (f <= r)
        {
            swap(arr[f][i], arr[r][i]);
            ++f;
            --r;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = arr.size();
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
    cout << endl;

    rotateBy90(arr);
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