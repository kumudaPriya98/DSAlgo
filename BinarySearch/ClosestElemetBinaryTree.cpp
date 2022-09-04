#include <iostream>

using namesapce std;

int closestValue(TreeNode* root,  double num) {
    if(!root) return 0;

    int target = root->value;
    while(root) {
        if(abs(root->value - num) < abs(target - num)) target = root->value;

        if(root->value > num) root = root->left;
        else root = root->right;
    }
}