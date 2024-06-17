#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int max(int a, int b) { return (a > b) ? a : b; }

void displayVector(const vector<char> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int lengthOfLongestSubstring(string s)
{
    int length = 0;
    vector<char> substring;
    int i = 0;
    while (i <= s.size())
    {
        if (substring.size() > 0)
        {
            for (int j = 0; j < substring.size(); j++)
            {
                if (substring[j] != s[i])
                {
                    substring.push_back(s[i]);
                    i++;
                }
                else if (substring[j] == s[i])
                {
                    length = max(substring.size(), length);
                    substring.clear();
                    i++;
                }
            }
        }
        else
        {
            substring.push_back(s[i]);
            i++;
        }
        cout << "length: " << length << endl;
        displayVector(substring);
    }

    return length;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}