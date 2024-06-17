#include <iostream>
#include <vector>

using namespace std;

// Define the number of vertices |V|
const int V = 5;

// Function to insert an element into the adjacency list
void insert(vector<int> Adj[], int u, int v) {
    Adj[u].push_back(v);
}

int main() {
    // Create a new adjacency list Adj'[1..|V|]
    vector<int> Adj[V];

    // Initialize an array A of size |V| with zeros
    int A[V] = {0};

    // Initialize the adjacency list for the original graph G (not shown)

    // Iterate through each vertex u in G.V
    for (int u = 0; u < V; u++) {
        // Iterate through each vertex v in Adj[u]
        for (int i = 0; i < Adj[u].size(); i++) {
            int v = Adj[u][i];
            // Check if v is not equal to u and A[v] is not equal to u
            if (v != u && A[v] != u) {
                // Set A[v] to u
                A[v] = u;
                // Insert v into the new adjacency list Adj'[u]
                insert(Adj, u, v);
            }
        }
    }

    // Display the new adjacency list Adj'
    for (int u = 0; u < V; u++) {
        cout << "Adj'[" << u << "]: ";
        for (int i = 0; i < Adj[u].size(); i++) {
            cout << Adj[u][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
