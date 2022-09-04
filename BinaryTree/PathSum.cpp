#include <iostream>
#include "TreeNode.hpp"

using namespace std;

bool hasPathSum(TreeNode* root, int targetSum) {
    return hasPathSumUtil(root, targetSum, 0);
}

bool hasPathSumUtil(TreeNode* root, int targetSum, int currSum) {
    if (!root) return false;
    
    currSum += root->val;
    if (!root->left && !root->right) {
        return currSum == targetSum ? true : false;
    }
    
    return hasPathSumUtil(root->left, targetSum, currSum) || 
           hasPathSumUtil(root->right, targetSum, currSum);
}