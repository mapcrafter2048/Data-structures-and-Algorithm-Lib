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
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal
4-directionally connected group of 0s and a closed island is an island totally
(all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

/*
Solution Logic:

The problem is to find the number of closed islands in a 2D grid. A closed
island is defined as a group of connected land cells (0s) that are completely
surrounded by water cells (1s) on all sides, including the boundaries of the
grid.

Steps of Implementation:

1. **Input Representation**:
    - The grid is represented as a 2D vector of integers, where `0` represents
land and `1` represents water.

2. **Helper Function (bfs)**:
    - A Breadth-First Search (BFS) function is implemented to traverse the grid
and check if a group of connected land cells forms a closed island.
    - The BFS starts from a given cell `(i, j)` and explores all its
4-directionally connected neighbors (up, down, left, right).
    - If any part of the island touches the boundary of the grid, it is not
considered closed.
    - A queue is used to perform the BFS, and a `visited` matrix is used to keep
track of the cells that have already been processed.

3. **Direction Vectors**:
    - Two vectors, `X` and `Y`, are used to simplify the traversal of the 4
possible directions (up, down, left, right).

4. **Grid Traversal**:
    - The main function `closedIsland` iterates through each cell in the grid.
    - If a cell is land (`0`) and has not been visited, the BFS function is
called to determine if the island is closed.
    - If the BFS returns `true`, the count of closed islands is incremented.

5. **Edge Cases**:
    - If the grid is empty or has no land cells, the result is `0`.
    - Islands that touch the boundary of the grid are not counted as closed.

6. **Output**:
    - The function returns the total count of closed islands.

The algorithm ensures that each cell is visited at most once, making the time
complexity approximately O(m * n), where `m` is the number of rows and `n` is
the number of columns in the grid.
*/

class Solution {
  public:
    bool bfs(int i, int j, int m, int n, vector<vector<int>> &grid,
             vector<vector<bool>> &visited) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;
        bool closed = true;

        vector<int> X{0, 1, 0, -1};
        vector<int> Y{-1, 0, 1, 0};

        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int newR = i + X[k];
                int newC = j + Y[k];
                if (newR < 0 || newR >= m || newC < 0 || newC >= n) {
                    closed = false;
                } else if (grid[newR][newC] == 0 && !visited[newR][newC]) {
                    q.push({newR, newC});
                    visited[newR][newC] = true;
                }
            }
        }

        return closed;
    }

    int closedIsland(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && !visited[i][j] &&
                    bfs(i, j, m, n, grid, visited)) {
                    count++;
                }
            }
        }
        return count;
    }
};