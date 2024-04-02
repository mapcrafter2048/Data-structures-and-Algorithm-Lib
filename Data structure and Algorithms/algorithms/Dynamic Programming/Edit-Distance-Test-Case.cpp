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
using namespace std::chrono;

string generateRandomString(int maxLength)
{
    int length = rand() % maxLength + 1;
    string randomString;
    for (int i = 0; i < length; i++)
    {
        char randomChar = 'a' + rand() % 26;
        randomString += randomChar;
    }

    return randomString;
}

int main()
{
    auto start = high_resolution_clock::now();

    srand(time(0));

    int n;
    cout << "Enter the number of cases: ";
    cin >> n;

    int maxLength;
    cout << "Enter the maximum length of the strings: ";
    cin >> maxLength;

    ofstream outputFile("Edit-String.txt");
    outputFile << n << endl;

    for (int i = 0; i < n; i++)
    {
        string randomString1 = generateRandomString(maxLength);
        string randomString2 = generateRandomString(maxLength);
        outputFile << randomString1 << " " << randomString2 << endl;
    }

    outputFile.close();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}