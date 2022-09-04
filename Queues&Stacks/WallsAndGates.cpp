#include <iostream>
#include <vector>
#include <queue>
#include <pair>

using namespace std;

const int EMPTY =  INT_MAX;
const int GATE = 0;
const int WALL = -1;

void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.size() == 0) return;

    queue<pair<int, int>> bfsQueue;
    vector<pair<int, int>> adjDists = {make_pair(1,0), make_pair(0,1),
                                  make_pair(-1,0), make_pair(0,-1)};

    for (int i = 0; i < rooms.size(); i++) {
        for (int j = 0; j < rooms[0].size(); j++) {
            if (rooms[i][j] == GATE)
                bfsQueue.push(make_pair(i,j));
        }
    }

    auto isValid = [&](pair<int,int> neighbourRoom) {
        int x_cord = neighbourRoom.first, y_cord = neighbourRoom.second;

        if (x_cord < 0 ||  x_cord >= rooms.size() ||
            y_cord < 0 ||  y_cord >= rooms.size() ||
            rooms[x_cord][y_cord] != INT_MAX) {
            return false;
        }

        return true;
    };

    int currDist = 1;
    while (!bfsQueue.empty()) {
        int currQueueSize = bfsQueue.size();
        for (int i = 0; i < currQueueSize; i++) {
            pair<int, int> currRoom = bfsQueue.front();
            bfsQueue.pop();

            for (auto adjDist : adjDists) {
                auto adjPair = make_pair(currRoom.first + adjDist.first,
                                        currRoom.second + adjDist.second);
                if (isValid(adjPair)) {
                    rooms[adjPair.first][adjPair.second] = currDist;
                    bfsQueue.push(adjPair);
                }
            }           
        }
        currDist++;
    }
}