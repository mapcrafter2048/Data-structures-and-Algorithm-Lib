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
You are given an integer array arr of length n that represents a permutation of
the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually
sort each chunk. After concatenating them, the result should equal the sorted
array.

Return the largest number of chunks we can make to sort the array.
*/

/*
Logic and Steps of Implementation:

1. **Understanding the Problem**:
    - The array `arr` is a permutation of integers in the range `[0, n-1]`.
    - We need to split the array into chunks such that sorting each chunk
individually and concatenating them results in the sorted array.
    - The goal is to maximize the number of such chunks.

2. **Key Insight**:
    - If we traverse the array and keep track of the maximum value encountered
so far (`maxSoFar`), we can determine if the current index `i` can form a chunk.
    - Specifically, if `maxSoFar == i`, it means all elements up to index `i`
are in their correct positions relative to the sorted array, and we can form a
chunk.

3. **Steps of Implementation**:
    - Initialize `chunks` to 0 to count the number of chunks.
    - Initialize `maxSoFar` to 0 to track the maximum value encountered so far.
    - Traverse the array using a loop:
      - Update `maxSoFar` to be the maximum of `maxSoFar` and the current
element `arr[i]`.
      - If `maxSoFar == i`, increment the `chunks` counter because we can form a
chunk up to this index.
    - Return the value of `chunks` after the loop ends.

4. **Complexity**:
    - Time Complexity: O(n), where `n` is the size of the array, as we traverse
the array once.
    - Space Complexity: O(1), as we use only a few variables for tracking.

5. **Example**:
    - Input: `arr = [1, 0, 2, 3, 4]`
    - Process:
      - At `i = 0`, `maxSoFar = 1` (not equal to `i`).
      - At `i = 1`, `maxSoFar = 1` (equal to `i`), so increment `chunks` to 1.
      - At `i = 2`, `maxSoFar = 2` (equal to `i`), so increment `chunks` to 2.
      - At `i = 3`, `maxSoFar = 3` (equal to `i`), so increment `chunks` to 3.
      - At `i = 4`, `maxSoFar = 4` (equal to `i`), so increment `chunks` to 4.
    - Output: `chunks = 4`
*/

class Solution {
  public:
    int maxChunksToSorted(vector<int> &arr) {
        int n = arr.size();
        int chunks = 0;
        int maxSoFar = 0;
        for (int i = 0; i < n; ++i) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) {
                ++chunks;
            }
        }
        return chunks;
    }
};
