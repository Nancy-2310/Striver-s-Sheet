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
   void deleteNode(ListNode* node) {
        if(node -> next == nullptr ) node -> val = 0;
        else {
            node -> val = node -> next -> val;
            node -> next = node -> next -> next;
        }
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
    
    Solution solution;  // Add this line to declare the Solution object
    
    int valueToDel;
    cout << "Enter value of node to be deleted: ";
    cin >> valueToDel;

    // Find the node with the specified value
    ListNode* nodetoDel = head;
    while (nodetoDel && nodetoDel->val != valueToDel) {
        nodetoDel = nodetoDel->next;
    }

    if (nodetoDel) {
        solution.deleteNode(nodetoDel);
        cout << "Node with value " << valueToDel << " deleted." << endl;
    } else {
        cout << "Node with value " << valueToDel << " not found." << endl;
    }

    printLinkedList(head);
    return 0;
}
