#1) In order: In this traversal technique, we traverse the left subtree first till there are no more nodes in the left subtree. 
After this, we visit the root node and then proceed to traverse the right subtree until there are no more nodes to traverse in the right subtree. 
Thus the order of inOrder traversal is left->root->right.

#2) Pre-order: For the preorder traversal technique, we process the root node first, then we traverse the entire left subtree, 
and finally, we traverse the right subtree. Hence the order of preorder traversal is root->left->right.

#3) Post-order: In the post-order traversal technique, we traverse the left subtree, then the right subtree, 
and finally the root node. The order of traversal for the postorder technique is left->right->root.

If n is the root node and ‘l’ and ’r’ are left and right nodes of the tree respectively, then the tree traversal algorithms are as follows:

In order (lnr) algorithm: Example: For the binary tree (1 is the root, 2 and 3 are its children): 2 - 1 - 3.

    Traverse left subtree using inOrder(left- Subtree).
    Visit the root node(n).
    Traverse right subtree using inOrder(right- subtree).
    Left subtree -> root -> right subtree

Preorder (nlr) algorithm:Example: For the binary tree (1 is the root, 2 and 3 are its children): 1 - 2 - 3.

    Visit the root node(n).
    Traverse left subtree using preorder(left-subtree).
    Traverse the right subtree using preorder(right-subtree).

Postorder (lrn) algorithm:Example: For the binary tree (1 is the root, 2 and 3 are its children): 2 - 3 - 1.

    Traverse left subtree using postOrder(left-subtree).
    Traverse the right subtree using postOrder(right-subtree).
    Visit the root node(n).
