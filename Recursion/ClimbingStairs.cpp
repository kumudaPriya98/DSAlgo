#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector<int> cache(n);
    return climbStairsUtil(n, cache);
}

int climbStairsUtil(int n, vector<int>& cache) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (cache[n - 1] == 0) {
        cache[n - 1] = climbStairsUtil(n-3, cache) + climbStairsUtil(n-2, cache);
    }
    return cache[n-1];
}