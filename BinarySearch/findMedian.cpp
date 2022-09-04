#include <iostream>
#include <vector>

using namespace std;

double findMedian(const vector<int>& numsA, const vector<int>& numsB) {
    if (numsA.size() > numsB.size()) return findMedian(numsB, numsA);

    int start = 0, end = numsA.size() - 1;
    int midCount = (numsA.size() + numsB.size() + 1)/2;

    while (start <= end) {
        int mid = start + (end - start)/2;
        int leftSizeA = mid;
        int leftSizeB =  midCount - leftSizeA;

        int leftA = leftSizeA > 0 ? numsA[leftSizeA - 1] : INT_MIN;
        int leftB = leftSizeB > 0 ? numsB[leftSizeB - 1] : INT_MIN;
        int rightA = leftSizeA < numsA.size() ? numsA[leftSizeA] : INT_MAX;
        int rightB = leftSizeB < numsB.size() ? numsB[leftSizeB] : INT_MAX;

        if (leftA <= rightB && leftB <= rightA) {
            double median = max(leftA, leftB);
            if ((numsA.size() + numsB.size()) % 2 == 0) {
                median += min(rightA, rightB);
                median /= 2;
            }
            return median;
        } else if (leftA > rightB) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0.0;
}