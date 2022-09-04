#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> arr; 
    int head;
    int count;
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        int head = 0;
        int count = 0;
    }

    int front() {
        return isEmpty() ? -1 : arr[head]; 
    }

    int rear() {
        return isEmpty() ? -1 : arr[(head + count - 1) % arr.size()];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == arr.size();
    }

    bool enQueue(int val) {
        if (isFull()) return false;
        arr[(head + count) % arr.size()] = val;
        count++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1)% arr.size();
        count--;
        return true;
    }
};