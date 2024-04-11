#include <iostream>
#include <fstream>
#include <random>

using namespace std;

int main()
{
    ofstream outputFile("Count-Alternating-Subarrays.txt");

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
        uniform_int_distribution<int> sizeDist(1, 100);
        int arraySize = sizeDist(generator);

        outputFile << arraySize << endl;

        // Generate random binary array elements (0 or 1)
        uniform_int_distribution<int> dataDist(0, 1);
        for (int j = 0; j < arraySize; ++j)
        {
            outputFile << dataDist(generator) << " ";
        }
        outputFile << endl; // Newline after each array
    }

    outputFile.close();
    return 0;
}
