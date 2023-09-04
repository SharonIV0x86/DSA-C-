
// Checking if a binary tree is a perfect binary tree in C++

#include <iostream>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

// Function to calculate the depth of a binary tree
int depth(Node *node)
{
    int d = 0;
    while (node != NULL)
    {
        d++;
        node = node->left;
    }
    return d;
}

// Recursive function to check if a binary tree is perfect
bool isPerfectR(struct Node *root, int d, int level = 0)
{
    // If the current node is NULL, it is considered a valid node
    if (root == NULL)
        return true;

    // If a leaf node is encountered, check if it is at the expected level
    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    // If a node has only one child, it is not a perfect binary tree
    if (root->left == NULL || root->right == NULL)
        return false;

    // Recursively check the left and right subtrees
    return isPerfectR(root->left, d, level + 1) &&
           isPerfectR(root->right, d, level + 1);
}

// Function to check if a binary tree is perfect
bool isPerfect(Node *root)
{
    // Calculate the depth of the binary tree
    int d = depth(root);
    // Call the recursive helper function to check if it is perfect
    return isPerfectR(root, d);
}

// Function to create a new node with a given key
struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

// Main function
int main()
{
    struct Node *root = NULL;
    // Create a sample binary tree
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    // Check if the tree is perfect and print the result
    if (isPerfect(root))
        cout << "The tree is a perfect binary tree\n";
    else
        cout << "The tree is not a perfect binary tree\n";
}

/*A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level.
Recursively, a perfect binary tree can be defined as:

    If a single node has no children, it is a perfect binary tree of height h = 0,
    If a node has h > 0, it is a perfect binary tree if both of its subtrees are of height h - 1 and are non-overlapping.*/
