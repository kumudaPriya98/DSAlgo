#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> letterCombinations(string digits)
{
    // When digits is empty return {}
    if (digits.empty())
        return vector<string>();

    vector<string> dir = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string temp = "";
    vector<string> result;
    letterCombinationsUtil(digits, dir, 0, temp, result);
    return result;
}

void letterCombinationsUtil(string digits, vector<string> &dir, int curr_pos, string &temp, vector<string> &result)
{
    if (curr_pos == digits.size())
    {
        result.push_back(temp);
    }

    char curr_char = digits[curr_pos];
    for (int i = 0; i < dir[curr_char - '0'].size(); i++)
    {
        temp.push_back(dir[curr_char - '0'][i]);
        letterCombinationsUtil(digits, dir, curr_pos + 1, temp, result);
        temp.pop_back();
    }
}