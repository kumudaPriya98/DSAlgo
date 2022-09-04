#include <iostream>
#include "TreeNode.hpp"
using namespace std;

TreeNode* searchBST(TreeNode* root, int value) {
    if (!root || root->val == value) return root;
    if (root->val < value) return searchBST(root->right, value);
    return searchBST(root->left, value);
} 

TreeNode* searchBSTIterative(TreeNode*root, int value) {
    while (root) {
        if (root->val == value) return root;
        else if (root->val < value) root = root->right;
        else root = root->left;
    }
    return NULL;
}

// constraint : all values in the tree are unique
// and current value is not already present in the tree
TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);

    TreeNode* newNode;
    if (root->val < value) {
        newNode = insertBST(root->right, value);
        if (!root->right)
            root->right = newNode;
    }
    else {
        newNode = insertBST(root->left, value);
        if (!root->left)
            root->left = newNode;
    } 
    return root;
}

TreeNode* insertBSTIterative(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);

    TreeNode* temp = root;
    while(temp) {
        if (temp->val < value) {
            if (temp->right) temp = temp->right;
            else {
                temp->right = new TreeNode(value);
                break;
            }
        } else {
            if (temp->left) temp = temp->left;
            else {
                temp->left = new TreeNode(value);
                break;
            }
        }
    }

    return root;
}

TreeNode* deleteBST(TreeNode* root, int value) {
    if (!root) return root;
    else if (root->val < value) root->right = deleteBST(root->right, value);
    else if (root->val > value) root->left = deleteBST(root->left, value);
    else {
        if (!root->left && !root->right) root = NULL;
        else if (!root->left || !root->right) root = root->left ? root->left : root->right;
        else {
            TreeNode* inorderSuccesor = root->right;
            while(inorderSuccesor->left) inorderSuccesor = inorderSuccesor->left;

            
            root->right = deleteBST(root->right, inorderSuccesor->val);
            root->val = inorderSuccesor->val;
        }
    }
    return root;
}