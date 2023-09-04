#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Expression tree node
class TreeNode {
public:
    string value; // Value or operator
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child
};

// Function to check if a character is an operand
bool isOperand(char c) {
    return isdigit(c);
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to build the expression tree
TreeNode* buildExpressionTree(const string& expression) {
    stack<TreeNode*> stk;

    for (char c : expression) {
        if (isOperand(c)) {
            TreeNode* newNode = new TreeNode;
            newNode->value = c;
            newNode->left = newNode->right = nullptr;
            stk.push(newNode);
        } else if (isOperator(c)) {
            TreeNode* newNode = new TreeNode;
            newNode->value = c;
            newNode->right = stk.top();
            stk.pop();
            newNode->left = stk.top();
            stk.pop();
            stk.push(newNode);
        }
    }

    return stk.top();
}

// Recursive function to evaluate the expression tree
int evaluateExpressionTree(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
        // Base case: leaf node (operand)
        return stoi(root->value); // Convert string to integer
    }

    // Evaluate the left and right subtrees
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Perform the operation based on the operator
    if (root->value == "+") {
        return leftValue + rightValue;
    } else if (root->value == "-") {
        return leftValue - rightValue;
    } else if (root->value == "*") {
        return leftValue * rightValue;
    } else if (root->value == "/") {
        return leftValue / rightValue;
    }

    return 0; // Invalid operator
}

int main() {
    string expression = "((3+4)*(5-2))";
    TreeNode* root = buildExpressionTree(expression);
    int result = evaluateExpressionTree(root);
    cout << "Expression: " << expression << endl;
    cout << "Result: " << result << endl;

    return 0;
}

// #include <iostream>

// struct Node {
//     int data;
//     Node* next;
// };

// void insertAtPosition(Node** head, int position, int value) {
//     Node* newNode = new Node;
//     newNode->data = value;
//     newNode->next = nullptr;
    
//     if (position == 1) {
//         newNode->next = *head;
//         *head = newNode;
//         return;
//     }
    
//     Node* current = *head;
//     for (int i = 1; i < position - 1 && current != nullptr; ++i) {
//         current = current->next;
//     }
    
//     if (current == nullptr) {
//         std::cout << "Invalid position." << std::endl;
//         return;
//     }
    
//     newNode->next = current->next;
//     current->next = newNode;
// }

// void displayLinkedList(Node* head) {
//     Node* current = head;
//     while (current != nullptr) {
//         std::cout << current->data << " ";
//         current = current->next;
//     }
//     std::cout << std::endl;
// }

// int main() {
//     Node* head = nullptr;  // Empty linked list

//     // Insert nodes
//     insertAtPosition(&head, 1, 5); // Insert at the beginning
//     insertAtPosition(&head, 2, 7); // Insert at position 2
//     insertAtPosition(&head, 3, 9); // Insert at position 3
//     insertAtPosition(&head, 4, 11); // Insert at position 4

//     // Display the linked list
//     displayLinkedList(head);

//     return 0;
// }

// // #include <iostream>

// // class Node {
// // public:
// //     int data;
// //     Node* next;

// //     Node(int value) : data(value), next(nullptr) {}

// //     Node* setData(int value) {
// //         data = value;
// //         // return this;
// //     }

// //     Node* setNext(Node* node) {
// //         next = node;
// //         // return this;
// //     }
// //     Node* lmao();
// //     void printData() {
// //         std::cout << "Data: " << data << std::endl;
// //     }
// // };

// // int main() {
// //     Node* first = new Node(1);
// //     Node* second = new Node(2);
// //     Node* third = new Node(3);

// //     first->setData(10)->setNext(second)->setData(20)->setNext(third);
// // /*The first call to setData(10) returns a pointer to the first object. Then, the setNext(second) call is made on that object, and so on. This chaining pattern allows you to perform a sequence of operations on the same object in a concise manner.
// // In summary, return this returns a pointer to the current object instance, not the function parameter Node* node.*/
// //     first->printData();  // Output: Data: 10
// //     first->next->printData();  // Output: Data: 20
// //     first->next->next->printData();  // Output: Data: 3

// //     delete third;
// //     delete second;
// //     delete first;

// //     return 0;
// // }
