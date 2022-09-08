#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<string> generateParenthesis(int n)
{
    vector<set<string>> paranthesisSets;
    paranthesisSets.push_back({""});

    for (int i = 1; i <= n; i++)
    {
        set<string> currParanthesisSet;
        for (int j = 1; j <= i - 1; j++)
        {
            for (auto s1 : paranthesisSets[j])
            {
                for (auto s2 : paranthesisSets[i - j])
                {

                    currParanthesisSet.insert(s1 + s2);
                }
            }
        }
        for (auto s1 : paranthesisSets[i - 1])
            currParanthesisSet.insert("(" + s1 + ")");

        paranthesisSets.push_back(currParanthesisSet);
    }

    vector<string> result;
    for (auto s1 : paranthesisSets.back())
        result.push_back(s1);
    return result;
}