#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

bool DetectCycle(const vector<vector<int>> &graph) {
    // 2: visitedEdges ← empty hashmap {Initialize empty hashmap to track
    // visited edges}
    unordered_map<int, vector<int>> visitedEdges;

    // 3: queue ← empty queue
    queue<int> q;

    // 4: for each vertex v in G do
    for (int v = 0; v < graph.size(); ++v) {
        // 5: if v is not visited then
        if (visitedEdges.find(v) == visitedEdges.end()) {
            // 6: enqueue v into queue
            q.push(v);
            // 7: mark v as visited
            visitedEdges[v] = vector<int>();

            // 8: while queue is not empty do
            while (!q.empty()) {
                // 9: u ← dequeue from queue
                int u = q.front();
                q.pop();

                // 10: for each neighbor w of u do
                for (int w : graph[u]) {
                    // 11: if (u, w) is not in visitedEdges then
                    if (find(visitedEdges[u].begin(), visitedEdges[u].end(),
                             w) != visitedEdges[u].end()) {
                        // 12: add (u, w) to visitedEdges
                        visitedEdges[u].push_back(w);
                        // 13: enqueue w into queue
                        q.push(w);
                    } else {
                        // Edge (u, w) has already been visited, indicating a
                        // cycle
                        return false; // Cycle detected
                    }
                }
            }
        }
    }

    // 19: for each edge (u, v) in E(G) do
    for (int u = 0; u < graph.size(); ++u) {
        for (int v : graph[u]) {
            // 20: if (u, w) is not in visitedEdges then
            if (find(visitedEdges[u].begin(), visitedEdges[u].end(), v) ==
                visitedEdges[u].end()) {
                // 21: return false {Cycle detected}
                return false;
            }
        }
    }

    // 24: return true {No cycle detected}
    return true;
}
