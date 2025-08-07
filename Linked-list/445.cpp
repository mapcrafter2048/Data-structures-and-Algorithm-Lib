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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contains a single
digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Detailed Solution and Steps of Implementation:

The problem is to add two numbers represented by two linked lists, where each
node contains a single digit. The digits are stored in reverse order, meaning
the least significant digit comes first. The result should also be returned as a
linked list.

Steps to solve the problem:

1. Reverse the Input Linked Lists:
    - Since the digits are stored in reverse order, we first reverse both linked
lists to make the least significant digit the last node. This allows us to
perform addition from the least significant digit to the most significant digit.

2. Perform Addition:
    - Traverse both reversed linked lists simultaneously.
    - Add the corresponding digits from both lists along with any carry from the
previous addition.
    - Create a new node for the result of the addition (modulo 10) and update
the carry (integer division by 10).

3. Handle Remaining Carry:
    - If there is a carry left after processing both linked lists, create a new
node for the carry.

4. Reverse the Result Linked List:
    - Since the result is built in reverse order, reverse the result linked list
to restore the correct order.

5. Return the Result:
    - Return the head of the reversed result linked list.

The `addTwoNumbers` function implements these steps. It uses a helper function
`reverse` to reverse the linked lists.

Key Points:
- The `reverse` function iteratively reverses a linked list by adjusting the
`next` pointers.
- The addition is performed digit by digit, and a new linked list is constructed
to store the result.
- Edge cases, such as when one linked list is longer than the other or when
there is a carry at the end, are handled appropriately.
*/
class Solution {
  public:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *temp;
        while (head) {
            // Store the next node
            temp = head->next;
            // Reverse the current node's pointer
            head->next = prev;
            // Move prev and head one step forward
            prev = head;
            // Move head to the next node
            head = temp;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *r1 = reverse(l1);
        ListNode *r2 = reverse(l2);

        int sum = 0;
        int carry = 0;
        ListNode *ans = new ListNode();
        while (r1 != nullptr || r2 != nullptr) {
            if (r1 != nullptr) {
                sum += r1->val;
                r1 = r1->next;
            }
            if (r2 != nullptr) {
                sum += r2->val;
                r2 = r2->next;
            }

            ans->val = sum % 10;
            carry = sum / 10;
            ListNode *head = new ListNode(carry);
            head->next = ans;
            ans = head;
            sum = carry;
        }

        if (carry == 0) {
            return ans->next;
        } else {
            return ans;
        }

        return nullptr;
    }
};