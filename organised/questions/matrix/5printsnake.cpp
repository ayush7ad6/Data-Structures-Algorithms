#include <iostream>
#include <vector>

using namespace std;

void printSnake(int **arr, int n, int m)
{
    int i = 0, j = 0;
    int right = 1;
    while ((i < n || i >= 0) && (j < m || j >= 0))
    {
        if (right)
        {
            cout << arr[i][j] << " ";
            ++j;
            if (j == m)
            {
                right = 0;
                --j;
                ++i;
                cout << endl;
            }
        }
        else
        {
            cout << arr[i][j] << " ";
            --j;
            if (j == -1)
            {
                right = 1;
                ++j;
                ++i;
                cout << endl;
            }
        }
    }
}

int main()
{
    int **arr;
    int m = 4, n = 4;
    arr = new int *[n];
    int v = 1;
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; ++j)
            arr[i][j] = v++;
    }

    printSnake(arr, n, m);
    return 0;
}