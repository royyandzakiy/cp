#include <bits/stdc++.h>
using namespace std;

// implementation
struct LinkNode {
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(nullptr) {
    }
};

// use 3 pointers, prev, curr, temp_next
// repeat until nullptr (store temp_next, flip next to prev, move forward)
LinkNode *reverseLinkedList(LinkNode *head) {
    LinkNode *prev = nullptr;
    LinkNode *curr = head;

    while (curr != nullptr) {
        // store next in temp
        LinkNode *temp_next = curr->next;

        // flip
        curr->next = prev;

        // move forward
        prev = curr;
        curr = temp_next;
    }

    return prev; // cause curr would've been nullptr
}

void printList(LinkNode *head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : " -> NULL");
        head = head->next;
    }
    cout << endl;
}

auto main() -> int {
    // 1. Create a linked list: 1 -> 2 -> 3 -> 4
    LinkNode *head = new LinkNode(1);
    head->next = new LinkNode(2);
    head->next->next = new LinkNode(3);
    head->next->next->next = new LinkNode(4);

    std::cout << "Original List: ";
    printList(head);

    // 2. Run the solution
    LinkNode *reversedHead = reverseLinkedList(head);

    std::cout << "Reversed List: ";
    printList(reversedHead);

    // 3. Simple cleanup (Manual memory management)
    while (reversedHead) {
        LinkNode *temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}