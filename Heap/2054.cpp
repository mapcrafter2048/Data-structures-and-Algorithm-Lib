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
You are given a 0-indexed 2D integer array of events where events[i] =
[startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at
endTimei, and if you attend this event, you will receive a value of valuei. You
can choose at most two non-overlapping events to attend such that the sum of
their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend
two events where one of them starts and the other ends at the same time. More
specifically, if you attend an event with end time t, the next event must start
at or after t + 1.
*/

/*
### Revised Solution Logic Steps:

1. **Sort Events by Start Time**:
    - The events array is sorted based on the start time of each event. This
ensures events are processed in chronological order.

2. **Use a Priority Queue to Track End Times and Values**:
    - A min-heap (priority queue) is used to store pairs `(endTime, value)` for
events that have been processed. This enables efficient retrieval of events that
have ended before the current event begins.

3. **Track the Best Value Among All Suitable Past Events**:
    - A variable `best` is maintained to store the maximum value among events
that have ended strictly before the current event starts.

4. **Iterate Through Each Event**:
    - For each event, remove all events from the priority queue whose `endTime`
is less than the current event's `startTime` (ensuring they do not overlap,
since the next event must start at or after previous event’s end time + 1).
    - Update `best` with the maximum value from the removed events.
    - Calculate the potential combined value by adding `best` to the current
event’s value, then update the answer.
    - Push the current event `(endTime, value)` onto the queue.

5. **Return the Maximum Sum**:
    - After processing all events, `ans` holds the maximum combined value of at
most two non-overlapping events.

---

### Detailed Dry Run Example:

Consider the input:
  events = [[1, 3, 5], [2, 5, 6], [4, 6, 5], [7, 10, 10]]

**Initial state:**
  - best = 0, ans = 0, priority queue (pq) = {}

**Step 1: Process event [1, 3, 5]**
  - pq is empty, so no events are removed.
  - ans = max(0, 0 + 5) = 5.
  - Push (3, 5) into pq.

**State after Step 1:**
  - pq = {(3, 5)}, best = 0, ans = 5

**Step 2: Process event [2, 5, 6]**
  - Check the top of pq: (3, 5). Since 3 is NOT < 2, we do not pop.
  - best remains 0.
  - ans = max(5, 0 + 6) = 6.
  - Push (5, 6) into pq.

**State after Step 2:**
  - pq = {(3, 5), (5, 6)}  (min-heap: top is (3, 5))
  - best = 0, ans = 6

**Step 3: Process event [4, 6, 5]**
  - Remove events from pq with endTime < current event's start (4):
      • Top (3, 5): 3 < 4; update best = max(0, 5) = 5 and pop it.
      • Now top becomes (5, 6): 5 is NOT < 4; stop popping.
  - ans = max(6, best + current value) = max(6, 5 + 5) = 10.
  - Push (6, 5) into pq.

**State after Step 3:**
  - pq = {(5, 6), (6, 5)}
  - best = 5, ans = 10

**Step 4: Process event [7, 10, 10]**
  - Remove events from pq with endTime < current event's start (7):
      • Top (5, 6): 5 < 7; update best = max(5, 6) = 6 and pop it.
      • Next, top (6, 5): 6 < 7; best remains max(6, 5) = 6 and pop it.
      • Now pq is empty.
  - ans = max(10, best + current value) = max(10, 6 + 10) = 16.
  - Push (10, 10) into pq.

**Final state:**
  - pq = {(10, 10)}
  - best = 6, ans = 16

**Result:**
  - The maximum sum of values from at most two non-overlapping events is 16.
*/

/*
Problem: You're given a list of events, each with a startTime, endTime, and
value. You can attend at most two non-overlapping events to maximize the total
value.

Approach:
This is a classic interval scheduling problem with a twist:

    Instead of maximizing the number of events attended, you maximize the sum of
values.

    You can attend at most two non-overlapping events.

We'll solve it using a Greedy approach with a min-heap (priority queue) to
simulate a sweep line over time.

At each step:

    Keep a heap of previous events that have ended

    Keep track of the best value so far (maxPrev) among those expired events

    For the current event:

        You can either take it alone (Option 1)

        Or pair it with the best earlier non-overlapping event (Option 2)

This way, for every event, we consider the best combination possible.
*/

class Solution {
  public:
    int maxTwoEvents(vector<vector<int>> &events) {
        // Step 1: Sort all events by start time
        // This enables us to process events in chronological order.
        sort(events.begin(), events.end());

        // Priority queue to hold previous events: (endTime, value)
        // This heap helps us remove "expired" events efficiently.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int maxPrev =
            0; // Best value from any past event that ended before current start
        int result = 0; // Maximum result across all choices

        // Step 2: Iterate through sorted events
        for (auto &event : events) {
            int start = event[0]; // Current event's start time
            int end = event[1];   // Current event's end time
            int value = event[2]; // Value of attending this event

            /*
            Remove all previous events from the heap whose endTime is less than
            current start. These are valid candidates for pairing
            (non-overlapping).
            */
            while (!pq.empty() && pq.top().first < start) {
                // Update maxPrev with the best value seen so far among expired
                // events
                maxPrev = max(maxPrev, pq.top().second);
                pq.pop();
            }

            /*
            Option 1: Attend this event alone → its value contributes directly.
            */
            result = max(result, value);

            /*
            Option 2: Pair with the best earlier non-overlapping event
            (tracked via maxPrev)
            */
            if (maxPrev > 0) {
                result = max(result, value + maxPrev);
            }

            /*
            Add this event to the heap for future candidates.
            It may serve as a non-overlapping option for later events.
            */
            pq.emplace(end, value);
        }

        // Final result: maximum value by attending at most two non-overlapping
        // events
        return result;
    }
};