#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    reverseStringUtil(s, 0, s.size() - 1);
}

void reverseStringUtil(vector<char>& s, int start, int end) {
    if (start >= end) return;
    swap(s[start], s[end]);
    reverseStringUtil(s, start + 1, end - 1);
}