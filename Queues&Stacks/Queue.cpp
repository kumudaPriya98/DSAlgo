#include <iostream>
#include <vector>

using namespace std;

class Queue {
    vector<int> nums;
    int head;
public:
    Queue() : head(0) {}

    void push(int val) {
        nums.push_back(val);
    }

    int pop() {
        if (isEmpty()) return INT_MIN;
        return nums[head++];
    }

    int front() {
        if (isEmpty()) return INT_MIN;
        return nums[head];
    }

    bool isEmpty() {
        return head == nums.size(); 
    }
};