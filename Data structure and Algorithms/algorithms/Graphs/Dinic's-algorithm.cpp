#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge
{
    int v;        // destination vertex
    int flow;     // current flow in the edge
    int capacity; // capacity of the edge
    int rev;      // reverse edge index
};

// Class to represent a graph
class Graph
{
    int V;                    // number of vertices
    vector<vector<Edge>> adj; // adjacency list

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int capacity)
    {
        // Forward edge: capacity is same as given capacity, flow is 0
        Edge forward = {v, 0, capacity, adj[v].size()};
        // Reverse edge: capacity is 0, flow is 0
        Edge reverse = {u, 0, 0, adj[u].size()};

        adj[u].push_back(forward);
        adj[v].push_back(reverse);
    }

    // Function to perform Breadth-First Search (BFS)
    bool bfs(int s, int t, vector<int> &level)
    {
        level.assign(V, -1);
        level[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (const Edge &e : adj[u])
            {
                if (level[e.v] == -1 && e.flow < e.capacity)
                {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }

        return level[t] != -1;
    }

    // Function to perform Depth-First Search (DFS)
    int dfs(int u, int t, int flow, vector<int> &level, vector<int> &ptr)
    {
        if (u == t || flow == 0)
            return flow;

        for (int &i = ptr[u]; i < adj[u].size(); i++)
        {
            Edge &e = adj[u][i];

            if (level[e.v] == level[u] + 1 && e.flow < e.capacity)
            {
                int minFlow = min(flow, e.capacity - e.flow);
                int currFlow = dfs(e.v, t, minFlow, level, ptr);

                if (currFlow > 0)
                {
                    e.flow += currFlow;
                    adj[e.v][e.rev].flow -= currFlow;
                    return currFlow;
                }
            }
        }

        return 0;
    }

    // Function to find the maximum flow in the graph
    int maxFlow(int s, int t)
    {
        if (s == t)
            return -1;

        int maxFlow = 0;
        vector<int> level(V);
        vector<int> ptr(V);

        while (bfs(s, t, level))
        {
            fill(ptr.begin(), ptr.end(), 0);

            while (int flow = dfs(s, t, INT_MAX, level, ptr))
                maxFlow += flow;
        }

        return maxFlow;
    }
};

int main()
{
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1, 16);
    graph.addEdge(0, 2, 13);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 12);
    graph.addEdge(2, 1, 4);
    graph.addEdge(2, 4, 14);
    graph.addEdge(3, 2, 9);
    graph.addEdge(3, 5, 20);
    graph.addEdge(4, 3, 7);
    graph.addEdge(4, 5, 4);

    int source = 0; // source vertex
    int sink = 5;   // sink vertex

    // Find the maximum flow in the graph
    int maxFlow = graph.maxFlow(source, sink);

    cout << "Maximum flow: " << maxFlow << endl;

    return 0;
}