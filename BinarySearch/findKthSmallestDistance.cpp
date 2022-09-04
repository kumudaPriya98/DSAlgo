#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthSmallestDistance(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = nums[nums.size() - 1] - nums[0];

    while (left < right) {
        int mid = left + (right - left)/2;

        int smallerDistancesCount = findSmallerDistancesCount(nums, mid);
        if (smallerDistancesCount >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}

int findSmallerDistancesCount(const vector<int>& nums, int targetDistance) {
    int left_ptr = 0, right_ptr = left_ptr + 1;
    int count = 0;
    while(right_ptr < nums.size()) {
        if (left_ptr == right_ptr) right_ptr++;
        else if (nums[right_ptr] - nums[left_ptr] <= targetDistance) {
            count += right_ptr - left_ptr;
            right_ptr++;
        } else {
            left_ptr++;
        }
    }
}