#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = NULL;
        ListNode* next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = curr;
            curr = head;
            head = next;
        }
        return curr;
    }
};

// Function to create a linked list from an array of integers
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode();
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);
    cout << "Original Linked List: ";
    printLinkedList(head);

    Solution solution;
    ListNode* reversed = solution.reverseList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(reversed);

    return 0;
}
