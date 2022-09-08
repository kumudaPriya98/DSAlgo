#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node() {}

    Node(int _val)
    {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node *_left, Node *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

Node *treeToDoublyList(Node *root)
{
    if (!root)
        return root;
    Node *head;
    Node *tail;
    Node *prev = NULL;

    treeToDoublyListUtil(root, prev, head, tail);
    tail->right = head;
    head->left = tail;
    return head;
}

void treeToDoublyListUtil(Node *root, Node *&prev, Node *&head, Node *&tail)
{
    if (!root)
        return;

    treeToDoublyListUtil(root->left, prev, head, tail);

    if (!prev)
    {
        head = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
    }

    tail = root;
    prev = root;

    treeToDoublyListUtil(root->right, prev, head, tail);
}