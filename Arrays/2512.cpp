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
You are given two string arrays positive_feedback and negative_feedback,
containing the words denoting positive and negative feedback, respectively. Note
that no word is both positive and negative.

Initially every student has 0 points. Each positive word in a feedback report
increases the points of a student by 3, whereas each negative word decreases the
points by 1.

You are given n feedback reports, represented by a 0-indexed string array report
and a 0-indexed integer array student_id, where student_id[i] represents the ID
of the student who has received the feedback report report[i]. The ID of each
student is unique.

Given an integer k, return the top k students after ranking them in
non-increasing order by their points. In case more than one student has the same
points, the one with the lower ID ranks higher.
*/

/*
Logic and Steps of Implementation:

1. **Understand the Problem**:
    - We need to rank students based on feedback reports.
    - Positive words increase the score by 3, and negative words decrease the
score by 1.
    - Students are ranked in non-increasing order of their scores. If scores are
equal, the student with the lower ID ranks higher.
    - Return the top `k` students.

2. **Steps of Implementation**:
    - **Step 1**: Convert `positive_feedback` and `negative_feedback` arrays
into unordered sets for fast lookup.
    - **Step 2**: Initialize a map (`unordered_map`) to store scores for each
student ID.
    - **Step 3**: Iterate through the `report` array and calculate scores for
each student:
      - Parse each feedback report using `istringstream` to extract individual
words.
      - Check if the word exists in the positive or negative feedback sets and
update the score accordingly.
    - **Step 4**: Store the student IDs and their scores in a vector of pairs.
    - **Step 5**: Sort the vector of pairs based on the following criteria:
      - Higher scores come first.
      - If scores are equal, lower student IDs come first.
    - **Step 6**: Extract the top `k` student IDs from the sorted vector and
return them.

3. **Key Points**:
    - Using unordered sets for positive and negative feedback ensures O(1)
lookup time.
    - Sorting is done using a custom comparator to handle both score and ID
ranking.
    - Efficient parsing of feedback reports ensures the solution scales well
with input size.

The implementation provided in the `topStudents` function follows these steps to
solve the problem efficiently.
*/

class Solution {
  public:
    vector<int> topStudents(vector<string> &posF, vector<string> &negF,
                            vector<string> &report, vector<int> &student_id,
                            int k) {
        unordered_set<string> pos(posF.begin(), posF.end());
        unordered_set<string> neg(negF.begin(), negF.end());

        unordered_map<int, int> score;
        for (int id : student_id) {
            score[id] = 0;
        }

        int n = report.size();
        for (int i = 0; i < n; ++i) {
            int id = student_id[i];
            istringstream in(report[i]);
            string w;
            while (in >> w) {
                if (pos.count(w)) {
                    score[id] += 3;
                } else if (neg.count(w)) {
                    score[id] -= 1;
                }
            }
        }

        vector<pair<int, int>> students;

        for (auto &it : score) {
            students.push_back({it.first, it.second});
        }

        sort(students.begin(), students.end(), [&](auto &a, auto &b) {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> ans(k);
        for (int i = 0; i < k; ++i)
            ans[i] = students[i].first;
        return ans;
    }
};
