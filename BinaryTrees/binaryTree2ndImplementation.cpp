// Binary Tree in C++

#include <stdlib.h>
#include <iostream>
using namespace std;

// Structure to represent a node in the binary tree
struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Function to create a new node with the given data
struct node *newNode(int data) {
  // Allocating memory for the new node
  struct node *node = (struct node *)malloc(sizeof(struct node));

  // Assigning the data to the new node
  node->data = data;

  // Initializing left and right child pointers as NULL
  node->left = NULL;
  node->right = NULL;

  // Returning the newly created node
  return (node);
}

// Function to traverse the binary tree in Preorder
void traversePreOrder(struct node *temp) {
  // Base condition: If the current node is not NULL
  if (temp != NULL) {
    // Display the data of the current node
    cout << " " << temp->data;
    // Traverse the left subtree in Preorder
    traversePreOrder(temp->left);
    // Traverse the right subtree in Preorder
    traversePreOrder(temp->right);
  }
}

// Function to traverse the binary tree in Inorder
void traverseInOrder(struct node *temp) {
  // Base condition: If the current node is not NULL
  if (temp != NULL) {
    // Traverse the left subtree in Inorder
    traverseInOrder(temp->left);
    // Display the data of the current node
    cout << " " << temp->data;
    // Traverse the right subtree in Inorder
    traverseInOrder(temp->right);
  }
}

// Function to traverse the binary tree in Postorder
void traversePostOrder(struct node *temp) {
  // Base condition: If the current node is not NULL
  if (temp != NULL) {
    // Traverse the left subtree in Postorder
    traversePostOrder(temp->left);
    // Traverse the right subtree in Postorder
    traversePostOrder(temp->right);
    // Display the data of the current node
    cout << " " << temp->data;
  }
}

int main() {
  // Creating the binary tree
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);

  // Traversing and displaying the tree in different orders
  cout << "Preorder traversal: ";
  traversePreOrder(root);
  cout << "\nInorder traversal: ";
  traverseInOrder(root);
  cout << "\nPostorder traversal: ";
  traversePostOrder(root);

  // Exiting the program
  return 0;
}
