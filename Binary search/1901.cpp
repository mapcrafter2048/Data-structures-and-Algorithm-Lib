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
A peak element in a 2D grid is an element that is strictly greater than all of
its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find
any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with
the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

/*
Solution Logic:

The problem is to find a peak element in a 2D grid where a peak element is
defined as an element that is strictly greater than its adjacent neighbors (top,
bottom, left, and right). The solution must run in O(m log(n)) or O(n log(m))
time, where m is the number of rows and n is the number of columns.

Steps of Implementation:

1. **Binary Search on Columns**:
    - Perform a binary search on the columns of the matrix. This ensures that
the time complexity is logarithmic with respect to the number of columns.

2. **Find the Maximum Element in the Current Column**:
    - For the middle column (mid), find the row index (maxi) of the maximum
element in that column. This is done by iterating through all rows in the
column.

3. **Compare the Maximum Element with Its Left and Right Neighbors**:
    - Check if the maximum element in the current column is greater than its
left and right neighbors:
      - If it is, then it is a peak element, and we return its position.
      - If the right neighbor is greater, move the binary search to the right
half of the columns.
      - If the left neighbor is greater, move the binary search to the left half
of the columns.

4. **Edge Cases**:
    - If the middle column is the first or last column, treat the out-of-bound
neighbors as having a value of -1 (as per the problem statement).

5. **Return the Result**:
    - If a peak is found, return its position as a vector `[i, j]`. If no peak
is found (though the problem guarantees one exists), return `{-1, -1}`.

The algorithm ensures that we only perform a logarithmic number of column
searches (O(log(n))) and for each column, we iterate through all rows (O(m)).
Thus, the overall time complexity is O(m log(n)).
*/

class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int maxi = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxi][mid]) {
                    maxi = i;
                }
            }

            int curr = mat[maxi][mid];
            int left = 0;
            int right = 0;

            if (mid > 0) {
                left = mat[maxi][mid - 1];
            } else {
                left = -1;
            }

            if (mid < n - 1) {
                right = mat[maxi][mid + 1];
            } else {
                right = -1;
            }

            if (curr > left && curr > right) {
                return {maxi, mid};
            } else if (right > curr) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};