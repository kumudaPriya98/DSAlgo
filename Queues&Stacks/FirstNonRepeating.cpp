#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string solve(string A) {
    vector<int> charsPresent(26, 0);
    queue<char> nonRepeatQueue;
    
    string result = "";
    for (int i = 0; i < A.size(); i++) {
        if (charsPresent[A[i] - 'a'] == 0) {
            nonRepeatQueue.push(A[i]);
        }
        charsPresent[A[i] - 'a']++;
        
        
        while (!nonRepeatQueue.empty()) {
            if (charsPresent[nonRepeatQueue.front() - 'a'] == 1) {
                break;
            } else {
                nonRepeatQueue.pop();
            }
        }
        
        result += nonRepeatQueue.empty() ? '#' : nonRepeatQueue.front();        
    }
    return result;
}