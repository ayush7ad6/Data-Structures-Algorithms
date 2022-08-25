#include <iostream>
#include <vector>

using namespace std;

bool ratMaze(int arr[4][4], int n, int m, int res[4][4], int r = 0, int c = 0)
{
    if (r > n || c > m || arr[r][c] == 0)
        return false;

    res[r][c] = 1;

    if (r == n && c == m)
    {
        if (arr[r][c] == 1)
        {

            return true;
        }

        return false;
    }

    if (ratMaze(arr, n, m, res, r + 1, c) || ratMaze(arr, n, m, res, r, c + 1))
        return true;

    res[r][c] = 0;
    return false;
}

int main()
{
    int m = 4;
    int n = 4;

    int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 1, 0}};
    int res[4][4] = {0};
    cout << ratMaze(maze, n - 1, m - 1, res) << endl;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << res[i][j] << " ";

        cout << endl;
    }
    return 0;
}