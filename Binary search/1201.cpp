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
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.
*/

/*
Logic and Steps of Implementation:

1. **Understanding the Problem**:
    - An "ugly number" is defined as a positive integer divisible by at least
one of the integers `a`, `b`, or `c`.
    - The task is to find the `n`th ugly number in ascending order.

2. **Approach**:
    - Use binary search to efficiently find the `n`th ugly number.
    - Calculate the number of ugly numbers less than or equal to a given number
`x` using the inclusion-exclusion principle.

3. **Key Observations**:
    - The count of numbers divisible by `a` is `x / a`.
    - Similarly, for `b` and `c`, the counts are `x / b` and `x / c`.
    - To avoid double-counting, subtract counts for numbers divisible by the
least common multiple (LCM) of pairs `(a, b)`, `(a, c)`, and `(b, c)`.
    - Add back the count for numbers divisible by the LCM of `(a, b, c)`.

4. **Steps**:
    - Compute the LCMs of `a`, `b`, and `c` using the formula `lcm(x, y) = (x /
gcd(x, y)) * y`.
    - Use binary search to find the smallest number `x` such that the count of
ugly numbers ≤ `x` is at least `n`.
    - The count of ugly numbers ≤ `x` is calculated using the
inclusion-exclusion principle.

5. **Binary Search**:
    - Start with a range `[low, high]`, where `low = 1` and `high = 2e18` (a
large number to ensure the range covers the `n`th ugly number).
    - Compute the midpoint `mid` and count the ugly numbers ≤ `mid`.
    - If the count is less than `n`, move the `low` pointer to `mid + 1`.
    - Otherwise, move the `high` pointer to `mid`.
    - Repeat until `low == high`, which gives the `n`th ugly number.

6. **Return Result**:
    - The final value of `low` is the `n`th ugly number.
*/

class Solution {
  public:
    typedef long long ll;

    ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

    ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

    int nthUglyNumber(int n, int a, int b, int c) {
        ll ab = lcm(a, b);
        ll ac = lcm(a, c);
        ll bc = lcm(b, c);
        ll abc = lcm(ab, c);

        ll low = 1, high = 2e18;

        while (low < high) {
            ll mid = low + (high - low) / 2;
            ll count = mid / a + mid / b + mid / c - mid / ab - mid / ac -
                       mid / bc + mid / abc;

            if (count < n)
                low = mid + 1;
            else
                high = mid;
        }

        return (int)low;
    }
};
