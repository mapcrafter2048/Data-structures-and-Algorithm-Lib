#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>

using namespace std;

void DFSres(vector<int> adj[], int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            DFSres(adj, neighbour, visited);
        }
    }
}

void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    DFSres(adj, 0, visited);
}

int main()
{

    vector<int> adj[5];

    adj[0].push_back(1); // A -> B
    adj[0].push_back(2); // A -> C
    adj[1].push_back(3); // B -> D
    adj[2].push_back(4); // C -> E
    adj[1].push_back(4); // B -> E
    adj[2].push_back(3); // C -> D

    cout << "Depth-First Traversal: ";
    DFS(adj, 5);
    return 0;
}