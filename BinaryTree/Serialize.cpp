#include <iostream>
#include <vector>
#include <string>
#include "TreeNode.hpp"
using namespace std;

string serialize(TreeNode* root) {
    if (!root) return "_";
    return to_string(root->val) + 
            "L" + serialize(root->left) +
            "R" + serialize(root->right); 
}

TreeNode* deserialize(string data) {
    int pos = 0;
    return deserializeUtil(data, pos);
}

TreeNode* deserializeUtil(string data, int& pos) {
    if (pos >= data.size()) return NULL;
    if (data[pos] == '_') {
        pos++; 
        return NULL;
    }

    int isNegative = false;
    int value = 0;
    if(data[pos] == '-') {
        isNegative = true; 
        pos++;
    }

    while(pos < data.size()) {
        if (data[pos] >= '0' && data[pos] <= '9') {
            value *= 10;
            value += data[pos] - '0';
            pos++;
        } else {
            break;
        }
    }

    value = isNegative ? -value : value;
    TreeNode* root = new TreeNode(value);

    pos++;
    root->left = deserializeUtil(data, pos);
    pos++;
    root->right = deserializeUtil(data, pos);
    return root;
}