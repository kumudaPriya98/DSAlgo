#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<int> higherTempStack;

    for (int i = temperatures.size() - 1; i >= 0; i--) {
        while (!higherTempStack.empty() && temperatures[higherTempStack.top()] <= temperatures[i]) {
            higherTempStack.pop();
        }

        result[i] = higherTempStack.empty() ? 0 : higherTempStack.top() - i;
        higherTempStack.push(i);
    }

    return result;
}