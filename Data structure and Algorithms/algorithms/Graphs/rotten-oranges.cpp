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

using namespace std;

/// @brief The basic intution of the algorithm is to first mark all the '2's as visted as they are the fresh oranges and then we push all the fresh oranges into a queue and then we do a BFS on the matrix and keep on updating the time required to rot the oranges and then return the time
/// @param grid
/// @return Time required to rot all the oranges
int rottenOranges(vector<vector<int>> grid)
{
    if (grid.empty())
    {
        return 0;
    }

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited;

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                visited[i][j] = 2;
                q.push({{i, j}, 0});
            }
            else
            {
                visited[i][j] = 0;
            }
        }
    }

    int time = 0;
    int changeRow[] = {-1, 0, 1, 0};
    int changeCol[] = {0, -1, 0, 1};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row + changeRow[i];
            int newCol = col + changeCol[i];
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && visited[newRow][newCol] != 2 && grid[newRow][newCol] == 1)
            {
                q.push({{newRow, newCol}, t + 1});
                visited[newRow][newCol] = 2;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] != 2 && grid[i][j] == 1)
            {
                return -1;
            }
        }
    }

    return time;
}

int main()
{

    return 0;
}