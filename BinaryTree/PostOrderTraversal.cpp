#include <iostream>
#include <vector>
#include <stack>
#include <pair>
#include "TreeNode.hpp"

using namespace std;

void postOrderTraversalRecursive(TreeNode* root, vector<int>& order) {
    if (!root) return;

    postOrderTraversalRecursive(root->left, order);
    postOrderTraversalRecursive(root->right, order);
    order.push_back(root->val);
}

void postOrderTraversalIterative1(TreeNode* root, vector<int>& order) {
    stack<TreeNode*> nodeStack;

    if (!root) return;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        root = nodeStack.top();
        nodeStack.pop();

        order.push_back(root->val);

        if (root->left) nodeStack.push(root->left);
        if (root->right) nodeStack.push(root->right);
    }

    for (int i = 0; i < order.size()/2; i++) {
        std::swap(order[i], order[order.size() - 1 - i]);
    }
}

void postOrderTraversalIterative2(TreeNode* root, vector<int>& order) {
    stack<pair<TreeNode*, bool>> nodeStack;

    while (!nodeStack.empty() || root) {
        while (root) {
            nodeStack.push(make_pair(root, false));
            root = root->left;
        }

        auto top = nodeStack.top();
        nodeStack.pop();

        if (!top.second) {
            nodeStack.push(make_pair(top.first, true));
            root = top.first->right;
        } else {
            order.push_back(top.first->val);
            root = NULL;
        }
    }
}