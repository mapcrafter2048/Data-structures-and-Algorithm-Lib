#include <iostream>
#include <vector>

using namespace std;

const int N = 1000; // Maximum number of vertices
bool visited[N];
int previsit[N];
int postvisit[N];
int Time = 0; // Global Time counter for numbering

bool hasCycle = false; // Flag to indicate cycle detection

void dfs(const vector<vector<int>> &graph, int u)
{
    visited[u] = true;
    previsit[u] = Time++; // Assign previsit number

    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs(graph, v);
        }
        else if (previsit[v] < previsit[u])
        { // Cycle detected
            hasCycle = true;
            return;
        }
    }

    postvisit[u] = Time++; // Assign postvisit number
}

bool detectCycle(const vector<vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); ++i)
    {
        if (!visited[i])
        {
            dfs(graph, i);
        }
    }

    return hasCycle;
}

int main()
{
    // Example graph (replace with your actual graph data)
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {3, 1}};

    cout << "Graph: " << endl;

    if (detectCycle(graph))
    {
        cout << "Cycle detected!" << endl;
    }
    else
    {
        cout << "No cycle found." << endl;
    }

    return 0;
}
