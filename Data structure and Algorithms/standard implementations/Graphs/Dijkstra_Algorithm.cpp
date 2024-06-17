#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node in the graph
struct Node
{
    int vertex;
    int weight;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Node>> &graph, int source)
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

    // Print the shortest distances from the source node
    cout << "Shortest distances from source node " << source << ":\n";
    for (int i = 0; i < numNodes; i++)
    {
        cout << "Node " << i << ": " << distances[i] << "\n";
    }
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Node>> graph(numNodes);

    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}
