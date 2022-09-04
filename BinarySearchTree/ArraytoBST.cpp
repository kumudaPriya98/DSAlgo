#include <iostream>
#include <vector>
#include "TreeNode.hpp"
using namespace std;

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBSTUtil(nums, 0, nums.size() -1);
}

TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int start, int end) {
    if (start > end) return NULL;
    if (start == end) return new TreeNode(nums[start]);

    int mid = start + (end - start)/2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBSTUtil(nums, start, mid - 1);
    root->right = sortedArrayToBSTUtil(nums, mid + 1, end);
    return root;
}