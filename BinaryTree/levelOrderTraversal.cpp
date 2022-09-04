#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> order;
    if (!root) return order;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int currCount = nodeQueue.size();
        vector<int> currLevel;
        for (int i = 0; i < currCount; i++) {
            root = nodeQueue.front();
            nodeQueue.pop();

            currLevel.push_back(root->val);

            if (root->left) nodeQueue.push(root->left);
            if (root->right) nodeQueue.push(root->right);
        }
        order.push_back(currLevel);
    }
    return order;
}