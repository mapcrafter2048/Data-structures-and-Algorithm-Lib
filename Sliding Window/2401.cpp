#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = nullptr;
    }
};

/*
Logic:
1. We will use a sliding window to solve this problem.
2. We will use two pointers l and r to represent the left and right end of the
window.
3. We will use a variable usedBits to store the bits that are used in the
current window.
4. We will iterate over the array using the right pointer r.
5. If the current bit is already present in the usedBits, we will move the left
pointer l to the right until the current bit is not present in the usedBits.
6. We will update the usedBits by adding the current bit.
7. We will update the maxLength by taking the maximum of the current window
length and the previous maxLength.
8. We will return the maxLength.

Example:
nums = [1, 3, 8, 48, 10]
l = 0, r = 0, usedBits = 000000, maxLength = 0
For demonstration purposes, we simulate the sliding window process on the array:
[1, 3, 8, 48, 10]
Iteration details:
-----------------------------------------------------------------
Outer loop iteration 0 (r = 0): Process nums[0] = 1.
  - Inner loop: Not entered because usedBits (0) & 1 equals 0.
  - After adding: usedBits becomes (0 | 1) = 1.
  - Window: [0, 0] with length 1 -> maxLength = 1.
Outer loop iteration 1 (r = 1): Process nums[1] = 3.
  - Inner loop: Entered because usedBits (1) & 3 yields 1 (nonzero).
      • Removing nums[0] = 1 from usedBits: usedBits becomes (1 ^ 1) = 0; l becomes 1.
  - Inner loop ends (now 0 & 3 equals 0).
  - After adding: usedBits becomes (0 | 3) = 3.
  - Window: [1, 1] with length 1 -> maxLength remains 1.
Outer loop iteration 2 (r = 2): Process nums[2] = 8.
  - Inner loop: Not entered because usedBits (3) & 8 equals 0.
  - After adding: usedBits becomes (3 | 8) = 11.
  - Window: [1, 2] with length 2 -> maxLength becomes 2.
Outer loop iteration 3 (r = 3): Process nums[3] = 48.
  - Inner loop: Not entered because usedBits (11) & 48 equals 0 (no overlapping bits).
  - After adding: usedBits becomes (11 | 48), forming a combined bitmask.
  - Window: [1, 3] with length 3 -> maxLength becomes 3.
Outer loop iteration 4 (r = 4): Process nums[4] = 10.
  - Inner loop: Entered because usedBits (from previous iterations) & 10 is nonzero.
      • Removing nums[1] = 3: usedBits updates via XOR; l becomes 2.
      • Check again: still conflict? Yes, so remove nums[2] = 8; usedBits updates; l becomes 3.
      • Now, usedBits (after removals) & 10 equals 0, ending the inner loop.
  - After adding: usedBits becomes updated bitmask | 10.
  - Window: [3, 4] with length 2 -> maxLength remains 3.
The final computed longest nice subarray length is 3.
*/

int longestNiceSubarray(vector<int>& nums) {
    int l = 0, usedBits = 0, maxLength = 0;

    for (int r = 0; r < nums.size(); r++) {
        while ((usedBits & nums[r]) != 0) {
            usedBits ^= nums[l];
            l++;
        }

        usedBits |= nums[r];
        maxLength = max(maxLength, r - l + 1);
    }

    return maxLength;
}

int main() {
    // Your code here
    return 0;
}