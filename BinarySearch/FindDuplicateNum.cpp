#include <iostream>
#include <vector>

using namespace std;

//constraint : array of len n+1, and nums in [1,n]
//constraint : Only one number is duplicated
int findDuplicateNum(const vector<int>& nums) {
    int left = 1, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left)/2;

        int smallerCount = findSmallerNumCount(nums, mid); 
        if (smallerCount >= mid) right = mid;
        else left = mid + 1;
    }
    return left;
}

int findSmallerNumCount(const vector<int>& nums, int  target) {
    int count = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i] <= target) count++;
    }
    return count;
}