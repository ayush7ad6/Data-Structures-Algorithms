#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isSafe(vector<vector<int>> grid, int n, int r, int c, int val)
{
    // if (grid[r][c] != 0)
    //     return false;

    int rootn = sqrt(n);
    for (int i = 0; i < n; ++i)
    {
        if (grid[r][i] == val)
            return false;
        if (grid[i][c] == val)
            return false;
    }

    int r0 = (r / rootn) * rootn;
    int c0 = (c / rootn) * rootn;

    for (int i = r0; i < r0 + rootn; ++i)
    {
        for (int j = c0; j < c0 + rootn; ++j)
        {
            if (grid[i][j] == val)
                return false;
        }
    }

    return true;
}

bool sudoku(vector<vector<int>> &grid, int n)
{
    int i, j;
    int f = 1;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (grid[i][j] == 0)
            {
                f = 0;
                break;
            }
        }
        if (f == 0)
            break;
    }

    if (i == n && j == n)
        return true;

    for (int v = 1; v <= n; ++v)
    {
        cout << "D: " << i << " " << j << " " << v << endl;
        if (isSafe(grid, n, i, j, v))
        {
            grid[i][j] = v;
            cout << "\nON " << i << " " << j << " " << v << endl
                 << endl;
            if (sudoku(grid, n))
                return true;
            grid[i][j] = 0;
            cout << "\nOFF " << i << " " << j << " " << v << endl
                 << endl;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> grid = {{1, 0, 3, 0}, {0, 0, 2, 1}, {0, 1, 0, 2}, {2, 4, 0, 0}};
    cout << "Before: " << endl;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    cout << endl
         << endl;
    sudoku(grid, grid.size());
    cout << endl
         << endl;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return 0;
}