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

bool detect(int source, vector<vector<int>> adjacenyList, vector<int> visited)
{
    visited[source] = 1;
    queue<pair<int, int>> q;
    q.push({source, -1});

    while (!q.empty())
    {
        int currentNode = q.front().first;
        int parentNode = q.front().second;

        for (auto neighbour : adjacenyList[currentNode])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                q.push({neighbour, currentNode});
            }
            else if (neighbour != parentNode)
            {
                return true;
            }
        }
    }

    return false;
}

bool hasCycle(vector<vector<int>> adjacenyList)
{
    vector<int> visited(adjacenyList.size(), 0);
    for (int i = 0; i < adjacenyList.size(); i++)
    {
        if (!visited[i])
        {
            if (detect(i, adjacenyList, visited))
            {
                return true;
            }
        }
    }
    return false;
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