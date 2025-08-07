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
You are given an array of events where events[i] = [startDayi, endDayi]. Every
event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You
can only attend one event at any time d.

Return the maximum number of events you can attend.
*/

/*
Logic: We can use a greedy approach with a priority queue to keep track of the
end days of the events. We will sort the events by their start days and then
iterate through the days, always attending the event that ends the earliest.
This way, we can maximize the number of events attended.

Implementation Steps:
1. Sort the events based on their start days.
2. Use a priority queue to keep track of the end days of the events that can be
attended.
3. Iterate through the days, adding events to the priority queue as they start.
4. Attend the event that ends the earliest and remove it from the priority
queue.
*/

/*
Dry run: [[1,2],[2,3],[3,4],[1,2]]
1. Sort the events: [[1,2],[1,2],[2,3],[3,4]]
2. Initialize day = 0, index = 0, n = 4, result = 0.
3. Start processing:
    - Day 0: Add events [1,2] to the queue.
    - Attend event [1,2], increment result to 1, day becomes 1.
    - Remove events that end before day 1.
    - Day 1: Add events [1,2] to the queue.
    - Attend event [1,2], increment result to 2, day becomes 2.
    - Remove events that end before day 2.
    - Day 2: Add event [2,3] to the queue.
    - Attend event [2,3], increment result to 3, day becomes 3.
    - Remove events that end before day 3.
    - Day 3: Add event [3,4] to the queue.
    - Attend event [3,4], increment result to 4, day becomes 4.
4. Return result = 4, which is the maximum number of events attended.

*/

int maxEvents(vector<vector<int>> &events) {
    // Step 1: Sort all events based on their start day.
    // This helps us process the events in chronological order.
    sort(events.begin(), events.end());

    // Step 2: Create a min-heap (priority queue) to track end days of events
    // that are available. We always want to attend the event that ends the
    // earliest to maximize our schedule.
    priority_queue<int, vector<int>, greater<int>> pq;

    // `day` will track the current simulation day.
    // `index` will help us iterate through the sorted event list.
    int day = 0, index = 0, n = events.size(), result = 0;

    // Step 3: Main loop runs while we still have events to process or events
    // available in pq.
    while (!pq.empty() || index < n) {
        // If no events are currently available to attend, skip to the next
        // event's start day.
        if (pq.empty()) {
            day = events[index]
                        [0]; // Jump to the start of the next available event.
        }

        // Step 4: Push into the min-heap all events that start on or before the
        // current day. Their end dates go into the heap for greedy selection.
        while (index < n && events[index][0] <= day) {
            pq.push(events[index][1]); // Push the endDay of the event
            index++;
        }

        // Step 5: Attend the event that ends the earliest (top of min-heap).
        // We assume one event per day, so pop the top and increment `day`.
        pq.pop();
        result++;
        day++; // We move to the next day after attending this one.

        // Step 6: Remove all events from pq that have already expired (end <
        // current day). These events can no longer be attended.
        while (!pq.empty() && pq.top() < day) {
            pq.pop();
        }
    }

    // Step 7: Return the total number of events attended.
    return result;
}
