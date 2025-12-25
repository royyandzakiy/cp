/*

https://leetcode.com/problems/linked-list-cycle/description/

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note
that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// --------- boilerplate ---------

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x),
          next(NULL) {
    }
};

ListNode* createList(const std::vector<int>& values, int pos) {
    if (values.empty())
        return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* tail = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;

    for (size_t i = 1; i < values.size(); ++i) {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
        if (i == static_cast<size_t>(pos)) {
            cycleNode = tail;
        }
    }

    if (pos != -1) {
        tail->next = cycleNode;
    }

    return head;
}

// Basic cleanup (Careful: this will infinite loop if there's a cycle!)
void deleteList(ListNode* head, bool hasCycle) {
    if (hasCycle || !head)
        return;
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// --------- solution ---------

class Solution {
  public:
    bool hasCycle_MoreVerbose(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return false;

        bool hasCycle = false;

        auto slow_ptr = head;
        auto fast_ptr = head->next;

        while (true) {
            if (fast_ptr->next == nullptr)
                break;
            if (fast_ptr->next->next == nullptr)
                break;

            if (hasCycle = fast_ptr == slow_ptr; hasCycle)
                break;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }

        return hasCycle;
    }

    bool hasCycle(ListNode* head) {
        auto slow_ptr = head;
        auto fast_ptr = head;

        while (fast_ptr && fast_ptr->next) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;

            if (slow_ptr == fast_ptr) [[unlikely]]
                return true;
        }

        return false;
    }
};

// --------- testcases ---------

int main() {
    Solution sol;

    // Define Test Cases: {values, pos, expected}
    struct TestCase {
        std::vector<int> values;
        int pos;
        bool expected;
        std::string name;
    };

    std::vector<TestCase> cases = {{{3, 2, 0, -4}, 1, true, "Example 1: Standard cycle"},
                                   {{1, 2}, 0, true, "Example 2: Two nodes, cycle to head"},
                                   {{1}, -1, false, "Example 3: Single node, no cycle"},
                                   {{}, -1, false, "Edge Case: Empty list"}};

    for (const auto& [vals, pos, expected, name] : cases) {
        ListNode* head = createList(vals, pos);
        bool result = sol.hasCycle(head);

        std::cout << "[" << name << "] "
                  << "Result: " << std::boolalpha << result << " | Expected: " << expected << " -> "
                  << (result == expected ? "PASS" : "FAIL") << std::endl;
    }

    return 0;
}