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
Given an integer array arr, return the number of distinct bitwise ORs of all the
non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray.
The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

/*
Solution Logic:

The problem requires us to find the number of distinct bitwise OR results of all
non-empty subarrays of the given array `arr`. To solve this problem, we can use
the following approach:

1. **Understanding Bitwise OR**:
    - The bitwise OR operation between two integers sets a bit in the result if
that bit is set in either of the integers.
    - For example, `5 | 3` results in `7` because `5` in binary is `101` and `3`
is `011`. The OR operation results in `111`, which is `7`.

2. **Key Observations**:
    - The bitwise OR operation is cumulative. For example, if we have a subarray
`[a, b, c]`, the OR result of the entire subarray can be computed as `((a | b) |
c)`.
    - This means that for each new element in the array, we can compute the OR
results by combining it with the results of the previous subarray ORs.

3. **Efficient Calculation**:
    - Instead of calculating the OR for every possible subarray (which would be
computationally expensive), we can maintain a set of OR results from the
previous step (`prev`) and compute the new OR results for the current element.
    - For each element in the array, we:
      - Start a new OR result with the current element itself.
      - Combine the current element with all previous OR results to generate new
OR results.
    - Store all these results in a set to ensure uniqueness.

4. **Steps of Implementation**:
    - Initialize an empty set `result` to store all distinct OR results.
    - Initialize an empty set `prev` to store the OR results of the previous
step.
    - Iterate through each element in the array:
      - Create a new set `curr` to store the OR results for the current step.
      - Add the current element to `curr`.
      - For each OR result in `prev`, compute the OR with the current element
and add it to `curr`.
      - Add all elements of `curr` to `result`.
      - Update `prev` to `curr` for the next iteration.
    - Return the size of the `result` set, which represents the number of
distinct OR results.

5. **Complexity**:
    - Time Complexity: The worst-case time complexity is `O(n * m)`, where `n`
is the size of the array and `m` is the number of distinct OR results generated
in each step. In practice, `m` is limited by the number of bits in the integers.
    - Space Complexity: The space complexity is `O(m)` for storing the sets.

This approach ensures that we efficiently compute the distinct OR results
without explicitly generating all subarrays.
*/

class Solution {
  public:
    int subarrayBitwiseORs(vector<int> &arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for (int num : arr) {
            unordered_set<int> curr;

            curr.insert(num);

            for (int x : prev)
                curr.insert(x | num);

            for (int x : curr)
                result.insert(x);

            prev = curr;
        }

        return result.size();
    }
};