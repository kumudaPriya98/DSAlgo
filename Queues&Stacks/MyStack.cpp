#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> numQueue;
    int topElt;

public:
    bool empty()
    {
        return numQueue.empty();
    }

    int top()
    {
        return topElt;
    }

    void push(int x)
    {
        topElt = x;
        numQueue.push(x);
    }

    int pop()
    {
        for (int i = 0; i < numQueue.size() - 1; i++)
        {
            int val = numQueue.front();
            numQueue.pop();
            numQueue.push(val);

            if (i == numQueue.size() - 2) {
                topElt = val;
            }
        }

        int val = numQueue.front();
        numQueue.pop();
        return val;
    }
};