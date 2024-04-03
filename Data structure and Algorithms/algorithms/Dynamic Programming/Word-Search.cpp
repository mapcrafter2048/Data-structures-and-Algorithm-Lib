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

/// @brief The basic idea of the question to perform DFS, not BFS as we find the individual characters in the word and then we perform DFS on the board to find the word. So we are performing DFS on the board and and if the current character in not equal to the character in the word then we return false. If we find the word then we return true. We call the DFS recursively on the board and if we find the word then we return true else we return false. We also need to keep track of the characters that we have visited so that we do not visit the same character again. We change the character to a special character and then we change it back to the original character so that we can explore the other paths as well. We also need to keep track of the index of the word that we are currently at. If we reach the end of the word then we return true else we return false.
/// @param row Current row
/// @param col Current column
/// @param board The board
/// @param word The word that we need to find
/// @param index The index of the word that we are currently at
/// @return
bool DFS(int row, int col, vector<vector<char>> &board, string word, int index)
{
    if (index == word.size())
    {
        return true;
    }

    int m = board.size();
    int n = board[0].size();

    if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index])
    {
        return false;
    }

    // Storing the character in a temporary varaible
    char temp = board[row][col];
    // changing the character to a special character to avoid visiting it again
    board[row][col] = '@';

    bool found = DFS(row + 1, col, board, word, index + 1) || DFS(row - 1, col, board, word, index + 1) || DFS(row, col + 1, board, word, index + 1) || DFS(row, col - 1, board, word, index + 1);

    // changing the character back to original so that if we explored this path again we can find the path as we will be searching various path and it not necessary that we find the correct answer in the first path itself hence we change the character again so as to preserve the original state of the board
    board[row][col] = temp;
    return found;
}

bool wordExist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (DFS(i, j, board, word, 0))
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