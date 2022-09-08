#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode *p, TreeNode *q)
{
    stack<pair<TreeNode *, TreeNode *>> preOrderStack;
    preOrderStack.push(make_pair(p, q));

    while (!preOrderStack.empty())
    {
        auto top = preOrderStack.top();
        preOrderStack.pop();

        if (!top.first && !top.second)
            ;
        else if (!top.first || !top.second)
            return false;
        else if (top.first->val != top.second->val)
            return false;
        else
        {
            preOrderStack.push(make_pair(top.first->right, top.second->right));
            preOrderStack.push(make_pair(top.first->left, top.second->left));
        }
    }
    return true;
}