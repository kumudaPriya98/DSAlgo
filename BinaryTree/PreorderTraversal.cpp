#include <iostream>
#include "TreeNode.hpp"
#include <vector>
#include <stack>
using namespace std;


void preorderTraversalRecursive(TreeNode* root, vector<int>& order) {
    if (!root) return;
    order.push_back(root->val);

    preorderTraversalRecursive(root->left, order);
    preorderTraversalRecursive(root->right, order);
}

void preorderTraversalIterative(TreeNode* root, vector<int>& order) {
    if (!root) return;

    stack<TreeNode*> nodesStack;
    nodesStack.push(root);

    while (!nodesStack.empty()) {
        TreeNode* root = nodesStack.top();
        nodesStack.pop();

        order.push_back(root->val);

        if (root->right) nodesStack.push(root->right);
        if (root->left) nodesStack.push(root->left);
    }
}