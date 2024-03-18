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
using namespace chrono;

bool dfsCheck(int currentNode, vector<vector<int>> adjacenyList, vector<int> visited, vector<int> pathVisited)
{
    visited[currentNode] = 1;
    pathVisited[currentNode] = 1;

    for (auto iterator : adjacenyList[currentNode])
    {
        // when the node is already visited and is in the current path
        if (!visited[iterator])
        {
            if (dfsCheck(iterator, adjacenyList, visited, pathVisited) == true)
            {
                return true;
            }
        }
        // if the node has been previously visited and is in the current path
        else if (pathVisited[iterator])
        {
            return true;
        }
    }

    pathVisited[currentNode] = 0;
    return false;
}

bool hasCycle(vector<vector<int>> adjacenyList, int numNodes)
{
    vector<int> visited(numNodes, 0);
    vector<int> pathVisited(numNodes, 0);

    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i])
        {
            if (dfsCheck(i, adjacenyList, visited, pathVisited) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream infile("input.txt");
    if (!infile.is_open())
    {
        cerr << "Error opening input.txt\n";
        return 1;
    }

    int numNodes;
    infile >> numNodes;

    vector<vector<int>> adjacenyList(numNodes);

    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        int node, neighbor;
        iss >> node; // Extract the starting node
        while (iss >> neighbor)
        {
            adjacenyList[node - 1].push_back(neighbor - 1); // Adjust for 0-based indexing
        }
    }

    infile.close();

    bool cycle_exists = hasCycle(adjacenyList, numNodes);

    ofstream outfile("output.txt");
    if (!outfile.is_open())
    {
        cerr << "Error opening output.txt\n";
        return 1;
    }

    outfile << (cycle_exists ? "Cycle exists" : "No cycle detected") << endl;
    outfile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}