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
In a special ranking system, each voter gives a rank from highest to lowest to
all teams participating in the competition.

The ordering of teams is decided by who received the most position-one votes. If
two or more teams tie in the first position, we consider the second position to
resolve the conflict, if they tie again, we continue this process until the ties
are resolved. If two or more teams are still tied after considering all
positions, we rank them alphabetically based on their team letter.

You are given an array of strings votes which is the votes of all voters in the
ranking systems. Sort all teams according to the ranking system described above.

Return a string of all teams sorted by the ranking system.
*/

/*
Logic:
1. Each team is ranked based on the number of votes it receives for each
position.
    - For example, if a team receives the most votes for the first position, it
is ranked higher.
2. If two teams have the same number of votes for a position, the next position
is considered to resolve the tie.
    - This process continues for all positions until the tie is resolved.
3. If all positions tie, teams are ranked alphabetically based on their team
letter.

Steps of Implementation:
1. Create a map (unordered_map) to store the vote count for each team at each
position.
    - The key is the team letter, and the value is a vector of integers
representing the vote count for each position.
2. Initialize the map with all teams and their respective vote counts as zero.
    - Use the first vote string to determine the list of teams.
3. Iterate through the votes and update the vote count for each team at each
position.
    - For each vote string, increment the corresponding position count for each
team.
4. Extract all teams into a vector for sorting.
    - This vector will contain all team letters.
5. Sort the teams based on the vote count for each position, breaking ties
alphabetically.
    - Use a custom comparator function for sorting:
      - Compare the vote counts for each position.
      - If the vote counts are equal for all positions, compare the team letters
alphabetically.
6. Convert the sorted vector of teams into a string and return it.
    - Concatenate the sorted team letters into a single string.
*/

class Solution {
  public:
    string rankTeams(vector<string> &votes) {
        // Create a map to store the vote counts for each team at each position
        unordered_map<char, vector<int>> cnt;
        // Initialize the map with all teams and their respective vote counts as
        // zero Use the first vote string to determine the list of teams
        for (int i = 0; i < votes[0].size(); ++i) {
            char c = votes[0][i];
            cnt[c] = vector<int>(votes[0].size(), 0);
        }
        // Iterate through the votes and update the vote count for each team at
        // each position
        for (int i = 0; i < votes.size(); ++i) {
            string v = votes[i];
            for (int j = 0; j < votes[0].size(); ++j) {
                char c = v[j];
                cnt[c][j]++;
            }
        }

        vector<char> teams;
        teams.reserve(votes[0].size());

        for (auto it : cnt) {
            teams.push_back(it.first);
        }
        // Sort the teams based on the vote count for each position, breaking
        // ties alphabetically
        sort(teams.begin(), teams.end(), [&](char a, char b) {
            for (int i = 0; i < votes[0].size(); i++) {
                if (cnt[a][i] != cnt[b][i]) {
                    return cnt[a][i] > cnt[b][i];
                }
            }
            return a < b;
        });

        return string(teams.begin(), teams.end());
    }
};