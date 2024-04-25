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
    ofstream outputFile("input2.txt");

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
        uniform_int_distribution<int> sizeDist(1, 150); // Arrays with 1 to 150 rows
        int numRows = sizeDist(generator);
        outputFile << numRows << endl;

        uniform_int_distribution<int> colDist(1, 150); // Arrays with 1 to 150 columns
        int numCols = colDist(generator);
        outputFile << numCols << endl;

        // Generate random array elements
        uniform_int_distribution<int> dataDist(0, 1); // adjust range as needed
        for (int j = 0; j < numRows; ++j)
        {
            for (int k = 0; k < numCols; ++k)
            {
                outputFile << dataDist(generator) << " ";
            }
            outputFile << endl; // Newline after each row
        }
        outputFile << endl; // Newline after each array
    }

    outputFile.close();
    return 0;
}
