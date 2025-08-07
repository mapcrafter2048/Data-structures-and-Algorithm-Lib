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
Given an integer array nums, return the sum of divisors of the integers in that
array that have exactly four divisors. If there is no such integer in the array,
return 0.
*/

/*
Solution Logic:

To find the sum of divisors of integers in the array that have exactly four
divisors, we need to identify such numbers and compute their divisor sums.

Observation:
- A number has exactly four divisors if and only if:
    1. It is the product of two distinct primes (n = p * q, p ≠ q).
         - Divisors: 1, p, q, n
    2. It is the cube of a prime (n = p^3).
         - Divisors: 1, p, p^2, n

Implementation Steps:
1. Generate all primes up to a reasonable limit (since n ≤ 10^5, we use sieve up
to 10^5).
2. For each number in the input array:
     a. Check if it is a cube of a prime (n = p^3). If so, sum its divisors: 1 +
p + p^2 + n. b. Otherwise, check if it is a product of two distinct primes (n =
p * q, p ≠ q). If so, sum its divisors: 1 + p + q + n.
3. Accumulate the sum for all such numbers and return the result.

The code uses a sieve to generate primes and a set for fast prime lookups. For
each number, it checks the two cases above and computes the divisor sum if the
number qualifies.
*/

class Solution {
  public:
    int MAX = 100000;
    vector<int> primes;
    unordered_set<int> primeSet;

    void generatePrimes() {
        vector<bool> isPrime(MAX + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }

        for (int i = 2; i <= MAX; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                primeSet.insert(i);
            }
        }
    }

    int sumFourDivisors(vector<int> &nums) {
        generatePrimes();
        int totalSum = 0;

        for (int n : nums) {
            int sum = 0;

            int root = round(pow(n, 1.0 / 3));
            if (root * root * root == n && primeSet.count(root)) {
                sum = 1 + root + root * root + n;
            } else {
                for (int p : primes) {
                    if (p * p > n)
                        break;
                    if (n % p == 0) {
                        int q = n / p;
                        if (q != p && primeSet.count(q)) {
                            sum = 1 + p + q + n;
                            break;
                        }
                    }
                }
            }

            totalSum += sum;
        }

        return totalSum;
    }
};
