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

bool dfs(int currentNode, int parent, vector<vector<int>> adjacenyList, vector<int> visited)
{
    visited[currentNode] = 1;

    for (auto neighbour : adjacenyList[currentNode])
    {
        if (!visited[neighbour])
        {
            if (dfs(neighbour, currentNode, adjacenyList, visited))
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            return true;
        }
    }
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