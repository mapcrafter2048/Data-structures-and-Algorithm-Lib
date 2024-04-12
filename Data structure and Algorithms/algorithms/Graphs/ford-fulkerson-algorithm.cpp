#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to find the maximum flow in a graph using Ford-Fulkerson algorithm
int fordFulkerson(vector<vector<int>> &graph, int source, int sink)
{
    int numVertices = graph.size();
    vector<vector<int>> residualGraph(numVertices, vector<int>(numVertices, 0));
    vector<int> parent(numVertices, -1);
    int maxFlow = 0;

    // Create a residual graph
    for (int u = 0; u < numVertices; u++)
    {
        for (int v = 0; v < numVertices; v++)
        {
            residualGraph[u][v] = graph[u][v];
        }
    }

    // Augment the path while there is a path from source to sink
    while (true)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        parent[source] = -1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v = 0; v < numVertices; v++)
            {
                if (!visited[v] && residualGraph[u][v] > 0)
                {
                    q.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }

        // If there is no path from source to sink, break the loop
        if (!visited[sink])
        {
            break;
        }

        // Find the minimum residual capacity along the path
        int pathFlow = numeric_limits<int>::max();
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Update the residual capacities and reverse edges along the path
        for (int v = sink; v != source; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        // Add the path flow to the overall maximum flow
        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    // Example usage
    int numVertices = 6;
    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    // Initialize the graph with capacities
    graph[0][1] = 16;
    graph[0][2] = 13;
    graph[1][2] = 10;
    graph[1][3] = 12;
    graph[2][1] = 4;
    graph[2][4] = 14;
    graph[3][2] = 9;
    graph[3][5] = 20;
    graph[4][3] = 7;
    graph[4][5] = 4;

    int source = 0;
    int sink = 5;

    int maxFlow = fordFulkerson(graph, source, sink);
    cout << "Maximum flow: " << maxFlow << endl;

    return 0;
}