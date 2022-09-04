#include <iostream>

#ifndef TREE_NODE
#define TREE_NODE

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val_p = 0) : val(val_p), 
                           left(NULL), 
                           right(NULL) {}
};


#endif