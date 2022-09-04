#include <iostream>
#include "TreeNode.hpp"

using namespace std;

//Bottom-Up Approach
int maxDepthBinaryTree(TreeNode* root) {
    if (!root) return 0;

    return max(maxDepthBinaryTree(root->left), maxDepthBinaryTree(root->right)) + 1;
}

//Top-Down Approach
int maxDepthBinaryTreeTopDown(TreeNode* root) {
    int maxDepth = 0;
    maxDepthBinaryTreeTopDownUtil(root, 1, maxDepth);
    return maxDepth;
}

void maxDepthBinaryTreeTopDownUtil(TreeNode* root, int currLevel, int& maxDepth) {
    if (!root) return;

    if (!root->left && !root->right) {
        maxDepth = max(maxDepth, currLevel);
        return;
    }

    maxDepthBinaryTreeTopDownUtil(root->left, currLevel + 1, maxDepth);
    maxDepthBinaryTreeTopDownUtil(root->right, currLevel + 1, maxDepth);
}