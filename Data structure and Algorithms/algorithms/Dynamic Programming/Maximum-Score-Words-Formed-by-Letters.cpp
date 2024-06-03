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
maxScoreWords(["dog", "cat", "dad"], ...)
 |
 ├── dog (pos = 0, temp = 15) (recursive call)
 |     |
 |     ├── cat (pos = 1, temp = 19) (recursive call)
 |     |     |
 |     |     └── dad (pos = 2, INVALID, d overused) (recursive call)
 |     |
 |     └── dad (pos = 2, INVALID, d overused) (iterative call)
 |
 ├── cat (pos = 1, temp = 5) (iterative call)
 |     |
 |     └── dad (pos = 2, temp = 12, answer = 12) (recursive call)
 |
 └── dad (pos = 0, INVALID, d overused) (iterative call)
*/

int maxScoreWords(vector<string> &words, vector<char> &letters,
                  vector<int> &score) {
    // Main function: Finds the maximum score achievable by forming words from
    // the given letters.
    vector<int> count(26, 0); // Frequency count of available letters
    vector<int> lettersCount(26, 0);
    // Frequency count of letters used in the current word combination

    // Count the frequency of available letters
    for (auto &character : letters) {
        count[character - 'a']++;
        // Convert character to index (0-25) and increment count
    }

    int answer = 0; // Stores the maximum score found
    // Start backtracking to explore all possible word combinations
    backtracking(words, score, count, lettersCount, 0, 0, answer);

    return answer; // Return the maximum score found
}

void backtracking(vector<string> &words, vector<int> &score, vector<int> &count,
                  vector<int> &lettersCount, int pos, int temp, int &answer) {
    // Backtracking function: Recursively explores word combinations and updates
    // maximum score.

    // Base case: Check if any letter has been used more times than available
    for (int i = 0; i < 26; i++) {
        if (lettersCount[i] > count[i]) {
            return; // Invalid combination: a letter is overused
        }
    }

    // Update maximum score if the current combination has a higher score
    answer = max(answer, temp);

    // Recursive case: Explore remaining words starting from 'pos'
    for (int i = pos; i < words.size(); i++) {
        // Add the letters of the current word to the used letters count and
        // update the score
        for (auto ch : words[i]) {
            lettersCount[ch - 'a']++;
            temp += score[ch - 'a'];
        }

        // Recursively try the next word
        backtracking(words, score, count, lettersCount, i + 1, temp, answer);

        // Backtrack: Remove the letters of the current word from the used
        // letters count and update the score
        for (auto ch : words[i]) {
            lettersCount[ch - 'a']--;
            temp -= score[ch - 'a'];
        }
    }
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}