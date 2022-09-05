#include <iostream>
using namespace std;

int kthGrammar(int n, int k)
{
    if (n == 1)
        return 0;
    return (kthGrammar(n - 1, (k + 1) / 2) == 0) ^ (k % 2 == 1);
}