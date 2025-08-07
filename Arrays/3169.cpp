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
Intuition

In the previous approach, we used a map to efficiently track meeting schedules,
but this required additional space to store boundary changes for each meeting.
Since each meeting contributes up to two unique entries in the map, the space
complexity grows linearly with the number of meetings. To optimize space usage,
we need a solution that avoids maintaining an extra data structure for storing
these intervals.

A more space efficient approach relies on sorting the meetings array based on
the starting times of meetings. By doing so, we can process meeting intervals in
order and determine gaps where no meetings are scheduled without needing a
separate map to track changes. The key observation here is that if meetings are
sorted, any gap between the current latest end time and the next meeting’s start
time represents a range of free days.

With this in mind, we can maintain a variable latestEnd, initialized to 0, which
keeps track of the latest ending time of meetings encountered so far. After
sorting the meetings, we iterate through them one by one. For each meeting
[start, end], we check if start > latestEnd + 1. If this condition holds, it
means there is a gap between latestEnd and start, representing a range of days
with no scheduled meetings. We add the length of this gap (start - latestEnd -
1) to our count of free days. Since latestEnd starts at 0, this check also
accounts for any free days before the first scheduled meeting (starting from day
1).

After processing a meeting, we update latestEnd to be the maximum of its current
value and the end of the current meeting, ensuring we always track the furthest
scheduled day. Once all meetings have been processed, we add any remaining free
days after the last meeting (up to days) to our count.

Through this process, we only process the ranges of each meeting while avoiding
the use of any data structures dependent on the input size. Algorithm

    Initialize:
        freeDays to 0 to count the number of days with no meeting scheduled.
        latestEnd to 0 to track the latest time a meeting ends.
    Sort meetings based on starting times.
    Iterate through meetings. For each meeting, [start, end]:
        If start > latestEnd + 1, meaning there is a gap where no meeting is
scheduled: Increase freeDays by start - latestEnd - 1 to represent the current
range of days without a meeting. Update latestEnd to the maximum of latestEnd
and end. Increase freeDays by days - latestEnd to represent the remaining days
without a meeting. Return freeDays.

*/

class Solution {
  public:
    int countDays(int days, vector<vector<int>> &meetings) {
        int freeDays = 0, latestEnd = 0;

        // Sort meetings based on starting times
        sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // Add current range of days without a meeting
            if (start > latestEnd + 1) {
                freeDays += start - latestEnd - 1;
            }

            // Update latest meeting end
            latestEnd = max(latestEnd, end);
        }

        // Add all days after the last day of meetings
        freeDays += days - latestEnd;

        return freeDays;
    }
};