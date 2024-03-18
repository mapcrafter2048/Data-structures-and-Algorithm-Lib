#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &graph, vector<int> &inDegree)
{
    int n = graph.size();
    vector<int> result;
    queue<int> q;

    // Enqueue all nodes with in-degree 0
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        // Reduce in-degree of adjacent nodes
        for (int neighbor : graph[node])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    // Check if there is a cycle in the graph
    if (result.size() != n)
    {
        cout << "Cycle detected! Topological sorting not possible." << endl;
        return {};
    }

    return result;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    cout << "Enter the edges:" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> sortedOrder = topologicalSort(graph, inDegree);

    cout << "Topological sorting order: ";
    for (int node : sortedOrder)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
