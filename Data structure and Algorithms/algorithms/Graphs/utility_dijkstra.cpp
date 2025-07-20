#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

// Structure to represent a node in the graph
struct Node
{
    int vertex;
    int weight;
};

/// @brief This it the Dijkstra Algorithm to find the shortest path from a source node to all other nodes in the graph. This algorithm works for both directed and undirected graphs. The time complexity of this algorithm is O(E log V), where E is the number of edges and V is the number of vertices in the graph. This algorithm is based on the greedy approach and works for graphs with non-negative edge weights. The idea is to use a priority queue to store the nodes with minimum distance from the source node. The distances of the nodes are updated as we traverse the graph. The algorithm works as follows:
/// 1. Initialize the distances of all nodes to infinity and the distance of the source node to 0.
/// 2. Create a priority queue to store the nodes with minimum distance. Push the source node with distance 0 to the priority queue.
/// 3. While the priority queue is not empty, do the following:
///     a. Pop the node with minimum distance from the priority queue.
///     b. If the node is already visited, skip it.
///     c. Mark the node as visited.
///     d. Update the distances of the adjacent nodes.
/// 4. Print the shortest distances from the source node.
/// @param graph
/// @param source
vector<int> dijkstra(vector<vector<Node>> &graph, int source)
{
    int numNodes = graph.size();
    vector<int> distances(numNodes, INT_MAX); // Initialize distances to infinity
    vector<bool> visited(numNodes, false);    // Initialize visited array

    // Priority queue to store nodes with minimum distance
    // Declare a priority queue named 'pq'. The elements in the queue are pairs of integers.
    // The underlying container used to store the elements is a vector.
    // The 'greater' comparison function is used to order the elements,
    // meaning that the elements will be ordered in ascending order based on their priority.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance of source node is 0
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // If the node is already visited, skip it
        if (visited[currentNode])
            continue;

        visited[currentNode] = true;

        // Update the distances of adjacent nodes
        for (auto neighbor : graph[currentNode])
        {
            int neighborNode = neighbor.vertex;
            int weight = neighbor.weight;

            if (!visited[neighborNode] && currentDistance + weight < distances[neighborNode])
            {
                distances[neighborNode] = currentDistance + weight;
                pq.push({distances[neighborNode], neighborNode});
            }
        }
    }

    return distances;
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

    vector<vector<Node>> graph(numNodes);

    string line;
    while (getline(infile, line))
    {
        istringstream iss(line);
        int node, neighbor, weight = 1;
        iss >> node;
        while (iss >> neighbor)
        {
            graph[node - 1].push_back({neighbor - 1, weight});
            // If undirected, add:  graph[neighbor - 1].push_back({node - 1, weight});
        }
    }

    infile.close();

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    vector<int> distances = dijkstra(graph, source);

    ofstream outfile("output.txt");

    if (!outfile.is_open())
    {
        cerr << "Error opening output.txt\n";
        return 1;
    }

    outfile << "Shortest distances from node " << source << " to all other nodes:\n";
    for (int i = 0; i < numNodes; i++)
    {
        outfile << "Node " << i + 1 << ": " << distances[i] << "\n";
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
