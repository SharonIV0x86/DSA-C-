// Tree traversal in C++

#include <iostream>
using namespace std;

// Structure to represent a node in the binary tree
struct Node {
  int data;
  struct Node *left, *right;

  // Constructor to initialize a node with given data
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

// Preorder traversal: Root->Left->Right
void preorderTraversal(struct Node* node) {
  // Base case: If the current node is NULL, return
  if (node == NULL)
    return;

  // Print the data of the current node
  cout << node->data << "->";

  // Recursive call to traverse the left subtree
  preorderTraversal(node->left);

  // Recursive call to traverse the right subtree
  preorderTraversal(node->right);
}

// Postorder traversal: Left->Right->Root
void postorderTraversal(struct Node* node) {
  // Base case: If the current node is NULL, return
  if (node == NULL)
    return;

  // Recursive call to traverse the left subtree
  postorderTraversal(node->left);

  // Recursive call to traverse the right subtree
  postorderTraversal(node->right);

  // Print the data of the current node
  cout << node->data << "->";
}

// Inorder traversal: Left->Root->Right
void inorderTraversal(struct Node* node) {
  // Base case: If the current node is NULL, return
  if (node == NULL)
    return;

  // Recursive call to traverse the left subtree
  inorderTraversal(node->left);

  // Print the data of the current node
  cout << node->data << "->";

  // Recursive call to traverse the right subtree
  inorderTraversal(node->right);
}

int main() {
  // Creating the binary tree
  struct Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);
  root->right->right = new Node(7);
  root->right->left = new Node(8);

  // Performing inorder traversal
  cout << "Inorder traversal: ";
  inorderTraversal(root);

  // Performing preorder traversal
  cout << "\nPreorder traversal: ";
  preorderTraversal(root);

  // Performing postorder traversal
  cout << "\nPostorder traversal: ";
  postorderTraversal(root);

  return 0;
}
