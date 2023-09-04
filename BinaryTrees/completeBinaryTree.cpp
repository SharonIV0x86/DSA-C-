// Checking if a binary tree is a complete binary tree in C++

#include <iostream>

using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

// Create node
struct Node *newNode(char k)
{
    // Allocate memory for a new node
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

// Count the number of nodes in the binary tree
int countNumNodes(struct Node *root)
{
    // Base case: an empty tree has 0 nodes
    if (root == NULL)
        return (0);

    // Recursively count the number of nodes in the left and right subtrees and add 1 for the current node
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the binary tree is a complete binary tree
bool checkComplete(struct Node *root, int index, int numberNodes)
{
    // Check if the tree is empty
    if (root == NULL)
        return true;

    // If the current index exceeds the number of nodes, it is not a complete binary tree
    if (index >= numberNodes)
        return false;

    // Recursively check if the left and right subtrees are complete binary trees
    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main()
{
    struct Node *root = NULL;

    // Construct the binary tree
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    // Count the number of nodes in the binary tree
    int node_count = countNumNodes(root);

    // Starting index for checking completeness is 0
    int index = 0;

    // Check if the binary tree is complete and print the result
    if (checkComplete(root, index, node_count))
        cout << "The tree is a complete binary tree\n";
    else
        cout << "The tree is not a complete binary tree\n";
}
