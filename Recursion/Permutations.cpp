#include <iostream>
#include <vector>
using namespace std;

// Constraint : All the intergers in nums are unique
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    permuteUtil(nums, result, 0);
    return result;
}

void permuteUtil(vector<int> &nums, vector<vector<int>> &result, int curr)
{
    if (curr == nums.size())
    {
        result.push_back(vector<int>(nums));
        return;
    }

    for (int i = curr; i < nums.size(); i++)
    {
        swap(nums[i], nums[curr]);
        permuteUtil(nums, result, curr + 1);
        swap(nums[i], nums[curr]);
    }
}