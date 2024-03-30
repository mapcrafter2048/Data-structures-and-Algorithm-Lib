#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

string generateRandomString(int maxLength)
{
    int length = rand() % maxLength + 1;
    string randomString;
    for (int i = 0; i < length; i++)
    {
        char randomChar = 'a' + rand() % 26; // Generate a random lowercase letter
        randomString += randomChar;
    }
    return randomString;
}

int main()
{
    srand(time(0)); // Seed the random number generator

    int n;
    cout << "Enter the number of strings to generate: ";
    cin >> n;

    int maxLength;
    cout << "Enter the maximum length of the strings: ";
    cin >> maxLength;

    ofstream outputFile("input3.txt");

    outputFile << n << endl;

    for (int i = 0; i < n; i++)
    {
        string randomString = generateRandomString(maxLength);
        outputFile << randomString << endl; // Write the random string to the file
    }

    outputFile.close(); // Close the output file

    return 0;
}
