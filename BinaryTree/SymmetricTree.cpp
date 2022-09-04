#include <iostream>
#include "TreeNode.hpp"

using namespace std;

bool isSymmetricTree(TreeNode* root) {
    if (!root) return true;
    return isSymmetricTreeUtil(root, root);
}

bool isSymmetricTreeUtil(TreeNode* leftTreeNode, TreeNode* rightTreeNode) {
    if (!leftTreeNode && !rightTreeNode) return true;

    if (!leftTreeNode || !rightTreeNode || 
        leftTreeNode->val != rightTreeNode->val) return false;

    return isSymmetricTreeUtil(leftTreeNode->left, rightTreeNode->right) &&
           isSymmetricTreeUtil(leftTreeNode->right, rightTreeNode->left);
}