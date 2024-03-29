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

/// @brief The problem statment : The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately. Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers). To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step. Return the knight's minimum initial health so that he can rescue the princess.Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
/// @param row The x coordinate of the grid
/// @param col The y coordinate of the grid
/// @param grid The 2D grid
/// @param dp The 2D dp array
/// @return
int solve(int row, int col, vector<vector<int>> &grid,
          vector<vector<int>> &dp)
{
    int m = grid.size();
    int n = grid[0].size();

    if (row == m - 1 && col == n - 1)
    {
        return max(1, 1 - grid[row][col]);
    }

    if (row >= m || col >= n)
    {
        return INT_MAX;
    }
    if (dp[row][col] != 0)
    {
        return dp[row][col];
    }

    int sum1 = solve(row + 1, col, grid, dp);
    int sum2 = solve(row, col + 1, grid, dp);

    dp[row][col] = min(sum1, sum2) - grid[row][col];

    // If the value of dp[row][col] is less than 1, then we need to make it 1 because the knight must have at least 1 health point to survive

    dp[row][col] = max(1, dp[row][col]);
    return dp[row][col];
}

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int m = dungeon.size();
    int n = dungeon[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return solve(0, 0, dungeon, dp);
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
        int result = calculateMinimumHP(grid);
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