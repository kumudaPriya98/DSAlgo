#include <iostream>
#include "TreeNode.hpp"

using namespace std;

TreeNode* inorderSuccesor(TreeNode* root, TreeNode* target) {
    if (!root) return NULL;

    TreeNode* succesor = NULL;

    while(root) {
        if (root == target || root->val < target->val) root = root->right;
        else {
            succesor = root;
            root = root->left;
        }
    }
    return succesor;
}