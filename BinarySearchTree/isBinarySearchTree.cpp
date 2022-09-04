#include <iostream>
#include "TreeNode.hpp"
using namespace std;

bool isBST(TreeNode* root) {
    return isBST(root, NULL, NULL);
}

bool isBST(TreeNode* root, TreeNode* leftMarginNode, TreeNode* RightMarginNode) {
    if (!root) return true;
    bool bstCheck = (leftMarginNode ? root->val > leftMarginNode->val) &&
                    (RightMarginNode ? root->val < RightMarginNode->val);

    return bstCheck && 
           isBST(root->left, leftMarginNode, root) &&
           isBST(root->right, root, RightMarginNode);
}