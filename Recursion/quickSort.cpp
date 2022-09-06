#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void quickSort(vector<int> &nums)
{
    quickSortUtil(nums, 0, nums.size() - 1);
}

void quickSortUtil(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(nums, start, end);
    quickSortUtil(nums, start, pivot - 1);
    quickSortUtil(nums, pivot + 1, end);
}

int partition(vector<int> &nums, int start, int end)
{
    // To avoid O(n2) if nums is already sorted
    int rand_pos = start + rand() % (end - start + 1);
    swap(nums[start], nums[rand_pos]);

    int pivot = start;
    int pivot_val = nums[start];

    for (int i = start + 1; i <= end; i++)
    {
        if (nums[i] < pivot_val)
        {
            // nums[pivot] is currently empty
            //  so insert the small no in nums[pivot]
            nums[pivot] = nums[i];

            // Now make sure, next pivot would be empty,
            // by placing nums[pivot + 1] in nums[i]
            nums[i] = nums[pivot + 1];

            pivot++;
        }
    }
    nums[pivot] = pivot_val;
    return pivot;
}