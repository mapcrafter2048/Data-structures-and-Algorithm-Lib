#include <iostream>
#include <vector>

struct Edge
{
    int source, destination, weight;
};

/// @brief @brief Implements the Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices in a weighted directed graph.  The Bellman-Ford algorithm works by iteratively relaxing the edges of the graph. It starts by initializing the distance of the source vertex to 0 and the distance of all other vertices to infinity. Then, it performs |V|-1 iterations, where |V| is the number of vertices in the graph. In each iteration, it relaxes all the edges of the graph by checking if there is a shorter path to the destination vertex through the current edge. If a shorter path is found, the distance of the destination vertex is updated.  After the iterations, the algorithm checks for negative-weight cycles. If there is a negative-weight cycle, it means that there is no shortest path, as the distance can be decreased indefinitely by going through the cycle. If a negative-weight cycle is found, the algorithm terminates and reports that the graph contains a negative-weight cycle.  Finally, the algorithm prints the shortest distances from the source vertex to all other vertices.
/// @param edges
/// @param numVertices
/// @param sourceVertex
void BellmanFord(std::vector<Edge> &edges, int numVertices, int sourceVertex)
{
    std::vector<int> distance(numVertices, INT_MAX);
    distance[sourceVertex] = 0;

    for (int iteration = 0; iteration < numVertices - 1; ++iteration)
    {
        for (const auto &edge : edges)
        {
            int source = edge.source;
            int destination = edge.destination;
            int weight = edge.weight;

            if (distance[source] != INT_MAX && distance[source] + weight < distance[destination])
            {
                distance[destination] = distance[source] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto &edge : edges)
    {
        int source = edge.source;
        int destination = edge.destination;
        int weight = edge.weight;

        if (distance[source] != INT_MAX && distance[source] + weight < distance[destination])
        {
            std::cout << "Graph contains negative-weight cycle\n";
            return;
        }
    }

    // Print the shortest distances
    for (int vertex = 0; vertex < numVertices; ++vertex)
    {
        std::cout << "Distance from source vertex to vertex " << vertex << " is " << distance[vertex] << "\n";
    }
}

int main()
{
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    std::vector<Edge> edges(numEdges);
    std::cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < numEdges; ++i)
    {
        std::cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int sourceVertex;
    std::cout << "Enter the source vertex: ";
    std::cin >> sourceVertex;

    BellmanFord(edges, numVertices, sourceVertex);

    return 0;
}
