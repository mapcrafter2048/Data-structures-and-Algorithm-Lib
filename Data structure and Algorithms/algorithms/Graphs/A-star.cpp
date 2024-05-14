#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Structure to represent a node in the graph
struct Node
{
    int id;
    int heuristic;
    int cost;
    vector<pair<int, int>> neighbors;
};

// Function to perform A* search
vector<int> AStarSearch(vector<Node> &graph, int start, int goal)
{
    // Priority queue to store nodes based on their total cost
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Map to store the parent of each node
    unordered_map<int, int> parent;

    // Map to store the cost to reach each node
    unordered_map<int, int> cost;

    // Initialize the cost of start node to 0
    cost[start] = 0;

    // Initialize the total cost of start node to its heuristic value
    int totalCost = graph[start].heuristic;
    pq.push({totalCost, start});

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        // If the goal node is reached, reconstruct the path and return it
        if (current == goal)
        {
            vector<int> path;
            while (current != start)
            {
                path.push_back(current);
                current = parent[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        // Iterate through the neighbors of the current node
        for (auto neighbor : graph[current].neighbors)
        {
            int neighborId = neighbor.first;
            int neighborCost = neighbor.second;

            // Calculate the cost to reach the neighbor node
            int newCost = cost[current] + neighborCost;

            // If the neighbor node has not been visited or the new cost is lower, update the cost and parent
            if (!cost.count(neighborId) || newCost < cost[neighborId])
            {
                cost[neighborId] = newCost;
                totalCost = newCost + graph[neighborId].heuristic;
                pq.push({totalCost, neighborId});
                parent[neighborId] = current;
            }
        }
    }

    // If the goal node cannot be reached, return an empty path
    return {};
}

int main()
{
    // Create the graph
    vector<Node> graph(5);

    // Set the heuristic values for each node
    graph[0].heuristic = 10;
    graph[1].heuristic = 5;
    graph[2].heuristic = 7;
    graph[3].heuristic = 3;
    graph[4].heuristic = 0;

    // Add the neighbors for each node
    graph[0].neighbors = {{1, 2}, {2, 3}};
    graph[1].neighbors = {{3, 4}};
    graph[2].neighbors = {{1, 1}, {3, 2}};
    graph[3].neighbors = {{4, 5}};

    // Perform A* search from node 0 to node 4
    vector<int> path = AStarSearch(graph, 0, 4);

    // Print the path
    cout << "Path: ";
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}