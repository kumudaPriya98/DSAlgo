#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
    vector<int> cache(n + 1, 0);
    return fibUtil(n, cache);
}

int fibUtil(int n, vector<int> &cache)
{
    if (n == 0 || n == 1)
    {
        cache[n] = n;
    }
    else if (cache[n] == 0)
    {
        cache[n] = fibUtil(n - 2, cache) + fibUtil(n - 1, cache);
    }
    return cache[n];
}