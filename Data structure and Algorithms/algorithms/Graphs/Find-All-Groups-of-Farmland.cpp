/*
You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].

Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.
*/
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

vector<int> BFS(int row, int col, vector<vector<int>> &land,
                vector<vector<bool>> &visited)
{
    int n = land.size();
    int m = land[0].size();
    vector<int> startPos = {row, col};
    vector<int> endPos = {row, col};

    queue<vector<int>> q;
    q.push({row, col});
    visited[row][col] = true;

    vector<int> delRow = {1, 0, -1, 0};
    vector<int> delCol = {0, -1, 0, 1};

    while (!q.empty())
    {
        int row1 = q.front()[0];
        int col1 = q.front()[1];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row1 + delRow[i];
            int newCol = col1 + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && land[newRow][newCol] == 1)
            {

                q.push({newRow, newCol});
                visited[newRow][newCol] == true;

                startPos[0] = min(startPos[0], newRow);
                startPos[1] = min(startPos[1], newCol);
                endPos[0] = max(endPos[0], newRow);
                endPos[1] = max(endPos[1], newCol);

                visited[newRow][newCol] = true;
            }
        }
    }

    vector<int> answer = {startPos[0], startPos[1], endPos[0], endPos[1]};
    return answer;
}

vector<int> DFS(int row, int col, vector<vector<int>> &land, vector<vector<int>> &visited)
{
    int n = land.size();
    int m = land[0].size();
    vector<int> startPos = {row, col};
    vector<int> endPos = {row, col};

    stack<vector<int>> s;
    s.push({row, col});
    visited[row][col] = true;

    vector<int> delRow = {1, 0, -1, 0};
    vector<int> delCol = {0, -1, 0, 1};

    while (!s.empty())
    {
        int row1 = s.top()[0];
        int col1 = s.top()[1];
        s.pop();

        for (int i = 0; i < 4; i++)
        {
            int newRow = row1 + delRow[i];
            int newCol = col1 + delCol[i];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && land[newRow][newCol] == 1)
            {

                s.push({newRow, newCol});
                visited[newRow][newCol] == true;

                startPos[0] = min(startPos[0], newRow);
                startPos[1] = min(startPos[1], newCol);
                endPos[0] = max(endPos[0], newRow);
                endPos[1] = max(endPos[1], newCol);

                visited[newRow][newCol] = true;
            }
        }
    }

    vector<int> answer = {startPos[0], startPos[1], endPos[0], endPos[1]};
    return answer;
}

vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = land.size();
    int m = land[0].size();
    vector<vector<int>> result;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 1 && !visited[i][j])
            {
                result.push_back(BFS(i, j, land, visited));
            }
        }
    }

    return result;
}

int main()
{
    auto start = high_resolution_clock::now();

    vector<vector<int>> land = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    vector<vector<int>> result = findFarmland(land);
    for (const auto &group : result)
    {
        cout << "[" << group[0] << ", " << group[1] << ", " << group[2] << ", " << group[3] << "]" << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}