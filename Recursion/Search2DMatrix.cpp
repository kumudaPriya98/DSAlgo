#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() == 0) return false;
    return searchMatrixUtil(matrix, target, matrix.size() - 1, 0);
}

bool searchMatrixUtil(vector<vector<int>>& matrix, int target, int curr_row, int curr_col) {
    if (curr_row < 0 || curr_row == matrix.size() || curr_col < 0 || curr_col == matrix[0].size()) return false;
    if (matrix[curr_row][curr_col] == target) return true;
    if (matrix[curr_row][curr_col] < target)
        return searchMatrixUtil(matrix, target, curr_row, curr_col + 1);
    return searchMatrixUtil(matrix, target, curr_row - 1, curr_col);
}