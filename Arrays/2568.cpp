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
You are given a 0-indexed integer array nums.

We say that an integer x is expressible from nums if there exist some integers 0
<= index1 < index2 < ... < indexk < nums.length for which nums[index1] |
nums[index2] | ... | nums[indexk] = x. In other words, an integer is expressible
if it can be written as the bitwise OR of some subsequence of nums.

Return the minimum positive non-zero integer that is not expressible from nums.
*/

/*
Detailed Solution Logic:

The problem requires finding the smallest positive integer that cannot be
expressed as the bitwise OR of any subsequence of the given array `nums`.

### Key Observations:
1. **Bitwise OR Property**:
    - The bitwise OR operation combines bits from numbers such that if any bit
is `1` in any of the operands, it will be `1` in the result.
    - For example, `5 | 3 = 7` because:
      ```
      5 -> 101 (binary)
      3 -> 011 (binary)
      7 -> 111 (binary)
      ```

2. **Expressibility**:
    - Any number that is already in the array is trivially expressible.
    - Numbers that can be formed by OR-ing subsets of the array are also
expressible.

3. **Powers of Two**:
    - Powers of two (`1, 2, 4, 8, ...`) have a unique property: they have only
one bit set in their binary representation.
    - If a power of two is missing from the array, it cannot be formed by OR-ing
any subset of the array. This is because OR-ing numbers can only set bits that
are already present in the operands.

4. **Smallest Missing Power of Two**:
    - To find the smallest positive integer that is not expressible, we can
check for the smallest power of two (`1, 2, 4, 8, ...`) that is not present in
the array.

### Steps of Implementation:
1. Convert the array `nums` into a hash set `s` for O(1) lookup.
2. Start with the smallest power of two, `a = 1`.
3. Check if `a` exists in the set `s`.
    - If it exists, multiply `a` by 2 (move to the next power of two).
    - If it does not exist, return `a` as the result because it is the smallest
missing power of two.

### Complexity Analysis:
- **Time Complexity**: O(n), where `n` is the size of the array. This is because
we iterate through the array once to build the set and perform O(1) lookups for
each power of two.
- **Space Complexity**: O(n), for storing the elements of the array in the hash
set.
*/

class Solution {
  public:
    int minImpossibleOR(vector<int> &nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int a = 1;
        while (s.count(a)) {
            a = a * 2;
        }
        return a;
    }
};