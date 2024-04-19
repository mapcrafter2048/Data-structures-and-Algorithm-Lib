/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

/*
This question is slightly different from all the previous questions, here we are given two starting points from where robot1 and robot2 can move.

We are given an ‘N*M’ matrix. We need to define the function with four parameters  row, col1, col2, and grid to describe the positions of robot1 and robot2 at a time.


If we observe, initially robot1 and robot1 are at the first row, and they always move to the row below them every time, so they will always be in the same row. Therefore two different variables row and i, to describe their positions are redundant. We can just use single parameter row, which tells us in which row of the grid both of them are.

Therefore, we can modify the function. It now takes three parameters: row, col1, and col2. solve(row, col1, col2, grid, dp) will give us the maximum number of cherries collected by robot1 and robot2 from their current positions to the last position.

Base Case:

There will be the following base cases:

When row == n-1, it means we are at the last row, so we need to return from here. Now it can happen that at the last row, both robot1 and robot2 are at the same cell, in this condition we will return only cherries collected by robot1, grid[row][col1]( as question states that the cherries cannot be doubly calculated), otherwise we return sum of cherries collected by both, grid[row][col1] + grid[row][col2].
At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙)

As we are moving to the bottom cell (↓), at max we will reach the last row, from where we return, so we will never go out of the bounding index.

To move to the bottom-right cell(↘) or to the bottom-left cell(↙), it can happen that we may go out of bound as shown in the figure(below). So we need to handle it, we can return INT_MIN, whenever we go out of bound, in this way this path will not be selected by the calling function as we have to return the maximum cherries.

If col1 < 0 or col1 >= m or col2 < 0 or col2 >= m, then we return INT_MIN

Step 2: Try out all possible choices at a given index.

At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙)

Now, we need to understand that we want to move robot1 and robot2 together. Both of them can individually move three moves but say robot1 moves to bottom-left, then robot2 can have three different moves for robot1’s move, and so on.

Hence we have a total of 9 different options at every solve(row, col1, col2) to move robot1 and robot2. Now we can manually write these 9 options or we can observe a pattern in them, first robot1 moves to one side and robot2 tries all three choices, then again robot1 moves, then robot2, and so on. This pattern can be easily captured by using two nested loops that change the column numbers(col1 and col2).

Note: if (col1 == col2), as discussed in the base case, we will only consider cherries collected by one of them otherwise we will consider cherries collected by both of them.

Step 3:  Take the maximum of all choices

As we have to find the maximum cherries collected of all the possible paths, we will return the maximum of all the choices(the 9 choices of step 2). We will take a variable answer( initialized to INT_MIN). We will update answer to the maximum of the previous answer and the cherries collected in the current choice. At last, we will return answer from our function as the answer.

Steps to memoize a recursive solution:

Before moving to the memoization steps, we need to understand the dp array we are taking. The recursive function has three parameters: row, col1, and col2. Therefore, we will also need to take a 3D DP Array. Its dimensions will be [n][m][m] because when we are moving, row can go from 0 to n-1, and col1 and col2 can go from 0 to m-1.

If we draw the recursion tree, we will see that there are overlapping subproblems. In order to convert a recursive solution the following steps will be taken:

Create a dp array of size [n][m][m], initialized to -1.
Whenever we want to find the answer of a particular row and columns (say solve(row, col1, col2)), we first check whether the answer is already calculated using the dp array(i.e dp[row][col1][col2]!= -1 ). If yes, simply return the value from the dp array.
If not, then we are finding the answer for the given values for the first time, we will use the recursive relation as usual but before returning from the function, we will set dp[row][col1][col2] to the solution we get.
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

int solve(int row, int col1, int col2, vector<vector<int>> &grid,
          vector<vector<vector<int>>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();
    if (col1 < 0 || col2 < 0 || col1 >= m || col2 >= m)
    {
        return INT_MIN;
    }

    if (row == n - 1)
    {
        if (col1 == col2)
        {
            return grid[row][col1];
        }
        else
        {
            return grid[row][col1] + grid[row][col2];
        }
    }

    if (dp[row][col1][col2] != -1)
    {
        return dp[row][col1][col2];
    }

    int answer = INT_MIN;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int value = 0;
            if (col1 == col2)
            {
                value = grid[row][col1] +
                        solve(row + 1, col1 + i, col2 + j, grid, dp);
            }
            else
            {
                value = grid[row][col1] + grid[row][col2] +
                        solve(row + 1, col1 + i, col2 + j, grid, dp);
            }

            answer = max(answer, value);
        }
    }

    return dp[row][col1][col2] = answer;
}

int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m - 1, grid, dp);
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