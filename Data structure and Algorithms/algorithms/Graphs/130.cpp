/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
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

using namespace std;
using namespace std::chrono;

/// @brief This is the modifed Depth first search function that is used to mark all the 'O's that are connected to the boundary as visited. The DFS will only run for the cells that are not visited are 'O's and are connected to the boundary 'O's
/// @param row  the row of the current cell
/// @param col the column of the current cell
/// @param visited  the visited matrix
/// @param matrix the matrix
/// @param changeRow  the change in row for the 4 directions
/// @param changeCol  the change in column for the 4 directions
void depthFirstSearch(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &matrix, vector<int> changeRow, vector<int> changeCol)
{
    int n = matrix.size();
    int m = matrix[0].size();

    visited[row][col] = 1;

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + changeRow[i];
        int newCol = col + changeCol[i];

        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && !visited[newRow][newCol] && matrix[newRow][newCol] == 'O')
        {
            depthFirstSearch(newRow, newCol, visited, matrix, changeRow, changeCol);
        }
    }
}

/// @brief The basic intution of the algorithm is to first mark all the 'O's that are connected to the boundary as visited. and then subsequently mark all the 'O's that are connected to the 'O's that are connected to the boundary as visited. we cna achive this by calling depth first seach on the boundary 'O's and then marking all the 'O's that are connected to the boundary 'O's as visited. and then we can simply iterate over the matrix and mark all the 'O's that are not visited as 'X's
/// @param n the number of rows
/// @param m the number of columns
/// @param matrix the matrix
/// @return matrix with all the 'O's that are not connected to the boundary as 'X's
vector<vector<char>> fill(int n, int m, vector<vector<char>> matrix)
{
    vector<int> changeRow = {-1, 0, 1, 0};
    vector<int> changeCol = {0, -1, 0, 1};

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++)
    {
        if (!visited[0][j] && matrix[0][j] == 'O')
        {
            depthFirstSearch(0, j, visited, matrix, changeRow, changeCol);
        }

        if (!visited[n - 1][j] && matrix[n - 1][j] == 'O')
        {
            depthFirstSearch(n - 1, j, visited, matrix, changeRow, changeCol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i][0] && matrix[i][0] == 'O')
        {
            depthFirstSearch(i, 0, visited, matrix, changeRow, changeCol);
        }

        if (!visited[i][m - 1] && matrix[i][m - 1] == 'O')
        {
            depthFirstSearch(i, m - 1, visited, matrix, changeRow, changeCol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && matrix[i][j] == 'O')
            {
                matrix[i][j] = 'X';
            }
        }
    }

    return matrix;
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    // n = 5, m = 4
    vector<vector<char>> ans = fill(5, 4, mat);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}