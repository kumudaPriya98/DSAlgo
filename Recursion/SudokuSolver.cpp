#include <iostream>
#include <vector>
using namespace std;

void solveSudoku(vector<vector<char>> &board)
{
    int curr_row = 0, curr_col = 0;
    vector<vector<char>> backtrack_board(board);
    solveSudokuUtil(backtrack_board, curr_row, curr_col, board);
}

void solveSudokuUtil(vector<vector<char>> &board, int curr_row, int curr_col,
                     vector<vector<char>> &solved_board)
{
    if (curr_row == board.size())
    {
        solved_board = board;
    }
    else if (curr_col == board.size())
    {
        solveSudokuUtil(board, curr_row + 1, 0, solved_board);
    }
    else if (board[curr_row][curr_col] != '.')
    {
        solveSudokuUtil(board, curr_row, curr_col + 1, solved_board);
    }
    else
    {
        for (int i = 1; i < board.size() + 1; i++)
        {
            if (validMove(board, curr_row, curr_col, i + '0'))
            {
                board[curr_row][curr_col] = i + '0';
                solveSudokuUtil(board, curr_row, curr_col + 1, solved_board);
                board[curr_row][curr_col] = '.';
            }
        }
    }
}

bool validMove(vector<vector<char>> &board, int curr_row, int curr_col, char val)
{
    // Check the Row and Col
    for (int i = 0; i < board.size(); i++)
    {
        if (board[curr_row][i] == val)
            return false;
        if (board[i][curr_col] == val)
            return false;
    }

    // Check the Square
    int square_row = (curr_row / 3) * 3;
    int square_col = (curr_col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[square_row + i][square_col + j] == val)
                return false;
        }
    }
    return true;
}