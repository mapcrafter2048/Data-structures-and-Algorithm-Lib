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
There are several cards arranged in a row, and each card has an associated
number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the
row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score
you can obtain.
*/

/*
Logic: To maximize the score, we can use a sliding window approach. We will
calculate the total points and then find the minimum sum of the points in a
window of size n - k, where n is the total number of cards. The maximum score
can be obtained by subtracting this minimum sum from the total points.

Implementation Steps:
1. Calculate the total points by summing all elements in cardPoints.
2. If k is equal to the size of cardPoints, return the total points.
3. Calculate the size of the window as n - k.
4. Initialize a variable to keep track of the current sum of the first window.
5. Iterate through the array to find the minimum sum of the window.
6. Subtract the minimum sum from the total points to get the maximum score.
7. Find the last occurrence of the sorted digit in the original vector.
8. Convert the modified vector back to a string and return the integer value.
*/
class Solution {
  public:
    int maxScore(vector<int> &cp, int k) {
        int n = cp.size();
        int total = accumulate(cp.begin(), cp.end(), 0);
        if (k == n) {
            return total;
        }

        int wsize = n - k;
        int curr = 0;
        for (int i = 0; i < wsize; i++) {
            curr += cp[i];
        }

        int minSum = curr;
        for (int i = wsize; i < n; i++) {
            curr += cp[i] - cp[i - wsize];
            minSum = min(minSum, curr);
        }

        return total - minSum;
    }
};
