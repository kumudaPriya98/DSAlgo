#include <iostream>
#include <vector>
#include "TreeNode.hpp"
typedef long long int LLI;
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    TreeNode* root = NULL;
    if (k == 0) return false;
    for (int i = 0; i < nums.size(); i++) {    
        if (i > k) {
            root = deleteBST(root, nums[i - k - 1]);
        }

        LLI min_gap = (LLI)INT_MAX + 1;
        root = insertBST(root, nums[i], min_gap);
        if (min_gap <= t) return true;       
    }
    return false;
}

TreeNode* insertBST(TreeNode* root, int val, LLI& min_gap) {
    if (!root) return new TreeNode(val);
    min_gap = min(min_gap, abs((LLI)root->val - (LLI)val));
    if (root->val == val);
    else if (root->val < val) {
        root->right = insertBST(root->right, val, min_gap);
    } else {
        root->left = insertBST(root->left, val, min_gap);
    }
    return root;
}

TreeNode* deleteBST(TreeNode* root, int val) {
    if (!root) return NULL;

    if (root->val < val) root->right = deleteBST(root->right, val);
    else if (root->val > val) root->left = deleteBST(root->left, val);
    else {
        if (!root->left && !root->right) root = NULL;
        else if (!root->left || !root->right) root = root->left ? root->left : root->right;
        else {
            TreeNode* inorderSuccesor = root->right;
            while(inorderSuccesor->left) inorderSuccesor = inorderSuccesor->left;

            root->val = inorderSuccesor->val;
            root->right = deleteBST(root->right, inorderSuccesor->val);
        }
    }
    return root;
}