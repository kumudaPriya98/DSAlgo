#include <iostream>
#include <vector>
using namespace std;

char smallestGreaterLetter(const vector<char> & letters, char target) {
    int len = letters.size();
    if(target > letters[len - 1]) return letters[0];

    int left = 0, right = len - 1;
    while(left < right) {
        int mid = left + (right - left)/2;

        if(letters[mid] <= target) left = mid + 1;
        else right = mid;
    }
    return letters[left];
}