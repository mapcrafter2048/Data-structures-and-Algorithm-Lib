#include <iostream>
#include <vector>

using namespace std;

// Function to insert a vertex into the adjacency list
void insert(vector<vector<int>>& adj, int vertex, int u) {
    adj[vertex].push_back(u);
}

// Function to create the transposed graph (G^T)
vector<vector<int>> transposeGraph(vector<vector<int>>& adj) {
    int V = adj.size(); // Number of vertices

    // Initialize the transposed adjacency list with empty vectors
    vector<vector<int>> adjT(V);

    // Traverse the original adjacency list
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            // For each vertex v in the adjacency list of u, insert u into v's adjacency list in G^T
            insert(adjT, v, u);
        }
    }

    return adjT;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V);

    // Example: Creating an adjacency list for the original graph G
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);

    // Get the transposed graph G^T
    vector<vector<int>> adjT = transposeGraph(adj);

    // Print the transposed adjacency list
    for (int u = 0; u < V; u++) {
        cout << "Adjacency list for vertex " << u << " in G^T: ";
        for (int v : adjT[u]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
