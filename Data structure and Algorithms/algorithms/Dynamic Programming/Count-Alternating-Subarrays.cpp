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

// This is the examples of Iterative dp in which we are not using memoization so we using the solution of the previous problems to find the solution of the current problem. In this if the current element is not equal to the previous element then we will add 1 to the previous element and store it in the current element. If the current element is equal to the previous element then we will store 1 in the current element. In the end we will add all the elements of the dp array and return the answer.
long long int countAlternatingSubarrays(vector<int> &nums)
{
    int n = nums.size();
    vector<long long int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] != nums[i])
        {
            dp[i] = 1 + dp[i - 1];
        }
        else
        {
            dp[i] = 1;
        }
    }

    long long int answer = 0;
    for (int i = 0; i < n; i++)
    {
        answer += dp[i];
    }

    return answer;
}

int main()
{
    auto start = high_resolution_clock::now();

    ifstream inputFile("Count-Alternating-Subarrays.txt");

    if (!inputFile.is_open())
    {
        cout << "File not found!" << endl;
        return 0;
    }

    int numcases;
    inputFile >> numcases;
    int i = 0;
    while (numcases--)
    {
        i++;
        int length;
        inputFile >> length;
        vector<int> nums(length);
        for (int i = 0; i < length; i++)
        {
            inputFile >> nums[i];
        }

        auto startCase = high_resolution_clock::now();
        int result = countAlternatingSubarrays(nums);
        auto stopCase = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stopCase - startCase);

        ofstream outputFile("Count-Alternating-Subarrays-output.txt", ios::app);
        if (!outputFile.is_open())
        {
            cerr << "Error opening Edit-distance-output.txt" << endl;
            return 1;
        }
        outputFile << "Test case " << i << ": " << result << " Completed in " << duration.count() << " nanoseconds" << endl;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}