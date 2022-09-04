#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> slidingWindow;
    int max_size;
    int sum;

public:
    MovingAverage(int sz) : max_size(sz) , sum(0) {}

    double next(int val) {
        slidingWindow.push(val);
        sum += val;

        if (slidingWindow.size() > max_size) {
            sum -= slidingWindow.front();
            slidingWindow.pop();
        }

        return (double)sum/slidingWindow.size();
    }
};