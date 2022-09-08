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
    combineUtil(arr, k, 0, INT_MIN, result);
    return result;
}

void combineUtil(vector<int> &arr, int k, int start, int prev, vector<vector<int>> &result)
{
    if (start == k)
    {
        result.push_back(vector<int>(arr.begin(), arr.begin() + k));
        return;
    }

    for (int i = start; i < arr.size(); i++)
    {
        if (arr[i] > prev)
        {
            swap(arr[i], arr[start]);
            combineUtil(arr, k, start + 1, arr[start], result);
            swap(arr[i], arr[start]);
        }
    }
}