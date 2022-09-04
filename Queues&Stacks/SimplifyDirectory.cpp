#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string simplifyPath(string A)
{
    stack<string> dirStack;
    int i = 0;
    while (i < A.size())
    {
        if (A[i] == '/')
            i++;
        else
        {
            string dir = "";
            while (i < A.size() && A[i] != '/')
            {
                dir.push_back(A[i]);
                i++;
            }

            if (dir == "..")
            {
                if (!dirStack.empty())
                    dirStack.pop();
            }
            else if (dir == ".")
                ;
            else
                dirStack.push(dir);
        }
    }

    string result = "";
    vector<string> resultVector;
    while (!dirStack.empty())
    {
        resultVector.push_back(dirStack.top());
        dirStack.pop();
    }

    for (int i = resultVector.size() - 1; i >= 0; i--)
        result += ("/" + resultVector[i]);
    return result == "" ? "/" : result;
}