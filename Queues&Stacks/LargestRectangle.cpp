#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &A)
{
    stack<int> leftStack;
    vector<int> rectangleWidths(A.size(), 1);

    for (int i = 0; i < A.size(); i++)
    {
        while (!leftStack.empty() && A[leftStack.top()] >= A[i])
        {
            rectangleWidths[leftStack.top()] += i - leftStack.top() - 1;
            leftStack.pop();
        }

        if (!leftStack.empty())
        {
            rectangleWidths[i] += i - leftStack.top() - 1;
        }
        else
        {
            rectangleWidths[i] += i;
        }
        leftStack.push(i);
    }

    while (!leftStack.empty())
    {
        rectangleWidths[leftStack.top()] += A.size() - leftStack.top() - 1;
        leftStack.pop();
    }

    int maxArea = 0;
    for (int i = 0; i < rectangleWidths.size(); i++)
    {
        maxArea = max(maxArea, rectangleWidths[i] * A[i]);
    }
    return maxArea;
}