#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

// Using O(Max nodes in a Level) queue size
Node* connect1(Node* root) {
    if(!root) return root;

    queue<Node*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        int levelCount = nodeQueue.size();

        for (int i = 0; i < levelCount; i++) {
            root = nodeQueue.front();
            nodeQueue.pop();

            nodeQueue.push(root->left);
            nodeQueue.push(root->right);

            if (i != levelCount - 1) {
                root->next = nodeQueue.front();
            }
        }
    }
    return root;
}

// Const Space Solution
Node* connect(Node* root) {
    connect(root, NULL);
    return root;
}

Node* findNextChild(Node** parent, Node* currChild) {
    if (!*parent) return NULL;

    if (currChild == (*parent)->left && (*parent)->right) {
        return (*parent)->right;
    }

    *parent = (*parent)->next;
    while(*parent) {
        if((*parent)->left || (*parent)->right) {
            return (*parent)->left ? (*parent)->left : (*parent)->right;
        }
        *parent = (*parent)->next;
    }
    return NULL;
}

void connect(Node* root, Node* parent) {
    if (!root) return;

    // Connect all the nodes in the current Level
    Node* currChild = root;

    while (Node* nextChild = findNextChild(&parent, currChild)) {
        currChild->next = nextChild;
        currChild = nextChild;
    }    
    
    // Find next level first node and its parent
    Node* nextLevelFirstChild = NULL, *nextLevelFirstChildParent = NULL;
    currChild = root;
    while (currChild) {
        if (currChild->left || currChild->right) {
            nextLevelFirstChild = currChild-> left ? currChild->left : currChild->right;
            nextLevelFirstChildParent = currChild;
            break;
        }
        currChild = currChild->next;
    }

    // Repeat the same for next level
    connect(nextLevelFirstChild, nextLevelFirstChildParent);
}