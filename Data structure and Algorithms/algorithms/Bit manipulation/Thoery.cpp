#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
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

// checks if the ith bit is set
bool isBitSet(int num, int i) { return (num & (1 << i)) != 0; }

// sets the ith bit
bool isOdd(int num) {
    return (num & 1) == 1; // Check if the least significant bit is 1
}

bool isPowerOfTwo(int num) { return (num > 0) && ((num & (num - 1)) == 0); }

int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1); // Unset the rightmost set bit
        count++;
    }
    return count;
}

int setRightmostUnsetBit(int num) { return num | (num + 1); }

int unsetRightmostUnsetBit(int num) { return num & (num + 1); }

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
int divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::runtime_error("Division by zero");
    }

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
    long long dvd = llabs(dividend);
    long long dvs = llabs(divisor);
    int quotient = 0;

    while (dvd >= dvs) {
        long long temp = dvs, multiple = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }

    return sign * quotient;
}

// << and >> are the left and right shift operators
// << shifts the bits of a number to the left by a certain number of positions
// >> shifts the bits of a number to the right by a certain number of positions
// 1 << i shifts the bits of 1 to the left by i positions
// 1 >> i shifts the bits of 1 to the right by i positions
// & is the bitwise AND operator
// | is the bitwise OR operator
// ^ is the bitwise XOR operator
// ~ is the bitwise NOT operator

int toggleBit(int num, int i) { return num ^ (1 << i); }

int clearBit(int num, int i) { return num & ~(1 << i); }

int setBit(int num, int i) { return num | (1 << i); }

int updateBit(int num, int i, int bitValue) {
    int mask = ~(1 << i);
    return (num & mask) | (bitValue << i);
}

int reverseBits(int num) {
    int reversedNum = 0;
    int numOfBits = sizeof(num) * 8;
    for (int i = 0; i < numOfBits; i++) {
        if (isBitSet(num, i)) {
            reversedNum |= (1 << (numOfBits - 1 - i));
        }
    }
    return reversedNum;
}

int countLeadingZeros(int num) {
    int count = 0;
    int numOfBits = sizeof(num) * 8;
    for (int i = numOfBits - 1; i >= 0; i--) {
        if (isBitSet(num, i)) {
            break;
        }
        count++;
    }
    return count;
}

int countTrailingZeros(int num) {
    int count = 0;
    int numOfBits = sizeof(num) * 8;
    for (int i = 0; i < numOfBits; i++) {
        if (isBitSet(num, i)) {
            break;
        }
        count++;
    }
    return count;
}

int rotateLeft(int num, int k) {
    int numOfBits = sizeof(num) * 8;
    k %= numOfBits;
    return (num << k) | (num >> (numOfBits - k));
}

int rotateRight(int num, int k) {
    int numOfBits = sizeof(num) * 8;
    k %= numOfBits;
    return (num >> k) | (num << (numOfBits - k));
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}