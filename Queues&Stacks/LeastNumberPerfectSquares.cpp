#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int numSquares(int n)
{
    vector<int> perfectSquares;
    unordered_set<int> visited;
    queue<int> bfsQueue;
    for (int i = 1; i * i <= n; i++)
    {
        perfectSquares.push_back(i * i);
        visited.insert(i * i);
        bfsQueue.push(i * i);
    }

    if (visited.find(n) != visited.end())
        return 1;
    int count = 2;
    while (!bfsQueue.empty())
    {
        int currLen = bfsQueue.size();
        for (int i = 0; i < currLen; i++)
        {
            int currSum = bfsQueue.front();
            bfsQueue.pop();

            for (int j = 0; j < perfectSquares.size(); j++)
            {
                int next = currSum + perfectSquares[j];
                if (next == n)
                    return count;

                if (next > n)
                    break;
                if (visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    bfsQueue.push(next);
                }
            }
        }
        count++;
    }
    return -1;
}