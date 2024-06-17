/*
You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right
side of it.

Return the head of the modified linked list.
*/
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

/*
so this a question of a monotonic stack and here we have to remove the nodes
which have a greater value on the right side of it. so what we will do is that
we will push the elemets in the stack but as soon as we encounter a node with
value greater than the top of the stack we will pop the stack until we get the
element which is greater than the current node and then we will push the current
node in the stack. and then we will reverse the stack and return the head of the
stack.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNodes(ListNode *head) {
    ListNode *curr = head;
    stack<ListNode *> st;

    while (curr != nullptr) {
        while (!st.empty() && st.top()->val < curr->val) {
            st.pop();
        }
        st.push(curr);
        curr = curr->next;
    }

    ListNode *nextval = nullptr;
    while (!st.empty()) {
        curr = st.top();
        st.pop();
        curr->next = nextval;
        nextval = curr;
    }

    return curr;
}

int main() {
    auto start = high_resolution_clock::now();

    // Your code here
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    ListNode *res = removeNodes(head);

    while (res != nullptr) {
        cout << res->val << " ";
        res = res->next;
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;
    return 0;
}