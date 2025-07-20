/*
Given a positive integer n, you can apply one of the following operations:

If n is even, replace n with n / 2.
If n is odd, replace n with either n + 1 or n - 1.
Return the minimum number of operations needed for n to become 1.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

/*
Given the constraints of n (0 to 2^31 - 1), using a vector to store the computed values would require a huge amount of memory, which is not feasible.

On the other hand, an unordered map only stores the values that are actually used, which is much more memory-efficient.

In the provided code, the function solve uses an unordered map dp to store the computed values. If the value for a particular n has already been computed, it is returned directly from the map. If not, it is computed and stored in the map for future use. This is a common technique in dynamic programming to avoid redundant computations.
*/

int solve(long long int n, unordered_map<long long int, long long int> &dp)
{
    if (n <= 1)
    {
        return 0;
    }

    if (dp.find(n) != dp.end())
        return dp[n];

    if (n % 2 == 0)
    {
        return dp[n] = 1 + solve(n / 2, dp);
    }
    else
    {
        long long int addOne = 1 + solve(n + 1, dp);
        long long int subOne = 1 + solve(n - 1, dp);
        return dp[n] = min(addOne, subOne);
    }
}

int integerReplacement(int n)
{
    unordered_map<long long int, long long int> dp;
    return solve(n, dp);
}

int main()
{
    auto start = high_resolution_clock::now();

    cout << integerReplacement(8) << endl;

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}