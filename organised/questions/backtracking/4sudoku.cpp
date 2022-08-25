#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isSafe(vector<vector<int>> &grid, int n, int r, int c, int val)
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

bool sudokuRec(vector<vector<int>> &grid, int n)
{
    int i, j;
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            if (grid[r][c] == 0)
            {
                i = r;
                j = c;
                break;
            }
        }
    }
    cout << i << " " << j << endl;
    if (i == n && j == n)
        return true;

    for (int val = 1; val <= n; ++val)
    {
        cout << "D: " << i << " " << j << " " << val << endl;
        if (isSafe(grid, n, i, j, val))
        {
            grid[i][j] = val;
            cout << "\nON " << i << " " << j << " " << val << endl
                 << endl;
            if (sudokuRec(grid, n))
                return true;
            grid[i][j] = 0;
            cout << "\nOFF " << i << " " << j << " " << val << endl
                 << endl;
        }
    }

    return false;
}
// bool sudokuRec(vector<vector<int>> &grid, int n, int col)
// {
//     if (col >= n)
//         return true;

//     for (int i = 0; i < n; ++i)
//     {
//         if (grid[i][col] == 0)
//         {
//             for (int j = 1; j <= n; ++j)
//             {
//                 cout << "D: " << i << " " << col << " " << j << endl;
//                 if (isSafe(grid, n, i, col, j))
//                 {
//                     grid[i][col] = j;
//                     cout << "\nON " << i << " " << col << " " << j << endl
//                          << endl;

//                     if (sudokuRec(grid, n, col + 1))
//                         return true;
//                     grid[i][col] = 0;
//                     cout << "\nOFF " << i << " " << col << " " << j << endl
//                          << endl;
//                 }
//             }
//         }
//     }

//     return false;
// }
void sudoku(vector<vector<int>> &grid)
{
    int n = grid.size();
    sudokuRec(grid, n);
    cout << endl
         << endl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << grid[i][j] << " ";
        cout << endl;
    }
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
    sudokuRec(grid, grid.size());
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