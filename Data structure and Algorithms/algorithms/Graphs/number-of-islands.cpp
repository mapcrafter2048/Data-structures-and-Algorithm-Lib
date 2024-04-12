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

void bfs(int row, int col, vector<vector<char>> &grid,
         vector<vector<bool>> &visited)
{
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = true;
    queue<pair<int, int>> q;
    q.push({row, col});

    vector<int> delrow = {1, 0, -1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                grid[newrow][newcol] == '1' && !visited[newrow][newcol])
            {
                visited[newrow][newcol] = true;
                q.push({newrow, newcol});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int count = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!visited[row][col] && grid[row][col] == '1')
            {
                count++;
                bfs(row, col, grid, visited);
            }
        }
    }

    return count;
}

int main()
{
    auto start = high_resolution_clock::now();

    // Your code here
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    cout << numIslands(grid) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}