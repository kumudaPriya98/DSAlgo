#include <iostream>

using namespace std;

int squareroot(int num) {
    if (num < 1) return 0;
    
    int left = 1, right = num;
    int target = 1;
    while (left <= right) {
        int mid = left + (right - left)/2;
        if(mid == num/mid) return mid;
        else if(mid < num/mid) {
            target = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    return target; 
}