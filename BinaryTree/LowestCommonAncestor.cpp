#include <iostream>
#include "TreeNode.hpp"
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* nodeA, TreeNode* nodeB) {
    if (!root || root == nodeA || root == nodeB) return root;

    TreeNode* left = lowestCommonAncestor(root->left, nodeA, nodeB);
    TreeNode* right = lowestCommonAncestor(root->right, nodeA, nodeB);

    return (left && right) ? root : (left ? left : right);
}