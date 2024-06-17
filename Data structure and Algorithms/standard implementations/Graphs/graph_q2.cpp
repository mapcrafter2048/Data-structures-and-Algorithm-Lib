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

const int V = 5;

void insert(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    vector<int> adj[V];
    vector<int> adj2[V];
    for (int u = 0; u < V; u++)
    {
        for (int i = 0; i < adj2[u].size(); i++)
        {
            int v = adj[u][i];
            insert(adj2, u, v);

            for (int j = 0; j < adj[v].size(); j++)
            {
                int w = adj[v][j];
                insert(adj2, v, w);
            }
        }
    }
    return 0;
}