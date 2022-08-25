#include <iostream>
#include <vector>

using namespace std;
vector<vector<vector<int>>> allNQueens;
bool isSafe(vector<vector<int>> &board, int n, int r, int c)
{
    // if (r < 0 || r >= n || c >= n || c < 0 || board[r][c] == 1)
    //     return false;
    if (board[r][c] == 1)
        return false;

    for (int i = 0; i < n; ++i)
    {
        if (board[i][c])
            return false;
        if (board[r][i])
            return false;
    }

    for (int i = r, j = c; i >= 0 && j >= 0; --j, --i)
        if (board[i][j])
            return false;

    for (int i = r, j = c; i < n && j >= 0; --j, ++i)
        if (board[i][j])
            return false;

    return true;
}

bool nQueenRec(vector<vector<int>> &board, int n, int c, vector<vector<int>> &temp)
{
    if (c >= n)
    {
        allNQueens.push_back(board);
        board = temp;
        return true;
    }
    for (int i = 0; i < n; ++i)
    {
        if (isSafe(board, n, i, c))
        {
            temp = board;
            board[i][c] = 1;
            cout << i << " " << c << " ON\n";
            if (nQueenRec(board, n, c + 1, temp))
                continue;

            cout << i << " " << c << " OFF\n";
            board[i][c] = 0;
        }
    }
    return false;
}
void nQueen(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> temp(n, vector<int>(n, 0));

    nQueenRec(board, n, 0, temp);
    cout << endl
         << endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     // cout << "HERE";
    //     for (int j = 0; j < n; ++j)
    //         cout << board[i][j] << " ";
    //     cout << endl;
    // }
}

int main()
{
    int n = 5;
    nQueen(n);

    for (int i = 0; i < allNQueens.size(); ++i)
    {
        for (int ii = 0; ii < n; ++ii)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << allNQueens[i][ii][j] << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }
    return 0;
}