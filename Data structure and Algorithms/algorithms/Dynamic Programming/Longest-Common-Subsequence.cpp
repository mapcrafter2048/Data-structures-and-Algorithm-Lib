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

int solve(int i, int j, string text1, string text2,
          vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (text1[i] == text2[j])
    {
        return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
    }

    return dp[i][j] = max(solve(i - 1, j, text1, text2, dp),
                          solve(i, j - 1, text1, text2, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(n - 1, m - 1, text1, text2, dp);
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
        string text1, text2;
        inputFile >> text1 >> text2;

        auto startCase = high_resolution_clock::now();
        int result = longestCommonSubsequence(text1, text2);
        auto stopCase = high_resolution_clock::now();
        auto durationCase = duration_cast<milliseconds>(stopCase - startCase);

        ofstream outputFile("output.txt", ios::app);
        if (!outputFile.is_open())
        {
            cerr << "Error opening output.txt" << endl;
            return 1;
        }

        outputFile << "Test case " << i << ": " << result << endl;
        outputFile.close();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}