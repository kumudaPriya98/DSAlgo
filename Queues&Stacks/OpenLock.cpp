#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int openLock(vector<string> &deadends, string target)
{
    string start = "0000";
    set<string> deadendSet;
    for (int i = 0; i < deadends.size(); i++)
    {
        deadendSet.insert(deadends[i]);
    }

    if (deadendSet.find(start) != deadendSet.end() ||
        deadendSet.find(target) != deadendSet.end())
        return -1;

    queue<string> bfsQueue;
    bfsQueue.push(start);
    deadendSet.insert(start);
    if (target == start)
        return 0;

    int count = 1;

    while (!bfsQueue.empty())
    {
        int currLen = bfsQueue.size();
        for (int i = 0; i < currLen; i++)
        {
            string currPos = bfsQueue.front();
            bfsQueue.pop();

            for (int j = 0; j < 4; j++)
            {
                for (int k = -1; k < 2; k = k + 2)
                {
                    string next = currPos;
                    next[j] = (((next[j] - '0') + k + 10) % 10) + '0';

                    if (next == target)
                        return count;
                    if (deadendSet.find(next) == deadendSet.end())
                    {
                        deadendSet.insert(next);
                        bfsQueue.push(next);
                    }
                }
            }
        }
        count++;
    }
    return -1;
}