#include <iostream>
#include "TreeNode.hpp"

using namespace std;

//constraint: P and Q exist in the BST and all elts in BST are unique
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > q->val) return LCA (root, q, p);
    if (root == p || root == q) return root;
    else if (root->val > p->val && root->val < q->val) return root;
    else if (root->val > p->val) return LCA(root->left, p, q);
    else return LCA(root->right, p, q);
}