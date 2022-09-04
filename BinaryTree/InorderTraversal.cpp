#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.hpp"

using namespace std;

void InorderTraversalRecursive(TreeNode* root, vector<int>& order) {
    if (!root) return;

    InorderTraversalRecursive(root->left, order);
    order.push_back(root->val);
    InorderTraversalRecursive(root->right, order);
}

void InorderTraversalRecursive2(TreeNode* root, vector<int>& order) {
    stack<TreeNode*> nodeStack;

    while (!nodeStack.empty() || root) {
        while(root) {
            nodeStack.push(root);
            root = root->left;
        } 

        root = nodeStack.top();
        nodeStack.pop();

        order.push_back(root->val);

        root = root->right;
    }
}
