#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

bool solve(int i, int j, int k, vector<vector<vector<int>>> &dp, string s1,
           string s2, string s3)
{
    if ((i == s1.length() && j == s2.length() && k == s3.length()))
    {
        return true;
    }

    if (dp[i][j][k] != -1)
    {
        return dp[i][j][k];
    }

    bool result = false;
    if (i < s1.length() && s1[i] == s3[k])
    {
        result = result || solve(i + 1, j, k + 1, dp, s1, s2, s3);
    }

    if (j < s2.length() && s2[j] == s3[k])
    {
        result = result || solve(i, j + 1, k + 1, dp, s1, s2, s3);
    }

    return dp[i][j][k] = result;
}

bool isInterleave(string s1, string s2, string s3)
{
    if (s1.length() + s2.length() != s3.length())
    {
        return false;
    }
    vector<vector<vector<int>>> dp(
        s1.length() + 1,
        vector<vector<int>>(s2.length() + 1,
                            vector<int>(s3.length() + 1, -1)));
    return solve(0, 0, 0, dp, s1, s2, s3);
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("input3.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input3.txt" << endl;
        return 1;
    }

    int numTestCases;
    inputFile >> numTestCases;

    for (int i = 1; i <= numTestCases; i++)
    {
        string text1, text2, text3;
        inputFile >> text1 >> text2 >> text3;

        auto startCase = high_resolution_clock::now();
        int result = isInterleave(text1, text2, text3);
        auto stopCase = high_resolution_clock::now();
        auto durationCase = duration_cast<milliseconds>(stopCase - startCase);

        ofstream outputFile("Decode-ways-output.txt", ios::app);
        if (!outputFile.is_open())
        {
            cerr << "Error opening output.txt" << endl;
            return 1;
        }

        outputFile << "Test case " << i << ": " << result << " and the tme of execution is " << durationCase.count() << endl;
        outputFile.close();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}