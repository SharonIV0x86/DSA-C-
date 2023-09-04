
#include <iostream>
using namespace std;

// Structure to represent a node in the binary tree
struct Node {
  int key;
  struct Node *left, *right;
};

// Function to create a new node with the given key
struct Node *newNode(char k) {
  // Allocating memory for the new node
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  
  // Assigning the key to the new node
  node->key = k;
  
  // Initializing left and right child pointers as NULL
  node->right = node->left = NULL;
  
  return node;
}

// Function to check if a binary tree is a full binary tree
bool isFullBinaryTree(struct Node *root) {
  
  // Checking if the tree is empty
  if (root == NULL)
    return true;

  // Checking if the node is a leaf node (no children)
  if (root->left == NULL && root->right == NULL)
    return true;

  // Checking if the node has both left and right children
  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  // If the above conditions are not met, it is not a full binary tree
  return false;
}

int main() {
  struct Node *root = NULL;
  
  // Creating a binary tree
  root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(7);

  // Checking if the tree is a full binary tree
  if (isFullBinaryTree(root))
    cout << "The tree is a full binary tree\n";
  else
    cout << "The tree is not a full binary tree\n";
}





// A full Binary tree is a special type of binary tree in which every parent node/internal node has either two or no children.

// It is also known as a proper binary tree.