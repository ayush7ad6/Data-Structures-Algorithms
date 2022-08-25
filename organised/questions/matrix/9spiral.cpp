#include <iostream>
#include <vector>

using namespace std;

void spiral(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    // cout << "size: " << n;
    int top = 0, right = m - 1, bottom = n - 1, left = 0;
    int i = 0, j = 0;
    while (top <= bottom && right >= left)
    {
        // cout << top << " " << right << " " << bottom << " " << left << endl;
        while (j <= right)
        {
            cout << arr[i][j] << " ";
            ++j;
        }
        ++top;

        --j;
        ++i;
        while (i <= bottom)
        {
            cout << arr[i][j] << " ";
            ++i;
        }
        --right;

        --i;
        --j;
        while (j >= left)
        {
            cout << arr[i][j] << " ";
            --j;
        }
        ++bottom;

        ++j;
        --i;
        while (i >= top)
        {
            cout << arr[i][j] << " ";
            --i;
        }
        --left;
        ++i;
        ++j;
    }
}

int main()
{
    // vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> arr = {{1, 2, 3, 4, 5}};
    // int n = arr.size();

    spiral(arr);
    return 0;
}