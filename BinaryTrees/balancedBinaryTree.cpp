// Checking if a binary tree is height balanced in C++

#include <iostream>
using namespace std;

#define bool int

class node
{
public:
    int item;
    node *left;
    node *right;
};

// Create a new node
node *newNode(int item)
{
    node *Node = new node();
    Node->item = item;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

// Check height balance
bool checkHeightBalance(node *root, int *height)
{
    // Check for emptiness
    int leftHeight = 0, rightHeight = 0;

    int l = 0, r = 0;

    // Base case: an empty tree is height balanced
    if (root == NULL)
    {
        *height = 0;
        return 1;
    }

    // Recursively check the height balance of the left and right subtrees
    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);

    // Update the height of the current node as the maximum height of the left and right subtrees, plus 1
    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    // Check if the height difference between the left and right subtrees is more than 1
    if (std::abs(leftHeight - rightHeight >= 2))
        return 0;
    else
        return l && r;
}

int main()
{
    int height = 0;

    // Create a binary tree
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Check if the tree is height balanced and print the result
    if (checkHeightBalance(root, &height))
        cout << "The tree is balanced";
    else
        cout << "The tree is not balanced";
}

/* A balanced binary tree, also referred to as a height-balanced binary tree,
is defined as a binary tree in which the height of the left and right subtree of any node differ by not more than 1.*/
