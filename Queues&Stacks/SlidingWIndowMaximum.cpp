#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B)
{
    vector<int> result;
    deque<int> maxPosDequeue;
    for (int i = 0; i < A.size(); i++)
    {
        while (!maxPosDequeue.empty() && i - maxPosDequeue.front() >= B)
        {
            maxPosDequeue.pop_front();
        }

        while (!maxPosDequeue.empty() && A[maxPosDequeue.back()] <= A[i])
        {
            maxPosDequeue.pop_back();
        }

        maxPosDequeue.push_back(i);

        if (i >= B - 1)
        {
            result.push_back(A[maxPosDequeue.front()]);
        }
    }
    return result;
}
