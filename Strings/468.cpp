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
Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if
IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and
xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0"
are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1"
are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:

    1 <= xi.length <= 4
    xi is a hexadecimal string which may contain digits, lowercase English
letter ('a' to 'f') and upper-case English letters ('A' to 'F'). Leading zeros
are allowed in xi.

For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and
"2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while
"2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334"
are invalid IPv6 addresses.
*/

/*
Solution Logic:

The problem requires determining whether a given string is a valid IPv4 address,
a valid IPv6 address, or neither. To solve this, we break the problem into
smaller steps:

1. **Input Validation**:
    - Check if the input string matches the format of an IPv4 or IPv6 address.

2. **IPv4 Validation**:
    - An IPv4 address consists of four decimal numbers separated by dots (`.`).
    - Each number must be between 0 and 255.
    - Leading zeros are not allowed unless the number is `0`.
    - Non-numeric characters are invalid.

3. **IPv6 Validation**:
    - An IPv6 address consists of eight hexadecimal groups separated by colons
(`:`).
    - Each group can have 1 to 4 characters.
    - Valid characters include digits (`0-9`) and letters (`a-f`, `A-F`).
    - Empty groups or groups with invalid characters are not allowed.

4. **Implementation Steps**:
    - Split the input string based on the delimiter (`.` for IPv4 and `:` for
IPv6).
    - Validate each part of the split string based on the rules for IPv4 or
IPv6.
    - Return the appropriate result: `"IPv4"`, `"IPv6"`, or `"Neither"`.

Steps of Implementation:

1. **Helper Function: `split`**:
    - Splits a string into parts based on a given delimiter.
    - Used to divide the input string into components for validation.

2. **IPv4 Validation (`validIPv4`)**:
    - Count the number of dots (`.`) in the string. If not exactly 3, return
false.
    - Split the string into four parts using the `split` function.
    - Check each part:
      - Ensure it is non-empty and has at most 3 characters.
      - Ensure it does not have leading zeros unless it is `0`.
      - Ensure all characters are digits.
      - Convert the part to an integer and check if it is within the range [0,
255].

3. **IPv6 Validation (`validIPv6`)**:
    - Count the number of colons (`:`) in the string. If not exactly 7, return
false.
    - Split the string into eight parts using the `split` function.
    - Check each part:
      - Ensure it is non-empty and has at most 4 characters.
      - Ensure all characters are valid hexadecimal digits (`0-9`, `a-f`,
`A-F`).

4. **Main Function (`validIPAddress`)**:
    - Call `validIPv4` and `validIPv6` to check the validity of the input
string.
    - Return `"IPv4"` if `validIPv4` is true, `"IPv6"` if `validIPv6` is true,
or `"Neither"` otherwise.
*/

class Solution {
  public:
    string validIPAddress(string IP) {
        return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6" : "Neither");
    }

    vector<string> split(string s, char c) {
        vector<string> parts;
        string part;
        istringstream in(s);
        while (getline(in, part, c)) {
            parts.push_back(part);
        }
        return parts;
    }
    bool validIPv4(string IP) {
        if (count(IP.begin(), IP.end(), '.') != 3) {
            return false;
        }
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 3 ||
                (part.size() > 1 && part[0] == '0')) {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c)) {
                    return false;
                }
            }
            if (stoi(part) > 255) {
                return false;
            }
        }
        return true;
    }

    bool validIPv6(string IP) {
        if (count(IP.begin(), IP.end(), ':') != 7) {
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8) {
            return false;
        }
        for (string part : parts) {
            if (part.empty() || part.size() > 4) {
                return false;
            }
            for (char c : part) {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) {
                    return false;
                }
            }
        }
        return true;
    }
};