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
You are playing a video game where you are defending your city from a group of n
monsters. You are given a 0-indexed integer array dist of size n, where dist[i]
is the initial distance in kilometers of the ith monster from the city.

The monsters walk toward the city at a constant speed. The speed of each monster
is given to you in an integer array speed of size n, where speed[i] is the speed
of the ith monster in kilometers per minute.

You have a weapon that, once fully charged, can eliminate a single monster.
However, the weapon takes one minute to charge. The weapon is fully charged at
the very start.

You lose when any monster reaches your city. If a monster reaches the city at
the exact moment the weapon is fully charged, it counts as a loss, and the game
ends before you can use your weapon.

Return the maximum number of monsters that you can eliminate before you lose, or
n if you can eliminate all the monsters before they reach the city.
*/

/*
Logic: We can calculate the time it takes for each monster to reach the city
by dividing the distance by the speed. We can then sort these times and check
if we can eliminate the monsters before they reach the city.
*/

class Solution {
  public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        int n = dist.size();
        vector<double> arrival(n);
        for (int i = 0; i < n; ++i) {
            arrival[i] = double(dist[i]) / speed[i];
        }
        sort(arrival.begin(), arrival.end());
        int kills = 0;
        for (int i = 0; i < n; ++i) {
            if (arrival[i] <= i)
                break;
            ++kills;
        }
        return kills;
    }
};
