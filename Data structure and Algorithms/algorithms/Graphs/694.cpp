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

/// @brief This the Breath First approach to find the number of islands in the grid. the basic idea is to start from the first cell and then visit all the cells that are connected to it and then move to the next cell and do the same thing until all the cells are visited.
/// @param row X-coordinate of the cell
/// @param col Y-coordinate of the cell
/// @param visited a 2D vector to keep track of the visited cells
/// @param grid the grid of 1s and 0s
void breadthFirstSearch(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid)
{

    visited[row][col] = 1;
    queue<pair<int, int>> q;

    q.push({row, col});

    int n = grid.size();
    int m = grid[0].size();

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int changeRow = -1; changeRow <= 1; changeRow++)
        {
            for (int changeCol = -1; changeCol <= 1; changeCol++)
            {
                int newRow = row + changeRow;
                int newCol = col + changeCol;

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1 && !visited[newRow][newCol])
                {
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}

/// @brief This is modified Depth first search to find the identical islands in graph. The basic idea is to start from the first cell and then visit all the cells that are connected to it and then move to the next cell and do the same thing until all the cells are visited. And then we are storing all the coordinates(X, Y) of the cells in a vector and then we are storing the vector in a set to find the unique islands. To find the identical Islands we are taking a Base coordinate and all the other corrdinates of cells connected to it are the Base coordinate - their coordinate this ensures that we can find the same islands
/// @param row X-coordinate of the cell
/// @param col Y-coordinate of the cell
/// @param visited a 2D vector to keep track of the visited cells
/// @param grid the grid of 1s and 0s
/// @param vec a vector to store the coordinates of the cells
/// @param row0 Base X-coordinate of the cell
/// @param col0 Base Y-coordinate of the cell
void depthFirstSearch(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0)
{

    visited[row][col] = 1;
    vec.push_back({row - row0, col - col0});

    int n = grid.size();
    int m = grid[0].size();

    vector<int> changeRow = {-1, 1, 0, 0};
    vector<int> changeCol = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int newRow = row + changeRow[i];
        int newCol = col + changeCol[i];

        if (newRow >= 0 && newRow < n && newRow >= 0 & newCol < m && grid[newRow][newCol] == 1 && !visited[newRow][newCol])
        {
            depthFirstSearch(newRow, newCol, visited, grid, vec, row0, col0);
        }
    }
}

/// @brief This function is used to find the number of islands and the number of distinct islands in the grid
/// @param grid
/// @return a pair of integers where the first integer is the number of islands and the second integer is the number of distinct islands
pair<int, int> numOfIslands(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> islands;
    pair<int, int> answer;
    int count = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!visited[row][col] && grid[row][col])
            {
                vector<pair<int, int>> vec;
                breadthFirstSearch(row, col, grid, visited);
                depthFirstSearch(row, col, visited, grid, vec, row, col);
                islands.insert(vec);
                count++;
            }
        }
    }
    answer.first = count;
    answer.second = islands.size();
    return answer;
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
    pair<int, int> answer = numOfIslands(matrix);

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the execution time
    auto duration = duration_cast<microseconds>(stop - start);

    outputFile << answer.first << " " << answer.second << endl;

    inputFile.close();
    outputFile.close();

    // Print the execution time
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}