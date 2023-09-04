#include <iostream>
#include <pthread.h>

using namespace std;

// Structure for a node in the Binary Search Tree
struct node
{
    int key;
    struct node *left, *right;
};

// Create a new node with the given key
struct node *newNode(int item)
{
    // Allocate memory for the new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    // Set the key and initialize left and right child pointers
    temp->key = item;
    temp->left = temp->right = NULL;
    
    return temp;
}

// Inorder Traversal of the Binary Search Tree
void inorder(struct node *root)
{
    if (root != NULL)
    {
        // Traverse left subtree
        inorder(root->left);
        
        // Print the current node's key
        cout << root->key << " -> ";
        
        // Traverse right subtree
        inorder(root->right);
    }
}

// Insert a node in the Binary Search Tree
struct node *insert(struct node *node, int key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);
    
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key); // Insert in the left subtree if the key is smaller
    else
        node->right = insert(node->right, key); // Insert in the right subtree if the key is greater
    
    return node;
}

// Find the inorder successor (minimum value) in a subtree
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    
    // Find the leftmost leaf node
    while (current && current->left != NULL)
        current = current->left;
    
    return current;
}

// Delete a node from the Binary Search Tree
struct node *deleteNode(struct node *root, int key)
{
    // Return if the tree is empty
    if (root == NULL)
        return root;
    
    // Find the node to be deleted in the left or right subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key); // Delete in the left subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key); // Delete in the right subtree
    else
    {
        // If the node is with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
        // If the node has two children
        struct node *temp = minValueNode(root->right);
        
        // Place the inorder successor's key in the current node
        root->key = temp->key;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    
    return root;
}

// Driver code
int main()
{
    struct node *root = NULL;
    
    // Inserting elements into the Binary Search Tree
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    
    cout << "Inorder traversal: ";
    inorder(root);
    
    cout << "\nAfter deleting 10\n";
    root = deleteNode(root, 10);
    cout << "Inorder traversal: ";
    inorder(root);
    
    return 0;
}
