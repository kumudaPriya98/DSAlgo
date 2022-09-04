#include <iostream>
#include "TreeNode.hpp"

using namespace std;

bool isBalanced(TreeNode* root) {
    int height = 0;
    return isBalancedUtil(root, height);
}

bool isBalancedUtil(TreeNode* root, int& height) {
    if (!root) return true;

    int leftChildHeight = 0, rightChildHeight = 0;

    if (isBalancedUtil(root->left, leftChildHeight) &&
        isBalancedUtil(root->right, rightChildHeight) &&
        abs(leftChildHeight - rightChildHeight) < 2) {
            height = max(leftChildHeight, rightChildHeight) + 1;
            return true;
    } 
    return false;
}