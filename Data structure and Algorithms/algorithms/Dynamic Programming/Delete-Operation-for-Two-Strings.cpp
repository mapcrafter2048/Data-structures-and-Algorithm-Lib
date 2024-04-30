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

int solve(int i, int j, string word1, string word2,
          vector<vector<int>> &dp)
{
    if (i >= word1.length())
    {
        return (word2.length() - j);
    }

    if (j >= word2.length())
    {
        return (word1.length() - i);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (word1[i] == word2[j])
    {
        return dp[i][j] = solve(i + 1, j + 1, word1, word2, dp);
    }
    else
    {
        return dp[i][j] = 1 + min(solve(i + 1, j, word1, word2, dp),
                                  solve(i, j + 1, word1, word2, dp));
    }

    return 0;
}

int minDistance(string word1, string word2)
{
    int n = word1.length(), m = word2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(0, 0, word1, word2, dp);
}

int main()
{
    auto start = high_resolution_clock::now();

    // Your code here
    string word1, word2;
    cin >> word1 >> word2;
    cout << minDistance(word1, word2) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}