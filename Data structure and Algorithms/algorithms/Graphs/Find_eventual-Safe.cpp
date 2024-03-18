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

vector<int> eventualSafeNodes(vector<vector<int>> &adjacenyList)
{
    vector<vector<int>> adjacencyReverse(adjacenyList.size());
    vector<int> inDegree(adjacenyList.size());
    for (int i = 0; i < adjacenyList.size(); i++)
    {
        for (auto it : adjacenyList[i])
        {
            adjacencyReverse[it].push_back(i);
            inDegree[i]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;
    for (int i = 0; i < adjacenyList.size(); i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        safeNodes.push_back(currentNode);
        for (auto neighbour : adjacencyReverse[currentNode])
        {
            inDegree[neighbour]--;
            if (inDegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
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