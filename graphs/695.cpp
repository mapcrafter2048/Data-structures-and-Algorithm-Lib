#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
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

/*
You are given an m x n binary matrix grid. An island is a group of 1's
(representing land) connected 4-directionally (horizontal or vertical.) You may
assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.
*/

/*
Solution Logic:

The problem is to find the maximum area of an island in a binary matrix. An
island is defined as a group of connected 1's (land) in the matrix. The
connectivity is 4-directional (up, down, left, right). If there are no islands,
the function should return 0.

Steps of Implementation:

1. **Define a Depth-First Search (DFS) Function**:
    - The DFS function is used to traverse the grid and calculate the area of an
island.
    - It takes the grid, a visited matrix, and the current cell's row and column
as input.
    - If the current cell is out of bounds, already visited, or water (0), the
function returns 0.
    - Otherwise, mark the cell as visited and recursively call DFS for its 4
neighbors (up, down, left, right).
    - Return the total area of the island by summing up the results of the
recursive calls and adding 1 for the current cell.

2. **Initialize a Visited Matrix**:
    - Create a 2D vector `visited` of the same size as the grid, initialized to
`false`. This matrix keeps track of which cells have already been visited during
the DFS traversal.

3. **Iterate Through the Grid**:
    - Loop through each cell in the grid.
    - If the cell is land (1) and has not been visited, call the DFS function to
calculate the area of the island starting from that cell.
    - Update the maximum area (`maxi`) if the area returned by DFS is greater
than the current maximum.

4. **Return the Maximum Area**:
    - After iterating through all cells, return the value of `maxi`, which holds
the maximum area of an island found in the grid.

The algorithm ensures that each cell is visited only once, making the time
complexity O(m * n), where m and n are the dimensions of the grid. The space
complexity is also O(m * n) due to the `visited` matrix and the recursion stack.

This approach efficiently calculates the maximum area of an island in the given
binary matrix.
*/

class Solution {
  public:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row,
            int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            visited[row][col] || grid[row][col] == 0) {
            return 0;
        }

        visited[row][col] = true;
        return 1 + dfs(grid, visited, row + 1, col) +
               dfs(grid, visited, row - 1, col) +
               dfs(grid, visited, row, col + 1) +
               dfs(grid, visited, row, col - 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        int maxi = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxi = max(maxi, dfs(grid, visited, i, j));
                }
            }
        }

        return maxi;
    }
};

class Solution2 {
  public:
    void dfs(int node, vector<vector<int>> &stones, vector<bool> &visited,
             vector<vector<int>> &graph) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, stones, visited, graph);
            }
        }
    }

    int removeStones(vector<vector<int>> &stones) {
        int n = stones.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, stones, visited, graph);
                comp++;
            }
        }
        return n - comp;
    }
};
