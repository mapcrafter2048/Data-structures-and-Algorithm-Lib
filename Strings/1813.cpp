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
You are given two strings sentence1 and sentence2, each representing a sentence
composed of words. A sentence is a list of words that are separated by a single
space with no leading or trailing spaces. Each word consists of only uppercase
and lowercase English characters.

Two sentences s1 and s2 are considered similar if it is possible to insert an
arbitrary sentence (possibly empty) inside one of these sentences such that the
two sentences become equal. Note that the inserted sentence must be separated
from existing words by spaces.

For example,

    s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by
inserting "my name is" between "Hello" and "Jane" in s1. s1 = "Frog cool" and s2
= "Frogs are cool" are not similar, since although there is a sentence "s are"
inserted into s1, it is not separated from "Frog" by a space.

Given two sentences sentence1 and sentence2, return true if sentence1 and
sentence2 are similar. Otherwise, return false.
*/

/*
Logic and Steps of Implementation:

1. **Understand the Problem**:
    - Two sentences are considered similar if one sentence can be transformed
into the other by inserting an arbitrary sentence (possibly empty) into one of
them.
    - The inserted sentence must be separated from existing words by spaces.

2. **Approach**:
    - Split both sentences into words using a helper function.
    - Compare the shorter sentence (`A`) with the longer sentence (`B`) by
checking if the words at the beginning and end of `A` match the corresponding
words in `B`.
    - If all words in `A` can be matched to the beginning and end of `B`, then
the sentences are similar.

3. **Steps**:
    - Define a helper function `split` to split a sentence into words using a
string stream.
    - Split both sentences into vectors of words (`A` and `B`).
    - Ensure `A` is the shorter sentence by swapping if necessary.
    - Use two pointers (`i` and `p`) to compare the beginning of `A` with the
beginning of `B`.
    - Use two pointers (`j` and `q`) to compare the end of `A` with the end of
`B`.
    - If all words in `A` are matched (i.e., `i > j`), return `true`. Otherwise,
return `false`.

4. **Implementation**:
    - The helper function `split` splits a sentence into words.
    - The main function `areSentencesSimilar` performs the comparison using the
logic described above.
*/

class Solution {
  public:
    bool areSentencesSimilar(string s1, string s2) {
        auto split = [&](string &s) {
            vector<string> w;
            istringstream in(s);
            string t;
            while (in >> t)
                w.push_back(t);
            return w;
        };
        vector<string> A = split(s1);
        vector<string> B = split(s2);
        if (A.size() > B.size()) {
            swap(A, B);
        }

        int i = 0, j = (int)A.size() - 1;
        int p = 0, q = (int)B.size() - 1;

        while (i <= j && A[i] == B[p]) {
            i++;
            p++;
        }

        while (i <= j && A[j] == B[q]) {
            j--;
            q--;
        }

        return (i > j);
    }
};