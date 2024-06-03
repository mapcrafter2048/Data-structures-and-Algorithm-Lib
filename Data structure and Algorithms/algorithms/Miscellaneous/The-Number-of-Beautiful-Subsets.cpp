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
 The line mp[nums[index]]++; is crucial for keeping track of which elements are
currently included in the subset being explored.

How it Works

The mp map: This unordered map (hash map) is used to efficiently store the
frequency of elements within the current subset. The key of the map is the
element itself (nums[index]), and the value is the count of how many times that
element appears in the subset.

Marking Inclusion: When we decide to include an element in the subset (after
confirming it doesn't violate the "beautiful" condition), we increment its count
in the map: mp[nums[index]]++;.  This effectively "marks" that the element is
now part of the subset.

Checking for Violations: The map comes in handy when we're checking if including
a new element would violate the "beautiful" condition. We simply look up whether
nums[index] - K or nums[index] + K exists in the map. If either one is present,
it means there's already an element in the subset that would create a difference
of K with the new element, so we can't include it.

Backtracking: After exploring all possible subsets that include the current
element (nums[index]), we need to "undo" its inclusion so we can explore other
combinations. This is where mp[nums[index]]--; comes in. It decrements the count
of that element, effectively removing it from the subset and restoring the map
to its previous state before the element was added.

Example

Let's say nums = [1, 5, 7] and K = 2.

We start with an empty subset (mp is empty).
We consider including 1. Since neither 1 nor 3 are in mp, it's valid. So we do
mp[1]++; (now mp contains {1: 1}). Next, we consider 5. Since neither 3 nor 7
are in mp, it's also valid. We do mp[5]++; (mp now contains {1: 1, 5: 1}).
Finally, we consider 7. But this time, 5 is in mp, so including 7 would violate
the rule. We don't include it. We backtrack. First, we remove 5 by doing
mp[5]--;. Now mp is back to {1: 1}. We try other combinations starting from 1,
and so on... In essence, mp[nums[index]]++; acts like a flag to indicate that an
element is currently in the subset. The map provides a fast way to check for
violations of the "beautiful" condition and to restore the subset to its
previous state during backtracking.
*/

int result;
int K;

// Global variable to store the count of beautiful subsets found
int result = 0;
// Global variable to store the given value of K
int K;

// Depth-First Search (DFS) to explore subset combinations
void dfs(vector<int> nums, int index, unordered_map<int, int> mp) {
    // Base case: If we've reached the end of the array (considered all
    // elements),
    //  a beautiful subset has been formed
    if (index == nums.size()) {
        result++; // Increment the count of beautiful subsets
        return;   // Backtrack
    }

    // Recursive case 1: Don't include the current element
    //  Explore subsets without it
    dfs(nums, index + 1, mp); // Move to the next index

    // Recursive case 2: Check if including the current element is valid
    // Check if neither (nums[index] - K) nor (nums[index] + K) exists in the
    // map
    if (!mp[nums[index] - K] && !mp[nums[index] + K]) {
        mp[nums[index]]++;        // Mark the current element as included
        dfs(nums, index + 1, mp); // Explore subsets with it
        mp[nums[index]]--; // Undo the inclusion (backtrack) for exploring other
                           // options
    }
}

// Function to calculate and return the count of beautiful subsets
int beautifulSubset(vector<int> nums, int k) {
    result = 0; // Reset the global counter for fresh calculation
    K = k;      // Store the given value of K globally
    unordered_map<int, int> mp; // Map to track elements in the current subset
    dfs(nums, 0, mp);           // Start DFS from the beginning of the array
    return result - 1; // Subtract 1 to exclude the empty subset (which is not
                       // considered beautiful)
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}