/*
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any
adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan
distance from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r
+ 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| +
|b - y|, where |val| denotes the absolute value of val.
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

/*
The motivation behind this question that first we use either of bfs or dfs to
mark each cell with the distance form  the nearest thief cell. Then we use
Dijkstra's algorithm to find the maximum safety factor path.

why do we use Dijkstra algorithm is because we want to find the the path such
that the distance of each cell in the path is maximum from the nearest one and
since in the bfs we have marked each cell with distace from thief cell we are
essintally finding the path with the max sum which is the max distance
*/

class Solution {
  public:
    void printGrid(vector<vector<int>> &grid) {
        for (auto row : grid) {
            for (auto cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    vector<int> delrow = {0, 0, 1, -1};
    vector<int> delcol = {1, -1, 0, 0};

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &score) {
        int n = grid.size();
        queue<pair<int, int>> q;

        // Initialize the queue and score for thief cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    score[i][j] = 0;
                    q.push({i, j});
                } else {
                    score[i][j] = INT_MAX;
                }
            }
        }

        printGrid(score);
        cout << endl;

        // Standard BFS to calculate minimum distance to the nearest thief for
        // each cell
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + delrow[i];
                int newCol = col + delcol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    score[newRow][newCol] == INT_MAX) {
                    score[newRow][newCol] = score[row][col] + 1;
                    q.push({newRow, newCol});
                }
                printGrid(score);
                cout << endl;
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>> &grid) {
        int n = grid.size();

        // Base cases: start or end on a thief cell
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score); // Calculate distances to thieves

        // Dijkstra's Algorithm to find the maximum safety factor path
        priority_queue<pair<int, pair<int, int>>>
            pq; // Max-heap based on safety factor
        pq.push({score[0][0], {0, 0}});

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        while (!pq.empty()) {
            int safe = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (visited[x][y])
                continue;
            visited[x][y] = true;

            if (x == n - 1 && y == n - 1) {
                return safe; // Reached the target
            }

            for (int i = 0; i < 4; i++) {
                int newRow = x + delrow[i];
                int newCol = y + delcol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    !visited[newRow][newCol]) {
                    int newSafe = min(safe, score[newRow][newCol]);
                    pq.push({newSafe, {newRow, newCol}});
                }
            }
        }
        return -1; // Should not happen if a path exists
    }
};

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    vector<vector<int>> grid = {
        {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    Solution solution;
    cout << solution.maximumSafenessFactor(grid) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}