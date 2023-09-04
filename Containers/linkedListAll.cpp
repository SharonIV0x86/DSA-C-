#include <iostream>

// Structure representing a node in the linked list
struct Node {
    int data;         // Data stored in the node
    Node* next;       // Pointer to the next node
};

// Linked list class
class LinkedList {
private:
    Node* head;       // Pointer to the head of the linked list

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the front of the linked list
    void insertFront(int value) {
        Node* newNode = new Node;        // Create a new node
        newNode->data = value;           // Assign the given value to the data field of the new node
        newNode->next = head;            // Set the next pointer of the new node to the current head
        head = newNode;                  // Make the new node the new head of the linked list
    }

    // Function to insert a new node at the back of the linked list
    void insertBack(int value) {
        Node* newNode = new Node;        // Create a new node
        newNode->data = value;           // Assign the given value to the data field of the new node
        newNode->next = nullptr;         // Set the next pointer of the new node to nullptr

        if (head == nullptr) {
            head = newNode;              // If the linked list is empty, make the new node the head
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;     // Traverse to the last node in the linked list
        }
        current->next = newNode;         // Set the next pointer of the last node to the new node
    }

    // Function to insert a new node after the first occurrence of a specified key
    void insertAfter(int key, int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {   // If the current node's data matches the key
                Node* newNode = new Node; // Create a new node
                newNode->data = value;    // Assign the given value to the data field of the new node
                newNode->next = current->next;     // Set the next pointer of the new node to the next node of the current node
                current->next = newNode;   // Set the next pointer of the current node to the new node
                return;
            }
            current = current->next;     // Move to the next node
        }
        std::cout << "Key not found in the linked list." << std::endl;
    }

    // Function to delete the first occurrence of a specified key from the linked list
    void deleteNode(int key) {
        if (head == nullptr) {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->data == key) {
            Node* temp = head;          // Store the head node in a temporary variable
            head = head->next;          // Move the head to the next node
            delete temp;                // Delete the temporary variable (previously the head)
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == key) {   // If the next node's data matches the key
                Node* temp = current->next;     // Store the next node in a temporary variable
                current->next = current->next->next;   // Set the next pointer of the current node to the node after the next node
                delete temp;                    // Delete the temporary variable (previously the node to be deleted)
                return;
            }
            current = current->next;     // Move to the next node
        }
        std::cout << "Key not found in the linked list." << std::endl;
    }

    // Function to search for a specified key in the linked list
    bool search(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return true;            // Key found
            }
            current = current->next;    // Move to the next node
        }
        return false;                   // Key not found
    }

    // Function to display the elements of the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";   // Print the data of the current node
            current = current->next;             // Move to the next node
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList linkedList;

    // Insert nodes at the front and back of the linked list
    linkedList.insertFront(3);
    linkedList.insertFront(2);
    linkedList.insertFront(1);
    linkedList.insertBack(4);

    // Insert a node after the first occurrence of a specified key
    linkedList.insertAfter(2, 5);

    linkedList.display();  // Output: 1 2 5 3 4

    // Search for keys in the linked list
    std::cout << "Searching for key 3: " << (linkedList.search(3) ? "Found" : "Not found") << std::endl;  // Output: Found
    std::cout << "Searching for key 6: " << (linkedList.search(6) ? "Found" : "Not found") << std::endl;  // Output: Not found

    // Delete nodes with specified keys from the linked list
    linkedList.deleteNode(2);
    linkedList.deleteNode(4);

    linkedList.display();  // Output: 1 5 3

    return 0;
}
