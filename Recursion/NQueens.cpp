#include <iostream>
#include <vector>
using namespace std;

int totalNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    int possibilities = 0;
    countPossibilities(board, 0, possibilities);
    return possibilities;
}


void countPossibilities(vector<vector<int>> &board, int curr_row, int &possibilities)
{
    if (curr_row == board.size())
    {
        possibilities++;
        return;
    }

    for (int i = 0; i < board.size(); i++)
    {
        if (board[curr_row][i] == 0)
        {
            // Make a move by placing the queen at curr_row, i
            positionQueen(board, curr_row, i, 1);

            countPossibilities(board, curr_row + 1, possibilities);

            // Backtrack the move of placing the queen at curr_row, i
            positionQueen(board, curr_row, i, -1);
        }
    }
}

void positionQueen(vector<vector<int>> &board, int curr_row, int curr_col, int update)
{
    int n = board.size();
    for (int i = curr_row; i < n; i++)
    {
        board[i][curr_col] += update;
        if (curr_col + i - curr_row < n)
            board[i][curr_col + i - curr_row] += update;
        if (curr_col - (i - curr_row) >= 0)
            board[i][curr_col - (i - curr_row)] += update;
    }
}