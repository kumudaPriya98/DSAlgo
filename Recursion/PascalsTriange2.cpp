#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> result(rowIndex + 1);
    getRowUtil(rowIndex, result);
    return result;
}

void getRowUtil(int rowIndex, vector<int> &result)
{
    if (rowIndex == 0)
    {
        result[0] = 1;
    }
    else
    {
        getRowUtil(rowIndex - 1, result);
        for (int i = rowIndex - 1; i > 0; i--)
        {
            result[i] = result[i - 1] + result[i];
        }
        result[rowIndex] = 1;
    }
}