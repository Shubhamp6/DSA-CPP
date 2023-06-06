#include <bits/stdc++.h>
#define N 4
using namespace std;

bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

bool nQueen(int board[N][N], int row)
{
    if (row == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            if (nQueen(board, row + 1))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int board[N][N];
    memset(board, 0, sizeof(board));
    nQueen(board, 0);
    return 0;
}