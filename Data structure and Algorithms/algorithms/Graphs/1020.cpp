/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
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

using namespace std;
using namespace std::chrono;

/// @brief The basic intution of the algortihm is to first mark all the boundary '1's as visited and then subsequently mark all the '1's that are connected to the boundary '1's as visited. We can achieve this by calling a BFS on the boundary '1's and then marking all the '1's that are connected to the boundary '1's as visited. We then simply iterate over the matrix and count all the '1's that are not visited
/// @param grid
/// @return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves
int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    vector<int> changeRow = {-1, 0, 1, 0};
    vector<int> changeCol = {0, -1, 0, 1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
            {
                visited[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open())
    {
        cerr << "Error opening files." << endl;
        return 1; // Indicate failure
    }

    int n, m;
    inputFile >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Read matrix from input file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            inputFile >> matrix[i][j];
        }
    }

    // Start the timer
    auto start = high_resolution_clock::now();

    // Process the matrix
    int answer = numberOfEnclaves(matrix);

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the execution time
    auto duration = duration_cast<microseconds>(stop - start);

    outputFile << answer << endl;

    inputFile.close();
    outputFile.close();

    // Print the execution time
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}