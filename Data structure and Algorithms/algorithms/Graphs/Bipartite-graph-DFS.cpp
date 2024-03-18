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

/// @brief This is the modifed Depth first search function which will check if the graph is bipartite or not. The basic idea is to color the nodes with two colors and if the graph is bipartite then we will not have any conflict in the coloring of the nodes. If we have any conflict then we will return false.
/// @param node current node
/// @param color color of the node
/// @param nodeColors vector to store the color of the nodes
/// @param adjacencyList The adjacency list of the graph
/// @return If the component is bipartite or not
bool depthFirstSeach(int node, int color, vector<int> &nodeColors, vector<vector<int>> &adjacencyList)
{
    nodeColors[node] = color;

    for (auto neighbor : adjacencyList[node])
    {
        // if the node is -1 it means that it has not been visited so we are calling the Dfs recursion and it any of the node is not bipartite then we will return false and if the node is already visited then we will check if the color of the node is same as the color of the parent node then we will return false
        if (nodeColors[neighbor] == -1)
        {
            if (!depthFirstSeach(neighbor, 1 - color, nodeColors, adjacencyList))
            {
                return false;
            }
        }
        else if (nodeColors[neighbor] == nodeColors[node])
        {
            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &adjacencyList)
{
    vector<int> nodeColors(adjacencyList.size(), -1);
    for (int i = 0; i < adjacencyList.size(); i++)
    {
        if (nodeColors[i] == -1)
        {
            if (!depthFirstSeach(i, 0, nodeColors, adjacencyList))
            {
                return false;
            }
        }
    }

    return true;
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