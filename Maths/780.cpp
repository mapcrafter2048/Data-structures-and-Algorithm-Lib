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
Given four integers sx, sy, tx, and ty, return true if it is possible to convert
the point (sx, sy) to the point (tx, ty) through some operations, or false
otherwise.

The allowed operation on some point (x, y) is to convert it to either (x, x + y)
or (x + y, y).
*/

/*
Logic and Steps of Implementation:

The problem is to determine if we can transform the starting point (sx, sy) into
the target point (tx, ty) using the allowed operations:
1. (x, y) -> (x, x + y)
2. (x, y) -> (x + y, y)

Instead of simulating the forward operations from (sx, sy) to (tx, ty), we
reverse the process. This is because the reverse operations are deterministic:
1. If tx > ty, the previous state must have been (tx - ty, ty).
2. If ty > tx, the previous state must have been (tx, ty - tx).

Steps:
1. Start from (tx, ty) and work backward to (sx, sy).
2. If tx == sx and ty == sy, return true (we've successfully reached the
starting point).
3. If tx < sx or ty < sy, return false (we've gone out of bounds).
4. Use modulo operations to skip unnecessary steps:
    - If tx > ty, reduce tx by taking `tx %= ty` (this simulates multiple
backward steps in one operation).
    - If ty > tx, reduce ty by taking `ty %= tx`.
5. Handle edge cases where one of the coordinates matches the starting point:
    - If tx == sx, check if (ty - sy) is divisible by sx.
    - If ty == sy, check if (tx - sx) is divisible by sy.
6. Repeat the process until tx < sx or ty < sy, or until we reach (sx, sy).

This approach ensures efficiency by avoiding unnecessary iterations and directly
jumping to potential valid states using modulo operations.
*/

class Solution {
  public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            // If we reach the starting point, return true
            if (tx == sx && ty == sy) {
                return true;
            }
            // If tx > ty, we can only reduce tx by taking modulo with ty this
            // essentially simulates multiple steps
            if (tx > ty) {
                // if ty is greater than sy, we can reduce tx by taking modulo
                // which essentially simulates multiple steps of
                // (x, y) -> (x + y, y)
                if (ty > sy) {
                    tx %= ty;
                } else {
                    // if ty is equal to sy, we can only check if tx can be
                    // reached by adding sy multiple times
                    return (tx - sx) % sy == 0;
                }
            } else {
                // if tx is greater than sx, we can reduce ty by taking modulo
                // which essentially simulates multiple steps of
                // (x, y) -> (x, x + y)
                if (tx > sx) {
                    ty %= tx;
                } else {
                    // if tx is equal to sx, we can only check if ty can be
                    // reached by adding sx multiple times
                    return (ty - sy) % sx == 0;
                }
            }
        }
        return false;
    }
};
