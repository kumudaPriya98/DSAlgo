#include <iostream>
#include <vector>

using namespace std;

// Constraint : all the nums are unique
// nums is ascending sorted and rotated between 1 and n times.
int findMinimumRotatedArray(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left)/2;
        if(nums[mid] < nums[right]) right = mid;
        else left = mid + 1;
         
    }
    return nums[left];
}
