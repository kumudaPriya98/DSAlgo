#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combine(int n, int k)
{
    if (k == 0 || k > n)
        return {};

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    vector<vector<int>> result;
    vector<int> dummy;
    combineUtil(arr, k, 0, result, dummy);
    return result;
}

void combineUtil(vector<int> &arr, int k, int start, vector<vector<int>> &result, vector<int> &dummy)
{
    if (dummy.size() == k)
    {
        result.push_back(vector<int>(dummy));
        return;
    }

    for (int i = start; i < arr.size(); i++)
    {
        dummy.push_back(arr[i]);
        combineUtil(arr, k, i + 1, result, dummy);
        dummy.pop_back();
    }
}