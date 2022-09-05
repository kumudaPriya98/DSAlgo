#include <iostream>
#include <vector>
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

vector<TreeNode *> generateTrees(int n)
{
    return generateTreesUtil(1, n);
}

vector<TreeNode *> generateTreesUtil(int start, int end)
{
    if (start > end)
        return {NULL};
    if (start == end)
        return {new TreeNode(start)};

    vector<TreeNode *> result;
    for (int i = start; i <= end; i++)
    {
        vector<TreeNode *> leftSubTrees = generateTreesUtil(start, i - 1);
        vector<TreeNode *> rightSubTrees = generateTreesUtil(i + 1, end);

        for (int j = 0; j < leftSubTrees.size(); j++)
        {
            for (int k = 0; k < rightSubTrees.size(); k++)
            {
                result.push_back(new TreeNode(i, leftSubTrees[j], rightSubTrees[k]));
            }
        }
    }
    return result;
}