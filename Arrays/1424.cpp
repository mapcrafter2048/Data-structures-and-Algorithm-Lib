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
Given a 2D integer array nums, return all elements of nums in diagonal order as
shown in the below images.
*/

/*
Solution Logic:

The problem is to traverse a 2D array in diagonal order. Diagonal order means
that we traverse elements that belong to the same diagonal (i.e., elements with
the same sum of row and column indices) together. The diagonals are traversed
from top-left to bottom-right, and within each diagonal, elements are collected
in reverse order of their appearance.

Steps of Implementation:

1. **Group Elements by Diagonal**:
    - Use an `unordered_map` to group elements by their diagonal index. The
diagonal index is calculated as the sum of the row index `i` and column index
`j` (`i + j`).
    - Traverse the 2D array `nums` using nested loops. For each element
`nums[i][j]`, add it to the group corresponding to the diagonal index `i + j`.
    - Keep track of the maximum diagonal index (`maxKey`) encountered during
this traversal.

2. **Collect Elements in Diagonal Order**:
    - Initialize an empty vector `ans` to store the result.
    - Iterate over all diagonal indices from `0` to `maxKey`.
    - For each diagonal index, retrieve the corresponding group of elements from
the map.
    - Reverse the group (since elements are collected in reverse order of their
appearance) and append them to the result vector `ans`.

3. **Return the Result**:
    - After processing all diagonals, return the result vector `ans`.

This approach ensures that all elements are traversed in the required diagonal
order efficiently.
*/

class Solution {
  public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums) {
        unordered_map<int, vector<int>> groups;
        int maxKey = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                groups[i + j].push_back(nums[i][j]);
                maxKey = max(maxKey, i + j);
            }
        }

        vector<int> ans;

        for (int k = 0; k <= maxKey; k++) {
            if (groups.count(k)) {
                vector<int> diag = groups[k];
                for (int i = diag.size() - 1; i >= 0; i--) {
                    ans.push_back(diag[i]);
                }
            }
        }

        return ans;
    }
};
