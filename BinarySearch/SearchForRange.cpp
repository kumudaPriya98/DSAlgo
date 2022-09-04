#include <iostream>
#include <vector>

using namespace std;

vector<int> searchForRange(vector<int>& nums, int target) {
    return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
}

int binarySearch(vector<int>& nums, int target, bool leftmost) {
    int left = 0, right = nums.size() - 1;
    int pos = -1;
    while(left <= right) {

        int mid = left + (right - left)/2;
        if(nums[mid] == target) {
            pos = mid;
            if(leftmost) right = mid - 1;
            else left = mid + 1;
        }
        else if(nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
} 