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

const int MOD = 1000000007;

int solve(int m, int n, int maxMove, int startRow, int startColumn,
          vector<vector<vector<int>>> &dp)
{
    if (startRow < 0 || startColumn < 0 || startRow >= m ||
        startColumn >= n)
    {
        return 1;
    }

    if (maxMove == 0)
    {
        return 0; // No moves remaining
    }

    if (dp[startRow][startColumn][maxMove] != -1)
    {
        return dp[startRow][startColumn][maxMove];
    }

    long long paths = 0; // Use long long to handle large numbers
    paths =
        (paths + solve(m, n, maxMove - 1, startRow + 1, startColumn, dp)) %
        MOD; // Move down
    paths =
        (paths + solve(m, n, maxMove - 1, startRow - 1, startColumn, dp)) %
        MOD; // Move up
    paths =
        (paths + solve(m, n, maxMove - 1, startRow, startColumn + 1, dp)) %
        MOD; // Move right
    paths =
        (paths + solve(m, n, maxMove - 1, startRow, startColumn - 1, dp)) %
        MOD; // Move left

    dp[startRow][startColumn][maxMove] = paths;

    return paths;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
    return solve(m, n, maxMove, startRow, startColumn, dp);
}

int main()
{
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}