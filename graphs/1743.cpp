#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
There is an integer array nums that consists of n unique elements, but you have
forgotten it. However, you do remember every pair of adjacent elements in nums.

You are given a 2D integer array adjacentPairs of size n - 1 where each
adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent
in nums.

It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will
exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]].
The pairs can appear in any order.

Return the original array nums. If there are multiple solutions, return any of
them.
*/

/*
Solution Logic:

The problem is to reconstruct the original array `nums` from the given
`adjacentPairs`. The key observation is that:
1. Each element in `nums` (except the first and last elements) will appear
exactly twice in the `adjacentPairs`.
2. The first and last elements in `nums` will appear only once in the
`adjacentPairs`.

Steps of Implementation:

1. **Build the Adjacency List**:
    - Use an unordered map to represent the adjacency list. Each key in the map
is an element from `adjacentPairs`, and its value is a vector of elements that
are adjacent to it.
    - Iterate through the `adjacentPairs` and populate the adjacency list.

2. **Find the Starting Element**:
    - The starting element of the array `nums` is the one that appears only once
in the adjacency list (i.e., it has only one neighbor). Iterate through the
adjacency list to find this element.

3. **Perform Depth-First Search (DFS)**:
    - Starting from the root (the element found in the previous step), perform a
DFS to reconstruct the array `nums`.
    - Maintain a `prev` variable to avoid revisiting the previous node during
the DFS traversal.

4. **Return the Result**:
    - The DFS traversal will produce the reconstructed array `nums`.

The implementation of the above logic is provided in the `restoreArray`
function. The `dfs` function is a helper function that performs the DFS
traversal and appends elements to the result array `ans`.
*/

class Solution {
  public:
    void dfs(int node, vector<int> &ans, unordered_map<int, vector<int>> &adj,
             int prev) {
        ans.push_back(node);
        for (int neighbor : adj[node]) {
            if (neighbor != prev) {
                dfs(neighbor, ans, adj, node);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>> &adjp) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < adjp.size(); i++) {
            int u = adjp[i][0];
            int v = adjp[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int root = 0;
        for (auto &it : adj) {
            if (it.second.size() == 1) {
                root = it.first;
                break;
            }
        }

        vector<int> ans;
        dfs(root, ans, adj, INT_MAX);

        return ans;
    }
};
