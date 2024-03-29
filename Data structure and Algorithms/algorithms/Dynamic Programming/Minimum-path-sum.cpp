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

int solve(int row, int col, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (row >= m || col >= n)
    {
        return INT_MAX;
    }

    if (row == m - 1 && col == n - 1)
    {
        return dp[row][col] = grid[row][col];
    }

    if (dp[row][col] != INT_MAX)
    {
        return dp[row][col];
    }

    int downCost = solve(row + 1, col, m, n, grid, dp);
    int rightCost = solve(row, col + 1, m, n, grid, dp);

    return dp[row][col] = grid[row][col] + min(downCost, rightCost);
}

int minPathSum(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    return solve(0, 0, m, n, grid, dp);
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("input2.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening input2.txt" << endl;
        return 1; // Indicate failure
    }

    int numTestCases;
    inputFile >> numTestCases;

    for (int testCase = 1; testCase <= numTestCases; ++testCase)
    {
        int numRows, numCols;
        inputFile >> numRows >> numCols;

        vector<vector<int>> grid(numRows, vector<int>(numCols));
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                inputFile >> grid[i][j];
            }
        }
        auto startCase = high_resolution_clock::now();
        int result = minPathSum(grid);
        auto stopCase = high_resolution_clock::now();
        auto durationCase = duration_cast<milliseconds>(stopCase - startCase);

        ofstream outputFile("output.txt", ios::app);
        if (!outputFile.is_open())
        {
            cerr << "Error opening output.txt" << endl;
            return 1; // Indicate failure
        }

        outputFile << "Test case " << testCase << ": " << result << endl;
        outputFile.close();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}