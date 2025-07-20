/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


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

int dfs(int row, int col, vector<vector<int>> &grid)
{
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0)
    {
        return 1;
    }

    if (grid[row][col] == -1)
    {
        return 0;
    }

    grid[row][col] = -1;

    return (dfs(row + 1, col, grid) + dfs(row - 1, col, grid) +
            dfs(row, col + 1, grid) + dfs(row, col - 1, grid));
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (grid[r][c] == 1)
            {
                perimeter += dfs(r, c, grid);
            }
        }
    }

    return perimeter;
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