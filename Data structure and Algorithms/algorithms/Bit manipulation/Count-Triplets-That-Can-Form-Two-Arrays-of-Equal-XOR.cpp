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

int countTriplets(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    vector<int> prefixXOR(n + 1,
                          0); // Create prefix XOR array, initialized to 0

    // Calculate prefix XOR for each index
    for (int i = 0; i < n; ++i) {
        prefixXOR[i + 1] =
            prefixXOR[i] ^ arr[i]; // XOR of elements up to index i
    }

    // Count triplets
    for (int i = 0; i < n; ++i) {         // First element of triplet
        for (int j = i + 1; j < n; ++j) { // Second element of triplet
            if (prefixXOR[i] == prefixXOR[j + 1]) {
                // If XOR up to i == XOR up to j+1, then XOR of i to j is 0
                count += (j - i); // Number of triplets with i and j fixed
            }
        }
    }
    return count;
}

int countTriplets2(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    vector<int> prefixXOR(n + 1, 0);
    vector<pair<int, int>> pairs;

    // Calculate prefix XOR and create pairs
    for (int i = 0; i < n; ++i) {
        prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        pairs.push_back({prefixXOR[i + 1], i + 1});
    }

    // Sort pairs
    sort(pairs.begin(), pairs.end());

    // Two-pointer counting
    int left = 0, right = 0;
    while (right < n) {
        if (pairs[left].first == pairs[right].first) {
            count += right - left - 1;
            right++;
        } else {
            left++;
        }
    }

    return count;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}