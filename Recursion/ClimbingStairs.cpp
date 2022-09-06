#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector<int> cache(n+1);
    return climbStairsUtil(n, cache);
}

int climbStairsUtil(int n, vector<int>& cache) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (cache[n] == 0) {
        cache[n] = climbStairsUtil(n-2, cache) + climbStairsUtil(n-1, cache);
    }
    return cache[n];
}

int climbStairsIterative(int n) {
    if (n == 1 || n == 2) return n;
    int f1 = 1, f2 = 2;
    int result = 0;
    for (int i = 3; i <= n; i++) {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
    }
    return result;
}