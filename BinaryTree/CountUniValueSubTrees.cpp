#include <iostream>
#include "TreeNode.hpp"


using namespace std;

int countUniValueSubTrees(TreeNode* root) {
    int count = 0;
    isUniValueSubTree(root, count);
    return count;
}

bool isUniValueSubTree(TreeNode* root, int& count) {
    if (!root) return true;

    if (isUniValueSubTree(root->left, count) && isUniValueSubTree(root->right, count)) {
        int leftChildVal = root->left ? root->left->val : root->val;
        int rightChildVal = root->right ? root->right->val : root->val;

        if (leftChildVal == rightChildVal && leftChildVal == root->val) {
            count++;
            return true;
        }
    }
    return false;
}