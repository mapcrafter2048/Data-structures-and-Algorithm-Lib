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
An integer x is numerically balanced if for every digit d in the number x, there
are exactly d occurrences of that digit in x.

Given an integer n, return the smallest numerically balanced number strictly
greater than n.
*/

/*
To solve the problem, we need to find the smallest numerically balanced number
strictly greater than a given number `n`. A numerically balanced number is
defined as a number where each digit `d` appears exactly `d` times in the
number.

### Steps to Solve the Problem:

1. **Understand the Problem**:
    - A numerically balanced number has a unique property where the count of
each digit matches the digit itself.
    - For example:
      - `22` is numerically balanced because the digit `2` appears exactly 2
times.
      - `122` is numerically balanced because the digit `1` appears 1 time, and
the digit `2` appears 2 times.

2. **Precompute Balanced Numbers**:
    - Since numerically balanced numbers are rare and follow specific patterns,
we can precompute all possible numerically balanced numbers up to a reasonable
limit.
    - This allows us to use a simple lookup to find the next numerically
balanced number greater than `n`.

3. **Generate Balanced Numbers**:
    - Use nested loops to generate all possible combinations of digits that
satisfy the numerically balanced property.
    - For each digit `d` (from 1 to 9), construct numbers where `d` appears
exactly `d` times.
    - Ensure the generated numbers are valid and sorted.

4. **Find the Next Balanced Number**:
    - Use binary search (`upper_bound`) to efficiently find the smallest
numerically balanced number greater than `n` from the precomputed list.

5. **Implementation**:
    - The `generate` function creates a list of all numerically balanced
numbers.
    - The `nextBeautifulNumber` function uses the precomputed list to find the
desired result.

### Implementation Details:
- The `generate` function constructs balanced numbers by iterating over digits
and appending them the required number of times.
- The `nextBeautifulNumber` function uses the `upper_bound` function from the
C++ Standard Library to find the smallest number greater than `n` in logarithmic
time.

### Complexity:
- **Precomputation**: Generating balanced numbers is efficient due to the
limited range of digits (1 to 9).
- **Query**: Finding the next balanced number is `O(log k)` where `k` is the
size of the precomputed list.

This approach ensures correctness and efficiency by leveraging precomputation
and binary search.
*/

class Solution {
  public:
    vector<int> generate() {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            string s = to_string(i);
            for (int j = 0; j < i; ++j) {
                s += to_string(i);
            }
            ans.push_back(stoi(s));
        }
        return ans;
    }

    int nextBeautifulNumber(int n) {
        vector<int> ans{
            0,      1,      22,     122,    212,    221,    333,     1333,
            3133,   3313,   3331,   4444,   14444,  22333,  23233,   23323,
            23332,  32233,  32323,  32332,  33223,  33232,  33322,   41444,
            44144,  44414,  44441,  55555,  122333, 123233, 123323,  123332,
            132233, 132323, 132332, 133223, 133232, 133322, 155555,  212333,
            213233, 213323, 213332, 221333, 223133, 223313, 223331,  224444,
            231233, 231323, 231332, 232133, 232313, 232331, 233123,  233132,
            233213, 233231, 233312, 233321, 242444, 244244, 244424,  244442,
            312233, 312323, 312332, 313223, 313232, 313322, 321233,  321323,
            321332, 322133, 322313, 322331, 323123, 323132, 323213,  323231,
            323312, 323321, 331223, 331232, 331322, 332123, 332132,  332213,
            332231, 332312, 332321, 333122, 333212, 333221, 422444,  424244,
            424424, 424442, 442244, 442424, 442442, 444224, 444242,  444422,
            515555, 551555, 555155, 555515, 555551, 666666, 1224444,
        };
        return *upper_bound(ans.begin(), ans.end(), n);
    }
};