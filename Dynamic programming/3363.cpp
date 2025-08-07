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
There is a game dungeon comprised of n x n rooms arranged in a grid.

You are given a 2D array fruits of size n x n, where fruits[i][j] represents the
number of fruits in the room (i, j). Three children will play in the game
dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n -
1, 0).

The children will make exactly n - 1 moves according to the following rules to
reach the room (n - 1, n - 1):

    The child starting from (0, 0) must move from their current room (i, j) to
one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room
exists. The child starting from (0, n - 1) must move from their current room (i,
j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the
target room exists. The child starting from (n - 1, 0) must move from their
current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1,
j + 1) if the target room exists.

When a child enters a room, they will collect all the fruits there. If two or
more children enter the same room, only one child will collect the fruits, and
the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.
*/

/*
Detailed Solution Logic and Steps of Implementation:

**Problem Restatement:**
- There is an n x n grid, each cell has some fruits.
- Three children start from three different corners: (0,0), (0,n-1), (n-1,0).
- Each child has a unique set of allowed moves.
- All children must reach (n-1, n-1) in exactly n-1 moves.
- If multiple children visit the same cell, fruits are collected only once.

**Step 1: Analyze the Movement Rules**
- Child 1 (from (0,0)): Can move to (i+1, j), (i, j+1), or (i+1, j+1).
- Child 2 (from (0,n-1)): Can move to (i+1, j), (i+1, j-1), or (i+1, j+1).
- Child 3 (from (n-1,0)): Can move to (i, j+1), (i-1, j+1), or (i+1, j+1).
- All must end at (n-1, n-1) after n-1 moves.

**Step 2: Overlap Handling**
- If two or more children visit the same cell, only one collects the fruits.
- To avoid double-counting, after collecting fruits from a cell, set its value
to zero.

**Step 3: Decompose the Problem**
- The main diagonal (from (0,0) to (n-1,n-1)) is common to all three children.
- Collect all fruits on the main diagonal first and set those cells to zero.
- The remaining two children (from (n-1,0) and (0,n-1)) must reach (n-1,n-1) via
their allowed moves, collecting as many fruits as possible, but not from the
diagonal (already collected).

**Step 4: Dynamic Programming Approach**
- Use DP to maximize the fruits collected for each child, given their movement
rules.
- For each child, define a DP function:
    - `solve2(row, col, fruits, dp)`: For the child starting at (n-1,0),
computes the max fruits from (row, col) to (n-1, n-1).
    - `solve3(row, col, fruits, dp)`: For the child starting at (0,n-1),
computes the max fruits from (row, col) to (n-1, n-1).
- Each DP function uses memoization to avoid recomputation.
- At each step, try all allowed moves, and pick the move that gives the maximum
fruits.

**Step 5: Implementation Steps**
1. Initialize a variable `total` to store the total fruits collected.
2. Traverse the main diagonal, add all fruits on it to `total`, and set those
cells to zero in the grid.
3. For the child starting at (n-1,0), use `solve2(n-1, 0, fruits, dp)` to
compute the max fruits for their path, add to `total`.
4. For the child starting at (0,n-1), use `solve3(0, n-1, fruits, dp)` to
compute the max fruits for their path, add to `total`.
5. Return `total` as the answer.

**Step 6: Complexity**
- Each DP function is O(n^2) due to memoization and grid size.
- The overall complexity is O(n^2).

**Summary**
- The solution collects the main diagonal fruits first, then uses DP for the
other two children, ensuring no double-counting.
- The approach is efficient and handles all movement and overlap constraints.
*/

class Solution {
  public:
    int solve2(int row, int col, vector<vector<int>> &fruits,
               vector<vector<int>> &dp) {
        if (row < 0 || col < 0 || row >= fruits.size() ||
            col >= fruits.size()) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int value = fruits[row][col];
        int result = 0;

        if (row == col) {
            result = max(result, solve2(row + 1, col + 1, fruits, dp));
        } else if (row - 1 == col) {
            result = max({result, solve2(row + 1, col + 1, fruits, dp),
                          solve2(row, col + 1, fruits, dp)});
        } else {
            result = max({result, solve2(row + 1, col + 1, fruits, dp),
                          solve2(row, col + 1, fruits, dp),
                          solve2(row - 1, col + 1, fruits, dp)});
        }

        return dp[row][col] = value + result;
    }

    int solve3(int row, int col, vector<vector<int>> &fruits,
               vector<vector<int>> &dp) {
        if (row < 0 || col < 0 || row >= fruits.size() ||
            col >= fruits.size()) {
            return 0;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        int value = fruits[row][col];
        int result = 0;

        if (row == col) {
            result = max(result, solve3(row + 1, col + 1, fruits, dp));
        } else if (row == col - 1) {
            result = max({result, solve3(row + 1, col + 1, fruits, dp),
                          solve3(row + 1, col, fruits, dp)});
        } else {
            result = max({result, solve3(row + 1, col + 1, fruits, dp),
                          solve3(row + 1, col, fruits, dp),
                          solve3(row + 1, col - 1, fruits, dp)});
        }

        return dp[row][col] = value + result;
    }

    int maxCollectedFruits(vector<vector<int>> &fruits) {

        int total = 0;

        vector<vector<int>> dp(fruits.size(), vector<int>(fruits.size(), -1));

        for (int i = 0; i < fruits.size(); i++) {
            total += fruits[i][i];
            fruits[i][i] = 0;
        }

        total += solve2(fruits.size() - 1, 0, fruits, dp);

        total += solve3(0, fruits.size() - 1, fruits, dp);

        return total;
    }
};