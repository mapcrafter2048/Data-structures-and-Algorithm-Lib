#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> map;

        int left = 0;
        int len = 0;
        for (int j = 0; j < s.length(); j++)
        {
            map[s[j]]++;

            if (map[s[j]] > 1)
            {

                while (map[s[j]] > 1)
                {

                    map[s[left]]--;
                    left++;
                }
            }
            if (j - left + 1 > len)
            {
                len = j - left + 1;
            }
        }
        return len;
    }
};

int main()
{

    return 0;
}