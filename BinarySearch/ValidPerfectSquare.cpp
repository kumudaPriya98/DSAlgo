#include <iostream>
typedef long long int LLI;

using namespace std;

bool validPerfectSquare(int num) {
    if(num < 0) return false;

    int left = 1, right = num;
    while(left <= right) {
        int mid = left + (right - left)/2;

        LLI square = (LLI)mid * mid;
        if(square == (LLI)num) return true;
        else if (square < (LLI)num) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}