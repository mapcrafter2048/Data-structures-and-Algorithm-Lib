#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

void dfs(int currentNode, vector<vector<int>> &adjacenyList, vector<int> visited, stack<int> stk)
{
    visited[currentNode] = 1;
    for (auto neighbour : adjacenyList[currentNode])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, adjacenyList, visited, stk);
        }
    }

    stk.push(currentNode);
}

vector<int> topologicalSort(int numberNodes, vector<vector<int>> &adjacenyList)
{
    vector<int> visited(numberNodes, 0);
    stack<int> stk;

    for (int i = 0; i < numberNodes; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjacenyList, visited, stk);
        }
    }

    vector<int> result;
    while (!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

int main()
{
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}