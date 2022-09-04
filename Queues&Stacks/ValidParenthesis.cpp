#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> paranthesisStack;

    auto matchParanthesis = [](const char &open_p, const char &closed_p)
    {
        if (open_p == '(')
            return closed_p == ')';
        else if (open_p == '{')
            return closed_p == '}';
        else
            return closed_p == ']';
    };

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            paranthesisStack.push(s[i]);
        }
        else
        {
            if (paranthesisStack.empty() ||
                !matchParanthesis(paranthesisStack.top(), s[i]))
            {
                return false;
            }
            paranthesisStack.pop();
        }
    }

    return paranthesisStack.empty();
}