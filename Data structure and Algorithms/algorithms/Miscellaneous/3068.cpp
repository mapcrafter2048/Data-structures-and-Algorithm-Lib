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
lets take an example of the array od
a---b---c---d

->a will become, because first we have choose the edge between a and b

a----b----c----d
a ^ k

a------b------c------d
a ^ k  b ^ k

a------b------c------d
a ^ k  b ^ k
       b ^ k ^ k

a------b------c------d
a ^ k  b ^ k
       b

a------b------c------d
a ^ k  b ^ k  c ^ k
       b

a------b------c------d
a ^ k  b ^ k  c ^ k
       b      c ^ k ^ k

a------b------c------d
a ^ k  b ^ k  c ^ k
       b      c

a------b------c------d
a ^ k  b ^ k  c ^ k  d ^ k
       b      c

*/

long long maximumValueSum(vector<int> &v, int k, vector<vector<int>> &edges) {

    long long total = accumulate(v.begin(), v.end(), 0ll);

    long long total_diff = 0;
    long long diff;
    int positive_count = 0;
    long long min_abs_diff = numeric_limits<int>::max();
    for (auto p : v) {
        diff = (p ^ k) - p;
            
        if (diff > 0) {
            total_diff += diff;
            positive_count++;
        }
        min_abs_diff = min(min_abs_diff, abs(diff));
    }
    if (positive_count % 2 == 1) {
        total_diff = total_diff - min_abs_diff;
    }
    return total + total_diff;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}