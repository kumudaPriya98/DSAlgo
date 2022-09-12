#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(nlogn)  Space Complexity : O(n)
vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    return getSkyLineRecursion(buildings, 0, buildings.size() - 1);
}

vector<vector<int>> getSkyLineRecursion(vector<vector<int>> &buildings, int start, int end)
{
    if (start > end)
        return {};
    if (start == end)
        return {{buildings[start][0], buildings[start][2]}, {buildings[start][1], 0}};

    int mid = start + (end - start) / 2;
    vector<vector<int>> leftSkyLine = getSkyLineRecursion(buildings, start, mid);
    vector<vector<int>> rightSkyLine = getSkyLineRecursion(buildings, mid + 1, end);
    return mergeSkyLines(leftSkyLine, rightSkyLine);
}

vector<vector<int>> mergeSkyLines(vector<vector<int>> skyline1, vector<vector<int>> skyline2)
{
    int ptr1 = 0, ptr2 = 0;
    vector<vector<int>> result;
    int prevHeight1 = 0, prevHeight2 = 0;
    while (ptr1 < skyline1.size() && ptr2 < skyline2.size())
    {
        if (skyline1[ptr1][0] < skyline2[ptr2][0])
        {
            if (skyline1[ptr1][1] > max(prevHeight1, prevHeight2))
            { // A taller building has started
                result.push_back(skyline1[ptr1]);
            }
            else if (prevHeight1 > max(skyline1[ptr1][1], prevHeight2))
            { // Curr tallest building has ended
                result.push_back({skyline1[ptr1][0], max(skyline1[ptr1][1], prevHeight2)});
            }
            prevHeight1 = skyline1[ptr1++][1];
        }
        else if (skyline1[ptr1][0] > skyline2[ptr2][0])
        {
            if (skyline2[ptr2][1] > max(prevHeight1, prevHeight2))
            { // A taller building has started
                result.push_back(skyline2[ptr2]);
            }
            else if (prevHeight2 > max(skyline2[ptr2][1], prevHeight1))
            { // Curr tallest building has ended
                result.push_back({skyline2[ptr2][0], max(prevHeight1,skyline2[ptr2][1] )});
            }
            prevHeight2 = skyline2[ptr2++][1];
        }
        else
        {
            // If both points are start, end or either
            int currHeight = max(skyline1[ptr1][1], skyline2[ptr2][1]);
            if (result.empty() || result.back()[1] != currHeight)
            {
                result.push_back({skyline1[ptr1][0], currHeight});
            }
            prevHeight1 = skyline1[ptr1++][1];
            prevHeight2 = skyline2[ptr2++][1];
        }
    }

    while (ptr1 < skyline1.size())
    {
        result.push_back(skyline1[ptr1++]);
    }

    while (ptr2 < skyline2.size())
    {
        result.push_back(skyline2[ptr2++]);
    }
    return result;
}