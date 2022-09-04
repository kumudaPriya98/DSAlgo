#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// constraint : token.size() >= 1
int evalRPN(vector<string> &tokens)
{
    stack<int> numStack;
    auto isOp = [](const string &op)
    {
        return op == "*" || op == "-" || op == "+" || op == "/";
    };

    auto evalOp = [](int num1, int num2, char op)
    {
        switch (op)
        {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        default:
            return num1 / num2;
        }
    };

    for (int i = 0; i < tokens.size(); i++)
    {
        if (isOp(tokens[i]))
        {
            int num2 = numStack.top();
            numStack.pop();
            int num1 = numStack.top();
            numStack.pop();

            numStack.push(evalOp(num1, num2, tokens[i][0]));
        }
        else
        {
            numStack.push(stoi(tokens[i]));
        }
    }
    return numStack.top();
}