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
You have a list arr of all integers in the range [1, n] sorted in a strictly
increasing order. Apply the following algorithm on arr:

    Starting from left to right, remove the first number and every other number
afterward until you reach the end of the list. Repeat the previous step again,
but this time from right to left, remove the rightmost number and every other
number from the remaining numbers. Keep repeating the steps again, alternating
left to right and right to left, until a single number remains.

Given the integer n, return the last number that remains in arr.
*/

/*
Detailed Solution Logic:

The problem involves repeatedly removing elements from a list in alternating
directions (left-to-right and right-to-left) until only one element remains.
Instead of simulating the entire process with an actual list (which would be
inefficient for large `n`), we can solve the problem mathematically by observing
patterns.

Key Observations:
1. The list starts with all integers from 1 to `n` in increasing order.
2. In each pass:
    - From left-to-right: The first element is always removed, and every second
element is removed afterward.
    - From right-to-left: The last element is removed, and every second element
is removed backward.
3. After each pass, the size of the list is halved, and the step size (distance
between consecutive elements) doubles.
4. The process alternates between left-to-right and right-to-left.

Mathematical Approach:
- Instead of maintaining the entire list, we track the "head" of the list (the
first remaining element) and update it based on the direction of traversal and
the number of remaining elements.
- If traversing left-to-right, the head always moves forward by the current step
size.
- If traversing right-to-left:
  - The head moves forward by the step size only if the number of remaining
elements is odd (because the first element is removed in this case).
- The step size doubles after each pass, and the number of remaining elements is
halved.

Steps of Implementation:
1. Initialize `head` to 1 (the first element of the list), `step` to 1 (initial
step size), and `remaining` to `n` (total elements in the list).
2. Use a boolean `leftToRight` to track the direction of traversal, starting
with `true` (left-to-right).
3. While more than one element remains:
    - If traversing left-to-right (`leftToRight == true`) or the number of
remaining elements is odd, update `head` by adding `step` to it.
    - Halve the number of remaining elements (`remaining /= 2`).
    - Double the step size (`step *= 2`).
    - Toggle the direction (`leftToRight = !leftToRight`).
4. When only one element remains, return `head` as the result.
*/

class Solution {
  public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int remaining = n;
        bool leftToRight = true;

        while (remaining > 1) {
            if (leftToRight || (remaining % 2 == 1)) {
                head += step;
            }
            remaining /= 2;
            step *= 2;
            leftToRight = !leftToRight;
        }
        return head;
    }
};
