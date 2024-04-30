/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/
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

vector<vector<int>> dp(101, vector<int>(101, INT_MAX));

int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
    {
        return INT_MAX;
    }

    if (row == grid.size() - 1)
    {
        return grid[row][col];
    }

    if (dp[row][col] != INT_MAX)
    {
        return dp[row][col];
    }

    int ans = INT_MAX;

    ans = min(ans, grid[row][col] + solve(row + 1, col, grid, dp));
    ans = min(ans, grid[row][col] + solve(row + 1, col - 1, grid, dp));
    ans = min(ans, grid[row][col] + solve(row + 1, col + 1, grid, dp));

    return dp[row][col] = ans;
}

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        ans = min(ans, solve(0, i, matrix, dp));
    }

    return ans;
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<vector<int>> matrix = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    cout << minFallingPathSum(matrix) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}