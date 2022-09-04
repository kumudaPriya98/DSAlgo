#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <pair>

using namespace std;

int numIslands(vector<vector<char>> &grid)
{
    int count = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                bfs(grid, i, j);
            }
        }
    }
    return count;
}

void bfs(vector<vector<char>> &grid, int row, int col)
{
    auto isValid = [&](int r, int c)
    {
        return (r >= 0 && r < grid.size() &&
                c >= 0 && c < grid[0].size() &&
                grid[r][c] == '1');
    };

    if (!isValid(row, col))
        return;
    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(row, col));
    grid[row][col] = '0';

    while (!bfsQueue.empty())
    {
        pair<int, int> currNode = bfsQueue.front();
        bfsQueue.pop();

        const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto dir : dirs)
        {
            int r = currNode.first + dir[0], c = currNode.second + dir[1];
            if (isValid(r, c))
            {
                bfsQueue.push(make_pair(r, c));
                grid[r][c] = '0';
            }
        }
    }
}

void dfsIterative(vector<vector<char>> &grid, int row, int col)
{
    auto isValid = [&](int r, int c)
    {
        return (r >= 0 && r < grid.size() &&
                c >= 0 && c < grid[0].size() &&
                grid[r][c] == '1');
    };

    if (!isValid(row, col))
        return;

    stack<pair<int,int>> dfsStack;
    dfsStack.push(make_pair(row,col));
    grid[row][col] = '0';

    while (!dfsStack.empty()) {
        pair<int, int> currNode = dfsStack.top();
        dfsStack.pop();

        const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto dir : dirs)
        {
            int r = currNode.first + dir[0], c = currNode.second + dir[1];
            if (isValid(r,c)) {
                dfsStack.push(make_pair(r,c));
                grid[r][c] = '0';
            }
        }

    }
}

void dfs(vector<vector<char>> &grid, int row, int col)
{
    if (row < 0 || row >= grid.size() ||
        col < 0 || col >= grid[0].size() ||
        grid[row][col] == '0')
        return;

    grid[row][col] = '0';
    const vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto dir : dirs)
    {
        dfs(grid, row + dir[0], col + dir[1]);
    }
}
