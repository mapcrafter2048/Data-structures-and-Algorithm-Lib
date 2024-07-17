/*
Given an m x n binary matrix mat, return the distance of the nearest 1 for each
cell. The distance between two adjacent cells is 1.
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
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

/// @brief The basic intution of the algorithm is to first mark all the '1's as
/// visited and all the other cells that is the cells with '0's as unvisited. We
/// then push all the visited cells into a queue along side their steps that is
/// the steps required to reach nearest 1 and since they already are 1 so hence
/// the step is 0 we then do a BFS on the matrix and keep on updating the
/// distance of the cells from the nearest 1 and then return the distance matrix
/// @param mat the matrix
/// @return matrix with the distance of the nearest 1 for each cell
vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    long long int n = mat.size();
    long long int m = mat[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> distance(n, vector<int>(m, 0));
    queue<pair<pair<long long int, long long int>, long long int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
            } else {
                visited[i][j] = 0;
            }
        }
    }

    vector<int> changeRow = {-1, 0, 1, 0};
    vector<int> changeCol = {0, -1, 0, 1};

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;

        q.pop();

        distance[row][col] = steps;

        // explore the 4 directions

        for (int i = 0; i < 4; i++) {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                visited[newRow][newCol] == 0) {
                visited[newRow][newCol] = 1;
                q.push({{newRow, newCol}, steps + 1});
            }
        }
    }

    return distance;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files." << endl;
        return 1; // Indicate failure
    }

    int n, m;
    inputFile >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Read matrix from input file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> matrix[i][j];
        }
    }

    // Start the timer
    auto start = high_resolution_clock::now();

    // Process the matrix
    vector<vector<int>> processed_matrix = updateMatrix(matrix);

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the execution time
    auto duration = duration_cast<microseconds>(stop - start);

    // Write the output matrix to the file
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            outputFile << processed_matrix[i][j] << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    // Print the execution time
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0; // Indicate success
}
