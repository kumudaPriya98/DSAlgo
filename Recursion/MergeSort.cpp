#include <iostream>
#include <vector>
using namespace std;

/*
* Top Down Approach : 
*for len = 2; len < n; len *= 2;   
* while start + len < n
*  Merge [start, start + len - 1], [start + len, min(n - 1, start + 2 * len - 1)] 
*  start = start + 2*len
*/


void mergeSortIterative(vector<int>& nums) {
    int n = nums.size();
    for (int len = 1; len < n; len *= 2) {
        int start = 0;
        while (start + len < n) { // Until 2nd array is not empty
            merge(nums, start, start + len - 1, min(n - 1, start + 2 * len - 1));
            start = start + 2 * len;
        }
    }
}

/*
 * Bottom Down Approach : Divide and Conquer
 * Divide arr to 2 halves [start, mid] [mid + 1, right]
 * merge_sort both halves
 * merge the 2 sorted halves
 *
 * Time Complexity O(nlogn), Space Complexity O(n)
 *
 */

vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums);
    return nums;
}

void mergeSort(vector<int> &nums)
{
    mergeSortUtil(nums, 0, nums.size() - 1);
}

void mergeSortUtil(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSortUtil(nums, start, mid);
    mergeSortUtil(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

void merge(vector<int> &nums, int start, int mid, int end)
{
    vector<int> dummy;

    int ptr1 = start, ptr2 = mid + 1;
    while (ptr1 <= mid && ptr2 <= end)
    {
        if (nums[ptr1] <= nums[ptr2])
        {
            dummy.push_back(nums[ptr1++]);
        }
        else
        {
            dummy.push_back(nums[ptr2++]);
        }
    }
    while (ptr1 <= mid)
    {
        dummy.push_back(nums[ptr1++]);
    }

    while (ptr2 <= end)
    {
        dummy.push_back(nums[ptr2++]);
    }

    for (int i = 0; i < dummy.size(); i++)
    {
        nums[start + i] = dummy[i];
    }
}