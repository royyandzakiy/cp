#include <bits/stdc++.h>
using namespace std;

// implementation
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {
    }
};

// use 3 pointers, prev, curr, temp_next
// repeat until nullptr (store temp_next, flip next to prev, move forward)
Node *reverseLinkedList(Node *head) {
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr) {
        // store temp
        Node *temp_next = curr->next;

        // flip
        curr->next = prev;

        // move forward
        prev = curr;
        curr = temp_next;
    }

    return prev; // cause curr would've been nullptr
}

void printList(Node *head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : " -> NULL");
        head = head->next;
    }
    cout << endl;
}

auto main() -> int {
    // 1. Create a linked list: 1 -> 2 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    std::cout << "Original List: ";
    printList(head);

    // 2. Run the solution
    Node *reversedHead = reverseLinkedList(head);

    std::cout << "Reversed List: ";
    printList(reversedHead);

    // 3. Simple cleanup (Manual memory management)
    while (reversedHead) {
        Node *temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}