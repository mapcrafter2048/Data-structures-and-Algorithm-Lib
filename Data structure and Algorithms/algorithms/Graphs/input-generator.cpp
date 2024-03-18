#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    ofstream outputFile("input.txt");

    srand(time(0));

    int n = 50;
    int m = 50;

    outputFile << n << " " << m << endl;

    // Generate random 0s and 1s for the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            outputFile << rand() % 2 << " ";
        }
        outputFile << endl;
    }

    outputFile.close();

    cout << "Input file 'input.txt' generated successfully!" << endl;

    return 0;
}
