#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<vector<int>> sortedPos;
    for (int i = 0; i < buildings.size(); i++)
    {
        // sortedPos has vector of {x_cord, start or end, height}
        // Making sure that, start of buildings come ahead of end of buildings
        // To correctly track ongoing heights (curr_heights)
        sortedPos.push_back({buildings[i][0], 0, buildings[i][2]});
        sortedPos.push_back({buildings[i][1], 1, buildings[i][2]});
    }
    sort(sortedPos.begin(), sortedPos.end());
    map<int, int> curr_heights;
    vector<vector<int>> result;
    for (int i = 0; i < sortedPos.size(); i++)
    {
        int height = sortedPos[i][2];
        if (sortedPos[i][1] == 0) // if curr_mark is start of building
        {
            // Start of building is represented by {x_cord, height}
            // Start of building is inserted only when, no overlapping buildings or
            // this is a tallest building.
            // In other cases, start point will be hidden by other buildings
            if (curr_heights.empty() || curr_heights.rbegin()->first < height)
            {
                // Take care of {x_cord, 0, h1}, {x_cord, 0, h2} where h1 <= h2
                if (!result.empty() && result.back()[0] == sortedPos[i][0])
                    result.pop_back();
                result.push_back({sortedPos[i][0], height});
            }
            curr_heights[height]++;
        }
        else // if curr_mark is end of building
        {

            // End of building is represented by {x_cord, 0 or overlapping smaller building}
            // I.E End of building is inserted only when, no overlapping buildings with endpoint or
            // overlapping building is smaller is size.
            // In other cases, end point will be hidden by other buildings

            // If there is no key with height, remove it, for calculating correct curr_heights.rbegin()->first
            // I.E Tallest building at current x_pos
            if (curr_heights[height] == 1)
                curr_heights.erase(height);
            else
                curr_heights[height]--;

            if (curr_heights.empty())
                result.push_back({sortedPos[i][0], 0});
            else if (curr_heights.rbegin()->first < height)
            {
                result.push_back({sortedPos[i][0], curr_heights.rbegin()->first});
            }
        }
    }
    return result;
}