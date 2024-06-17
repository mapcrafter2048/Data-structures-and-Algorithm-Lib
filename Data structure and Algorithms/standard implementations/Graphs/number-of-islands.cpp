#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == '0')
    {
        return;
    }

    visited[row][col] = 1;

    dfs(grid, visited, row + 1, col);
    dfs(grid, visited, row - 1, col);
    dfs(grid, visited, row, col + 1);
    dfs(grid, visited, row, col - 1);
    dfs(grid, visited, row - 1, col - 1);
    dfs(grid, visited, row + 1, col - 1);
    dfs(grid, visited, row - 1, col + 1);
    dfs(grid, visited, row + 1, col + 1);
}

int numberOfIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;

    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (!visited[row][col] && grid[row][col] == '1')
            {
                count++;
                dfs(grid, visited, row, col);
            }
        }
    }

    return count;
}

int main()
{
    // Your code here
    vector<vector<char>> grid{
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}};

    cout << numberOfIslands(grid) << endl;
    return 0;
}
