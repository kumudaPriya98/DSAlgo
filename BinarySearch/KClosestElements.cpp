#include <iostream>
#include <vector>

using namespace std;

vector<int> kClosestElements(vector<int>& nums, int target, int k) {
    if(nums.size() <= k) return nums;

    int left = 0, right = nums.size() - 1;
    while(left < right) {
        int mid = left + (right - left)/2;
        if(nums[mid] == target) {left = mid; break;}
        else if(nums[mid] < target) left = mid + 1;
        else right = mid; 
    }
    int closestPos = left;
    int leftNeighbor = left - 1 > -1 ? left - 1 : left;
    int rightNeighbor = left + 1 < nums.size() ? left + 1 : left;

    closestPos = abs(target - nums[closestPos]) >= abs(target - nums[leftNeighbor]) ? leftNeighbor;
    closestPos = abs(target - nums[closestPos]) > abs(target - nums[rightNeighbor]) ? rightNeighbor;

    left = closestPos; right = closestPos;
    while(right - left < k - 1) {
        if (left - 1 < 0) right++;
        else if (right + 1 > nums.size() - 1) left --;
        else {
            if(abs(target - nums[left - 1]) <= abs(target - nums[right + 1])) left--;
            else right++;
        }
    }

    return vector(nums.begin() + left, nums.begin() + left + k);
}