#include <iostream>
using namespace std;

// Structure of a node
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to check if two linked lists are identical
bool areIdentical(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data)
            return false; // data mismatch

        head1 = head1->next;
        head2 = head2->next;
    }

    // Both should end at the same time
    return (head1 == nullptr && head2 == nullptr);
}

// Helper function to insert a new node at the end
void append(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Helper function to print the list (just for testing)
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    // Example 1
    append(head1, 1);
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);
    append(head1, 5);

    append(head2, 1);
    append(head2, 2);
    append(head2, 3);
    append(head2, 4);
    append(head2, 5);

    cout << "LinkedList1: ";
    printList(head1);
    cout << "LinkedList2: ";
    printList(head2);

    if (areIdentical(head1, head2))
        cout << "Output: true" << endl;
    else
        cout << "Output: false" << endl;

    return 0;
}
