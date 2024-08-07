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
#include <random>

using namespace std;
using namespace chrono;

int main()
{
    ofstream outputFile("Coin-change.txt");

    random_device rd;
    mt19937 generator(rd()); // Seed the random number generator

    // Get the number of test cases from the user
    int numTestCases;
    cout << "Enter the number of test cases: ";
    cin >> numTestCases;

    outputFile << numTestCases << endl;

    for (int i = 0; i < numTestCases; ++i)
    {
        // Generate random array size
        uniform_int_distribution<int> sizeDist(1, 10);
        int arraySize = sizeDist(generator);

        outputFile << arraySize << endl;

        // Generate random array elements
        uniform_int_distribution<int> dataDist(0, 50); // adjust range as needed
        for (int j = 0; j < arraySize; ++j)
        {
            outputFile << dataDist(generator) << " ";
        }

        uniform_int_distribution<int> amountDist(0, 100); // adjust range as needed
        int amount = amountDist(generator);
        outputFile << endl
                   << amount << endl;
    }

    outputFile.close();
    return 0;
}
