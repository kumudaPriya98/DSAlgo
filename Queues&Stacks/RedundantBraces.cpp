#include <iostream>
#include <stack>
using namespace std;

int braces(string A)
{
    stack<char> braceStack;

    auto isOp = [](char op)
    {
        return op == '*' || op == '/' || op == '+' || op == '-';
    };

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == ' ')
            ;
        else if (A[i] == '(')
            braceStack.push('(');
        else if (A[i] == ')')
        {
            if (braceStack.top() == '(')
                return 1;
            else
            {
                // Remove exp and corresponding '('
                braceStack.pop();
                braceStack.pop();
            }
        }
        else
        {
            bool isExpr = false;
            while (i < A.size() && A[i] != ')' && A[i] != '(')
            {
                if (isOp(A[i]))
                    isExpr = true;
                i++;
            }
            i--;
            if (isExpr)
            {
                braceStack.push('a');
            }
        }
    }
    return 0;
}