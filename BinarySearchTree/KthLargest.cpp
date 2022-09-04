#include <iostream>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

class Node {
public:
    int val;
    int rightSubTreeCount;
    Node* left;
    Node* right;

    Node (int val_p = 0, int count = 0) : val(val_p), 
                                          rightSubTreeCount(count),
                                          left(NULL), right(NULL) {}
};


class KthLargest {
private:
    Node* root;
    int k;
public :
    KthLargest(int k_param, vector<int>& nums) : k(k_param - 1) {
        root = NULL;
        for (int i = 0; i < nums.size(); i++) {
            root = add (root, nums[i]);
        }
    }

    Node* add(Node* root, int val) {
        if (!root) return new Node(val);
        else if(root->val > val) {
            root->left = add(root->left, val);
        } else {
            root->rightSubTreeCount++;
            root->right = add(root->right, val);
        }

        return root;
    }

    Node* findKthLargest(Node* root, int largerEltCount) {
        if (largerEltCount == k) return root;
        else if (largerEltCount > k) {
            int rightCount = largerEltCount - (root->rightSubTreeCount - root->right->rightSubTreeCount);
            return findKthLargest(root->right, rightCount);
        } else {
            int leftCount = largerEltCount + 1 + root->left->rightSubTreeCount;
            return findKthLargest(root->left, leftCount);
        }
    }

    Node* add(int val) {
        root = add(root, val);
        return findKthLargest(root, root->rightSubTreeCount);
    }

};