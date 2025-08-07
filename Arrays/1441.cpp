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
You are given an integer array target and an integer n.

You have an empty stack with the two following operations:

    "Push": pushes an integer to the top of the stack.
    "Pop": removes the integer on the top of the stack.

You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom
to the top) equal to target. You should follow the following rules:

    If the stream of the integers is not empty, pick the next integer from the
stream and push it to the top of the stack. If the stack is not empty, pop the
integer at the top of the stack. If, at any moment, the elements in the stack
(from the bottom to the top) are equal to target, do not read new integers from
the stream and do not do more operations on the stack.

Return the stack operations needed to build target following the mentioned
rules. If there are multiple valid answers, return any of them.
*/

/*
Solution Logic and Steps of Implementation:

The problem requires us to simulate stack operations ("Push" and "Pop") to
construct a stack that matches the given `target` array using integers from a
stream [1, n]. The goal is to determine the sequence of operations needed to
achieve this.

### Steps of Implementation:

1. **Initialization**:
    - Create a vector `ans` to store the sequence of operations.
    - Use an integer `ind` to keep track of the current number being processed
from the stream.

2. **Iterate Through the Target Array**:
    - For each number in the `target` array, determine how many numbers from the
stream need to be skipped (pushed and then popped) before reaching the current
target number.

3. **Simulate Stack Operations**:
    - Use a `while` loop to simulate pushing and popping numbers from the stream
until the current number matches the target number.
    - For each skipped number, add "Push" followed by "Pop" to the `ans` vector.
    - Once the current target number is reached, add "Push" to the `ans` vector
to keep it in the stack.

4. **Increment the Stream Index**:
    - After processing each target number, increment the `ind` variable to move
to the next number in the stream.

5. **Return the Result**:
    - After processing all numbers in the `target` array, return the `ans`
vector containing the sequence of operations.

### Example Walkthrough:

#### Input:
- `target = [1, 3]`
- `n = 3`

#### Execution:
- Start with an empty stack and `ind = 0`.
- Process `target[0] = 1`:
  - Push "1" onto the stack (`ans = ["Push"]`).
  - Increment `ind` to 1.
- Process `target[1] = 3`:
  - Skip "2" by pushing and popping it (`ans = ["Push", "Push", "Pop"]`).
  - Push "3" onto the stack (`ans = ["Push", "Push", "Pop", "Push"]`).
  - Increment `ind` to 3.

#### Output:
- `ans = ["Push", "Push", "Pop", "Push"]`

This sequence of operations constructs the stack `[1, 3]` as required.

### Complexity Analysis:
- **Time Complexity**: O(n), where `n` is the size of the `target` array. Each
number in the `target` array is processed once, and the operations for skipped
numbers are constant time.
- **Space Complexity**: O(n), for storing the result in the `ans` vector.
*/

class Solution {
  public:
    vector<string> buildArray(vector<int> &target, int n) {
        vector<string> ans;
        int ind = 0;

        for (int i = 0; i < target.size(); i++) {
            while (ind < target[i] - 1) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ind++;
            }
            ans.push_back("Push");
            ind++;
        }

        return ans;
    }
};