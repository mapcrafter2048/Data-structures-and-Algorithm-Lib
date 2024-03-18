#include <iostream>
#include <vector>

#define INF 99999

using namespace std;

void floydWarshall(vector<vector<int>> &graph, int numVertices)
{
    vector<vector<int>> shortestDistances(numVertices, vector<int>(numVertices));

    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            shortestDistances[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < numVertices; k++)
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                if (shortestDistances[i][k] + shortestDistances[k][j] < shortestDistances[i][j])
                {
                    shortestDistances[i][j] = shortestDistances[i][k] + shortestDistances[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            if (shortestDistances[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << shortestDistances[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> adjacencyMatrix(numVertices, vector<int>(numVertices));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cin >> adjacencyMatrix[i][j];
        }
    }

    floydWarshall(adjacencyMatrix, numVertices);

    return 0;
}
