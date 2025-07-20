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

int solve(string word1, string word2, int i, int j,
          vector<vector<int>> &dp)
{
    if (i >= word1.length())
    {
        return word2.length() - j;
    }
    if (j >= word2.length())
    {
        return word1.length() - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    if (word1[i] == word2[j])
    {
        ans = solve(word1, word2, i + 1, j + 1, dp);
    }
    else
    {
        int replaced = 1 + solve(word1, word2, i + 1, j + 1, dp);
        int deleted = 1 + solve(word1, word2, i + 1, j, dp);
        int inserted = 1 + solve(word1, word2, i, j + 1, dp);
        ans = min(replaced, min(deleted, inserted));
    }

    dp[i][j] = ans;
    return dp[i][j];
}

int minDistance(string word1, string word2)
{

    if (word1.length() == 0)
        return word2.length();
    if (word2.length() == 0)
        return word1.length();
    int i = 0, j = 0;
    vector<vector<int>> dp(word1.length() + 1,
                           vector<int>(word2.length() + 1, -1));
    return solve(word1, word2, i, j, dp);
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("Edit-String.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening Edit-String.txt" << endl;
        return 1;
    }

    int numTestCases;
    inputFile >> numTestCases;

    for (int i = 1; i <= numTestCases; i++)
    {
        string word1, word2;
        inputFile >> word1 >> word2;

        auto startCase = high_resolution_clock::now();
        int result = minDistance(word1, word2);
        auto stopCase = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stopCase - startCase);

        ofstream outputFile("Edit-distance-output.txt", ios::app);
        if (!outputFile.is_open())
        {
            cerr << "Error opening Edit-distance-output.txt" << endl;
            return 1;
        }
        outputFile << "Test case " << i << ": " << result << " Completed in " << duration.count() << " nanoseconds" << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}