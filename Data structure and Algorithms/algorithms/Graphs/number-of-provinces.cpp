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

void depthFirstSeach(int node, vector<vector<int>> &adjacencyList, vector<bool> &visited)
{
    visited[node] = true;

    for (auto neighbor : adjacencyList[node])
    {
        if (!visited[neighbor])
        {
            depthFirstSeach(neighbor, adjacencyList, visited);
        }
    }
}

int numberOfProviences(vector<vector<int>> adjacencymatrix)
{
    int n = adjacencymatrix.size();
    vector<vector<int>> adjacencylist(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjacencymatrix[i][j] == 1)
            {
                adjacencylist[i].push_back(j);
                adjacencylist[j].push_back(i);
            }
        }
    }

    vector<bool> visited(n, false);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            depthFirstSeach(i, adjacencymatrix, visited);
            count++;
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
    int answer = numberOfProviences(matrix);

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