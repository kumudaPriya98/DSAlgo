#include <iostream>
#include <stack>
using namespace std;

// Methods pop, top and getMin operations will always be called on non-empty stacks.

class MinStack
{
private:
    stack<int> numStack;
    stack<int> minStack;

public:
    MinStack() {}

    int getMin()
    {
        return minStack.top();
    }

    int top()
    {
        return numStack.top();
    }

    void pop()
    {
        minStack.pop();
        numStack.pop();
    }

    void push(int val)
    {
        if (minStack.empty())
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(min(minStack.top(), val));
        }
        numStack.push(val);
    }
};