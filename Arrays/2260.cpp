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
You are given an integer array cards where cards[i] represents the value of the
ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a
pair of matching cards among the picked cards. If it is impossible to have
matching cards, return -1.
*/

/*
Solution Logic and Steps of Implementation:

The problem requires finding the minimum number of consecutive cards to pick up
in order to have a pair of matching cards. If no such pair exists, return -1.

### Steps of Implementation:

1. **Understand the Problem**:
    - We need to find the smallest subarray that contains two cards with the
same value.
    - If no such subarray exists, return -1.

2. **Approach**:
    - Use a hash map (`unordered_map`) to store the last seen index of each card
value.
    - Iterate through the array, and for each card, check if it has been seen
before.
    - If it has been seen before, calculate the length of the subarray between
the current index and the last seen index of the card.
    - Keep track of the minimum length of such subarrays.

3. **Implementation**:
    - Initialize an `unordered_map` to store the last seen index of each card.
    - Initialize a variable `minLen` to `INT_MAX` to keep track of the minimum
subarray length.
    - Iterate through the array:
      - If the current card exists in the map, calculate the subarray length and
update `minLen` if the new length is smaller.
      - Update the map with the current index of the card.
    - After the loop, check if `minLen` is still `INT_MAX`. If it is, return -1
(no matching pair found). Otherwise, return `minLen`.

4. **Edge Cases**:
    - If the input array is empty or has only one card, return -1.
    - If no matching cards exist in the array, return -1.

### Complexity:
- **Time Complexity**: O(n), where n is the size of the array. We traverse the
array once.
- **Space Complexity**: O(u), where u is the number of unique card values in the
array. This is the space used by the hash map.

### Example:
Input: `cards = [3, 4, 2, 3, 4, 7]`
- At index 0, card = 3. Add to map: `{3: 0}`.
- At index 1, card = 4. Add to map: `{3: 0, 4: 1}`.
- At index 2, card = 2. Add to map: `{3: 0, 4: 1, 2: 2}`.
- At index 3, card = 3. Found in map. Subarray length = `3 - 0 + 1 = 4`. Update
`minLen = 4`.
- At index 4, card = 4. Found in map. Subarray length = `4 - 1 + 1 = 4`.
`minLen` remains 4.
- At index 5, card = 7. Add to map: `{3: 3, 4: 4, 2: 2, 7: 5}`.
Output: `4`.

If no matching cards exist, return `-1`.
*/

class Solution {
  public:
    int minimumCardPickup(vector<int> &cards) {
        unordered_map<int, int> mp;
        int minLen = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            int card = cards[i];

            if (mp.find(card) != mp.end()) {
                minLen = min(minLen, i - mp[card] + 1);
            }

            mp[card] = i;
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }
};
