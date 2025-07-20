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

double solve(int row, int col, int moves, int n,
             vector<vector<vector<double>>> &dp)
{
    if (moves == 0)
    {
        return 1.0;
    }
    if (dp[row][col][moves] != -1)
    {
        return dp[row][col][moves];
    }
    vector<int> delrow = {-2, -2, -1, 1, 2, 2, 1, -1};
    vector<int> delcol = {-1, 1, 2, 2, 1, -1, -2, -2};
    double ans = 0.0;

    for (int i = 0; i < 8; i++)
    {
        int nr = row + delrow[i];
        int nc = col + delcol[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n)
        {
            ans += solve(nr, nc, moves - 1, n, dp);
        }
    }

    return dp[row][col][moves] = ans;
}

double knightProbability(int n, int k, int row, int column)
{
    vector<vector<vector<double>>> dp(
        n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));
    double ct = solve(row, column, k, n, dp);
    for (int i = 0; i < k; i++)
    {
        ct = ct / 8;
    }

    return ct;
}

int main()
{
    auto start = high_resolution_clock::now();

    int n = 3, k = 2, row = 0, column = 0;
    cout << knightProbability(n, k, row, column) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}