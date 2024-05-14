#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int minCut(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> vertices(n);
    vector<int> weights(n);
    vector<bool> inSet(n, false);

    int minCut = INF;

    for (int phase = n - 1; phase >= 0; --phase)
    {
        fill(inSet.begin(), inSet.end(), false);
        fill(weights.begin(), weights.end(), 0);

        int prev = 0;
        for (int i = 0; i < phase; ++i)
        {
            int maxWeight = -1;
            int v = -1;
            for (int j = 0; j < n; ++j)
            {
                if (!inSet[j] && weights[j] > maxWeight)
                {
                    maxWeight = weights[j];
                    v = j;
                }
            }

            if (i == phase - 1)
            {
                for (int j = 0; j < n; ++j)
                {
                    graph[prev][j] += graph[v][j];
                    graph[j][prev] += graph[j][v];
                }

                minCut = min(minCut, maxWeight);

                for (int j = 0; j < n; ++j)
                {
                    graph[v][j] = graph[n - 1][j];
                    graph[j][v] = graph[j][n - 1];
                }
            }
            else
            {
                inSet[v] = true;
                for (int j = 0; j < n; ++j)
                {
                    weights[j] += graph[v][j];
                }
                prev = v;
            }
        }
    }

    return minCut;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int minCutValue = minCut(graph);

    cout << "Minimum cut value: " << minCutValue << endl;

    return 0;
}