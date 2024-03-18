#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int src, des, wt;
    edge(int s, int d, int w)
    {
        src = s;
        des = d;
        wt = w;
    }

    bool operator<(const edge& other) const
    {
        return wt < other.wt;
    }
};

vector<int> parent, ranks;

int find(int x)
{
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if (ranks[xroot] < ranks[yroot])
        parent[xroot] = yroot;
    else if (ranks[xroot] > ranks[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[yroot] = xroot;
        ranks[xroot]++;
    }
}

void kruskals_mst(vector<edge> &edges, int V)
{
    sort(edges.begin(), edges.end());

    parent.resize(V);
    ranks.assign(V, 0); 

    for (int i = 0; i < V; i++)
    {
        parent[i] = i; 
    }

    int ans = 0;
    cout << "Following are the edges in the constructed MST:" << endl;
    for (const edge &e : edges)
    {
        int w = e.wt;
        int x = e.src;
        int y = e.des;

        if (find(x) != find(y))
        {
            union_set(x, y);
            ans += w;
            cout << x << " -- " << y << " == " << w << endl;
        }
    }
    cout << "Minimum Cost Spanning Tree: " << ans << endl;
}

void addEdge(vector<edge> &edges, int src, int des, int wt)
{
    edges.push_back(edge(src, des, wt));
}

int main()
{
    int V = 5;
    int E = 7;
    vector<edge> edges;

    addEdge(edges, 0, 1, 2);
    addEdge(edges, 0, 3, 6);
    addEdge(edges, 1, 2, 3);
    addEdge(edges, 1, 3, 8);
    addEdge(edges, 1, 4, 5);
    addEdge(edges, 2, 4, 7);
    addEdge(edges, 3, 4, 9);

    kruskals_mst(edges, V);

    return 0;
}
