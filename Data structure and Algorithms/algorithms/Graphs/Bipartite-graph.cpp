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

/// @brief This function checks if the graph is bipartite or not using BFS> The basics idea is to assign colors to each vertex such that no two adjacent vertices have the same color.
/// @param start start vertex
/// @param adj adjacency list
/// @param color color array
/// @return if the graph is bipartite or not
bool check(int start, vector<vector<int>> adj, vector<int> color)
{
    int V = adj.size();
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

/// @brief This function checks if the graph is bipartite or not over all the nodes in the graph
/// @param adj
/// @return if the graph is bipartite or not
bool isBipartite(vector<vector<int>> adj)
{
    int V = adj.size();
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!check(i, adj, color))
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