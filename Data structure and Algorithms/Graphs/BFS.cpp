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

class graph
{   
public:
    int v;
    vector<vector<int>> adj;
    graph(int vertices)
    {
        v = vertices;
        adj.resize(v);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void bfs(int startnode)
    {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(startnode);
        visited[startnode] = true;

        while (!q.empty())
        {
            int currentnode = q.front();
            cout << currentnode << " ";
            q.pop();

            for (int neighbor : adj[currentnode])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

void BFS(vector<int> adj[], int v, int s, vector<bool> visited){
    vector<bool> visited(v);
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }
    queue<int> q;   
    visited[s] = true;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v: adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BFS1(vector<int> adj[], int v, int s, vector<bool>& visited) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

void BFS2(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            BFS1(adj, v, i, visited);
        }
    }
}

int main()
{
    int v = 9;

    graph g(v);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 5);
    g.add_edge(2, 6);
    g.add_edge(4, 7);
    g.add_edge(6, 8);

    g.bfs(0);

    return 0;
}
