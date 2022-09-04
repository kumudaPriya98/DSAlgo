#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
private:
    stack<int> push_stack, pop_stack;

public:
    bool empty()
    {
        return push_stack.empty() && pop_stack.empty();
    }

    void push(int x)
    {
        push_stack.push(x);
    }

    void shuffle()
    {
        if (pop_stack.empty())
        {
            while (!push_stack.empty())
            {
                pop_stack.push(push_stack.top());
                push_stack.pop();
            }
        }
    }

    int pop()
    {
        if (pop_stack.empty())
            shuffle();

        int val = pop_stack.top();
        pop_stack.pop();
        return val;
    }

    int peek()
    {
        if (pop_stack.empty())
            shuffle();

        return pop_stack.top();
    }
};