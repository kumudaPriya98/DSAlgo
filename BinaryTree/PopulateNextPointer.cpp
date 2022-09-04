#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};



Node* connect(Node* root) {
    if (!root || (!root->left && !root->right)) return root;

    root->left->next = root->right;
    connect(root->left);

    root->right->next = root->next ? root->next->left : NULL;
    connect(root->right);
    
    return root;
}

