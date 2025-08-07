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
You want to water n plants in your garden with a watering can. The plants are
arranged in a row and are labeled from 0 to n - 1 from left to right where the
ith plant is located at x = i. There is a river at x = -1 that you can refill
your watering can at.

Each plant needs a specific amount of water. You will water the plants in the
following way:

    Water the plants in order from left to right.
    After watering the current plant, if you do not have enough water to
completely water the next plant, return to the river to fully refill the
watering can. You cannot refill the watering can early.

You are initially at the river (i.e., x = -1). It takes one step to move one
unit on the x-axis.

Given a 0-indexed integer array plants of n integers, where plants[i] is the
amount of water the ith plant needs, and an integer capacity representing the
watering can capacity, return the number of steps needed to water all the
plants.

*/

/*
The solution involves simulating the process of watering the plants step by
step. Here are the detailed steps of implementation:

1. Initialize variables:
    - `steps` to keep track of the total number of steps taken.
    - `tmp` to represent the remaining water in the watering can, initialized to
the given `capacity`.

2. Iterate through the `plants` array:
    - For each plant at index `i`, check if the current plant can be watered
with the remaining water in the can (`tmp`).
      - If yes, increment `steps` by 1 (move to the next plant).
      - If no, calculate the steps required to go back to the river, refill the
watering can, and return to the current plant:
         - Going back to the river takes `i` steps.
         - Refilling the can and returning to the current plant takes another `i
+ 1` steps.
         - Add `2 * i + 1` to `steps`.
         - Reset `tmp` to the full capacity of the watering can.

3. Deduct the amount of water required by the current plant from `tmp`.

4. Continue the process until all plants are watered.

5. Return the total number of steps taken (`steps`).
*/

class Solution {
  public:
    int wateringPlants(vector<int> &plants, int caps) {
        int steps = 0;
        int tmp = caps;

        for (int i = 0; i < plants.size(); i++) {
            if (plants[i] <= tmp) {
                steps++;
            } else if (plants[i] > tmp) {
                steps += (2 * i + 1);
                tmp = caps;
            }

            tmp -= plants[i];
        }

        return steps;
    }
};