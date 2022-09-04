#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s)
{
    stack<string> decodeStack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || (s[i] >= 'a' && s[i] <= 'z'))
        {
            string substr = "";
            substr.push_back(s[i]);
            decodeStack.push(substr);
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            string num = "";
            while (i < s.size() && s[i] >= '0' && s[i] <= '9')
            {
                num.push_back(s[i]);
                i++;
            }
            i--;
            decodeStack.push(num);
            continue;
        }
        else
        {
            string substr = "";
            while (decodeStack.top() != "[")
            {
                substr = decodeStack.top() + substr;
                decodeStack.pop();
            }
            decodeStack.pop();
            int repeatNo = stoi(decodeStack.top());
            decodeStack.pop();

            string result = "";
            for (int j = 1; j <= repeatNo; j++)
            {
                result += substr;
            }
            decodeStack.push(result);
        }
    }

    string result = "";
    while (!decodeStack.empty())
    {
        result = decodeStack.top() + result;
        decodeStack.pop();
    }
    return result;
}