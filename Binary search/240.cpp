#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using namespace std::chrono;

/*
Write an efficient algorithm that searches for a value target in an m x n
integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.
*/

/*
Logic and Steps of Implementation:

1. Problem Understanding:
    - The matrix is sorted in ascending order both row-wise and column-wise.
    - We need to efficiently search for a target value in the matrix.

2. Approach:
    - Instead of searching the entire matrix, we can leverage the sorted
property of rows and columns.
    - For each row, check if the target lies within the range of the first and
last elements of the row.
    - If the target is within the range, perform binary search on that row to
find the target.

3. Steps:
    - Check if the matrix is empty or has no columns; return false if true.
    - Iterate through each row of the matrix:
      - Skip the row if the target is smaller than the first element or larger
than the last element of the row.
      - Perform binary search on the row to find the target.
    - If the target is found during binary search, return true.
    - If no match is found after checking all rows, return false.

4. Complexity:
    - Time Complexity: O(m * log(n)), where m is the number of rows and n is the
number of columns.
      - Binary search on each row takes O(log(n)).
    - Space Complexity: O(1), as no additional space is used.
*/

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;

        for (int i = 0; i < m; ++i) {
            if (target < matrix[i][0] || target > matrix[i][n - 1]) {
                continue;
            }

            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) {
                    return true;
                } else if (matrix[i][mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};
