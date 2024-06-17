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

using namespace std;

struct Edge
{
    int to;
    int weight;
};

class Graph
{
private:
    int V;                    // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void addEdge(int from, int to, int weight)
    {
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    void primMST()
    {
        vector<bool> inMST(V, false);
        vector<int> key(V, 2147483647);
        vector<int> parent(V, -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int startVertex = 0;
        pq.push({0, startVertex});
        key[startVertex] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            inMST[u] = true;

            for (const Edge &edge : adj[u])
            {
                int v = edge.to;
                int weight = edge.weight;
                if (!inMST[v] && weight < key[v])
                {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        for (int i = 1; i < V; i++)
        {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
        }
    }
};

int main()
{
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;
    g.primMST();

    return 0;
}