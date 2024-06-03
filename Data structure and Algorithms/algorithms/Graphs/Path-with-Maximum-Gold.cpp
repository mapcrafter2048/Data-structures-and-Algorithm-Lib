/*
In a gold mine grid of size m x n, each cell in this mine has an integer
representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has
some gold.
*/
#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

vector<int> delrow = {1, -1, 0, 0};
vector<int> delcol = {0, 0, -1, 1};

int dfs(vector<vector<int>> &grid, int row,
        int col) { // Pass grid by reference
    int n = grid.size();
    int m = grid[0].size();

    if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == 0) {
        return 0;
    }

    int curr = grid[row][col];
    grid[row][col] = 0; // Mark as visited
    int maxGold = curr;

    for (int i = 0; i < 4; i++) {
        int newRow = row + delrow[i];
        int newCol = col + delcol[i];
        maxGold = max(maxGold, curr + dfs(grid, newRow, newCol));
    }

    grid[row][col] = curr; // Restore the value after exploration
    return maxGold;
}

int getMaximumGold(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int maxGold = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, dfs(grid, i, j));
            }
        }
    }

    return maxGold;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    vector<vector<int>> grid = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << getMaximumGold(grid) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}