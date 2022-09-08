#include <iostream>
#include <vector>
#include <set>
#include <pair>
using namespace std;

class Robot
{
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};

void cleanRoom(Robot &robot)
{
    recurse_backtrack(robot);
}

void recurse_backtrack(Robot &robot)
{
    set<pair<int, int>> visited;
    pair<int, int> curr_dir(-1, 0);
    pair<int, int> curr_pos(0, 0);

    recurse_backtrack(robot, visited, curr_pos, curr_dir);
}

void recurse_backtrack(Robot &robot, set<pair<int, int>> &visited, pair<int, int> curr_pos,
                       pair<int, int> curr_dir)
{

    visited.insert(curr_pos);
    robot.clean();

    for (int i = 1; i <= 4; i++)
    {
        robot.turnLeft();
        pair<int, int> next_dir = turnLeft(curr_dir);
        pair<int, int> next_pos = make_pair(curr_pos.first + next_dir.first,
                                            curr_pos.second + next_dir.second);

        if (visited.find(next_pos) == visited.end() && robot.move())
        {
            recurse_backtrack(robot, visited, next_pos, next_dir);

            // TURN 180 DEGRESS TO REACH Opposite of next_dir
            robot.turnLeft();
            robot.turnLeft();
            // Move to the Parent Node
            robot.move();
            // TURN 180 DEGRESS TO turn to next_dir
            robot.turnLeft();
            robot.turnLeft();
        }
        curr_dir = next_dir;
    }
}

pair<int, int> turnLeft(pair<int, int> curr_dir)
{
    if (curr_dir.first == -1 && curr_dir.second == 0)
        return make_pair(0, -1);
    else if (curr_dir.first == 0 && curr_dir.second == -1)
        return make_pair(1, 0);
    else if (curr_dir.first == 1 && curr_dir.second == 0)
        return make_pair(0, 1);
    return make_pair(-1, 0);
}
