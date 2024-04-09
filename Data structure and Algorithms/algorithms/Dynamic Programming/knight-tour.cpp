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

bool isSafe(int x, int y, vector<vector<int>> &board)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1)
    {
        return true;
    }
    return false;
}

bool solve(int x, int y, int count, vector<vector<int>> &board)
{
    int xMove[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[] = {1, 2, 2, 1, -1, -2, -2, -1};

    if (count == 64)
    {
        return true;
    }

    for (int i = 0; i < 8; i++)
    {
        int newX = x + xMove[i];
        int newY = y + yMove[i];

        if (isSafe(newX, newY, board))
        {
            board[newX][newY] = count;

            if (solve(newX, newY, count + 1, board))
            {
                return true;
            }
            else
            {
                board[newX][newY] = -1;
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