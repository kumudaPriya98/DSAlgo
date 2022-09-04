#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int count = 0;
    findTargetSumWaysUtil(nums, target, 0, count, 0);
    return count;
}

void findTargetSumWaysUtil(vector<int>& nums, int target, int currSum, int& count, int currPos) {
    if (currPos == nums.size()) {
        if (currSum == target) {
            count++;
        }
        return;
    }

    findTargetSumWaysUtil(nums, target, currSum + nums[currPos], count, currPos+1);
    findTargetSumWaysUtil(nums, target, currSum - nums[currPos], count, currPos+1);
}