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
Approach 1: Monotonic Stack & Priority Queue
Intuition

    For convenience, let the element with the highest prime score in a subarray
be the "dominant" element of that subarray.

To address the challenge described above, it is helpful to calculate the number
of subarrays each number is dominant in. With this information, we can start
with the largest element and apply the operation to all subarrays where it
remains dominant. We then repeat this for the second-largest element, and so on,
until no further operations can be performed.

First, we need an efficient way to calculate the prime score of a number n. To
do this, we iterate over all numbers in the range [2, sqrt(n)]. If we find a
number p that divides n, we increment the prime score and remove all occurrences
of p in n by repeatedly dividing n by p until it is no longer possible. Notice
that we don't need to check if p is prime to increment the prime score because
any composite number (e.g., 9, 15) will have had its smaller prime factors
removed earlier and therefore will not divide n. Finally, if n >= 2, n must be
prime, so we increment the score once more.

Now, notice that a number remains dominant until another element with a greater
prime score appears either to its left or right. To efficiently determine this
region, we use a monotonic decreasing stack, which helps identify the nearest
elements with a higher prime score on both sides.

To better understand monotonic stacks, you can try solving Next Greater Element
I first. It’s a great prerequisite for this problem!

A monotonic stack is a data structure that maintains a specific order as
elements are inserted. In this case, we need a monotonically decreasing stack
based on prime scores, meaning each new element can only be added if it has a
lower prime score than the one at the top. If the top element has a greater
prime score, we pop it from the stack. When the current element causes another
to be popped, it means it is the first element with a higher prime score to the
right. Conversely, if we reach an element in the stack with a greater prime
score than the current one, that element is the first with a higher prime score
to the left.

Current

After finding the indices of the nearest elements with a higher prime score on
the left and right, prevDominant[i] and nextDominant[i], we can compute the
number of subarrays in which the i-th element is dominant.

For the left boundary, we have i - prevDominant[i] choices, and for each of
them, we have nextDominant[i] - i choices for the right boundary. This gives a
total of: (i - prevDominant[i]) * (nextDominant[i] - i) subarrays, where the
i-th element is dominant.

Visual Representation of All Valid Subarrays

Finally, we need an efficient way to determine the next element on which we will
apply operations across all subarrays where it is dominant. Since we need to
process elements in decreasing order to maximize the score, a priority queue
(max-heap) is a useful data structure. It allows us to quickly extract the
largest element and then remove it to move on to the next one.

    If you need a refresher on heaps, check out the Heap Explore Card to review
their functionality and common patterns.

To sum up, the algorithm follows these steps:

    Calculate the prime score for each number in nums.
    Use a monotonic stack to determine the prevDominant[i] and nextDominant[i]
indices for each nums[i]. Compute the number of subarrays in which each number
is dominant. Use a priority queue to process the numbers in decreasing order and
apply operations to all subarrays where they are dominant.

Algorithm

    Initialize:
        n to the size of the nums array.
        an array, called primeScores of size n.
    Iterate over nums with index from 0 to n - 1 to calculate the prime scores:
        Set num to nums[index].
        For each factor in range [2, sqrt(num)]:
            If factor divides num:
                Increment primeScores[index] by 1.
                Remove all occurrences of factor in num by repeatedly dividing
by factor. If num >= 2, num is prime, so increment primeScores[index] one more
time. Initialize: two arrays nextDominant and prevDominant to store the indices
of the nearest elements with a higher prime score on both sides of each number.
Set all elements in nextDominant to n and all values of prevDominant to -1. an
empty stack decreasingPrimeScoreStack. Iterate over nums with index from 0 to n
- 1 to fill the nextDominant and prevDominant arrays: While the stack is not
empty and the element at index decreasingPrimeScoreStack.top() has a lower prime
score than nums[index]: Pop the top element of the stack as topIndex. Set
nextDominant[topIndex] to the current index. If the stack is not empty, set
prevDominant[index] to the index at the top of the stack. Push index into the
stack. Initialize an array of size n called numOfSubarrays. Iterate over nums
with index from 0 to n - 1 to count the number of subarrays in which each
element is dominant: Calculate numOfSubarrays[index] as (nextDominant[index] -
index) * (index - prevDominant[index]). Initialize: a priority queue,
processingQueue of pairs (value, index) and insert all elements of nums into it.
        score to 1.
    While k > 0, meaning that we are still allowed to perform operations:
        Pop the front element of the queue as [num, index].
        Calculate the number of operations that we will perform on subarrays in
which num is dominant, as min(k, subarrays[index]). Multiply score by num ^
operations using modular exponentiation. Decrement k by operations. Return
score.

*/

class Solution {
  public:
    const int MOD = 1e9 + 7;

    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            // Check for prime factors from 2 to sqrt(n)
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    // Increment prime score for each prime factor
                    primeScores[index]++;

                    // Remove all occurrences of the prime factor from num
                    while (num % factor == 0)
                        num /= factor;
                }
            }

            // If num is still greater than or equal to 2, it's a prime factor
            if (num >= 2)
                primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Priority queue to process elements in decreasing order of their value
        priority_queue<pair<int, int>> processingQueue;

        // Push each number and its index onto the priority queue
        for (int index = 0; index < n; index++)
            processingQueue.push({nums[index], index});

        long long score = 1;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value from the queue
            auto [num, index] = processingQueue.top();
            processingQueue.pop();

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

  private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }
};