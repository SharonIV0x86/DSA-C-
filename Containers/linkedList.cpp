#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int main() {
    // Initialize nodes
    Node* head = nullptr;
    Node* one = nullptr;
    Node* two = nullptr;
    Node* three = nullptr;

    // Allocate memory0
    one = new Node(1);
    two = new Node(2);
    three = new Node(3);

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = nullptr;

    // Save address of first node in head
    head = one;

    // Access and print the data values
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Deallocate memory
    delete one;
    delete two;
    delete three;

    return 0;
}
