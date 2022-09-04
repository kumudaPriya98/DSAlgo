#include <iostream>
#include "TreeNode.hpp"
#include <vector>
#include <unordered_map>
using namespace std;

TreeNode* constructBinaryTree(const vector<int>& inorder, const vector<int>& postorder) {
    unordered_map<int,int> inorder_pos_hm;
    // Make a copy of Post Order, so when Util modifies the array
    // The original array stays intact
    vector<int> postorder_copy(postorder.begin(), postorder.end());
    
    for(int i = 0; i < inorder.size(); i++) {
        inorder_pos_hm[inorder[i]] = i;
    }
    
    return constructBinaryTreeUtil(postorder_copy, inorder, 0, inorder.size() - 1, inorder_pos_hm);
}

TreeNode* constructBinaryTreeUtil(vector<int>& postorder,
                                  const vector<int>& inorder, int start, int end,
                                  const unordered_map<int,int>& inorder_pos_hm) {
    if (start > end) return NULL;

    TreeNode* root = new TreeNode(postorder.back());
    postorder.pop_back();

    int root_pos = inorder_pos_hm.at(root->val);

    root->right = 
    constructBinaryTreeUtil(postorder, inorder, root_pos+1, end, inorder_pos_hm);

    root->left = 
    constructBinaryTreeUtil(postorder, inorder, start, root_pos - 1, inorder_pos_hm);

    return root;
}
