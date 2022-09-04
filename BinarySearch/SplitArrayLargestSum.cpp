#include <iostream>
#include <vector>

using namespace std;

int splitArrayLargestSum(const vector<int>& nums, int m) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0);

    while (left < right) {
        int mid = left + (right - left)/2;
        
        if (canSplit(nums, m, mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

bool canSplit(const vector<int>& nums, int m, int  targetSum) {
    int currSubArrayCount = 1;
    int currSum = 0, currPtr = 0;
    while (currSubArrayCount <= m && currPtr < nums.size()) {
        if (nums[currPtr] + currSum <= targetSum) {
            currSum += nums[currPtr++];
        } else {
            currSubArrayCount++;
        }
    }
    return currPtr == nums.size();
}