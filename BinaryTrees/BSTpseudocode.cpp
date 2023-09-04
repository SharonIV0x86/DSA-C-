

1. Search
If root == NULL 
    return NULL;
If number == root->data 
    return root->data;
If number < root->data 
    return search(root->left)
If number > root->data 
    return search(root->right)

2. Inser Operation
If node == NULL 
    return createNode(data)
if (data < node->data)
    node->left  = insert(node->left, data);
else if (data > node->data)
    node->right = insert(node->right, data);  
return node;

Operation
					Best Case Complexity
					Average Case Complexity
					Worst Case Complexity
			

			
				Search
					O(log n)
					O(log n)
					O(n)
			

			
				Insertion
					O(log n)
					O(log n)
					O(n)
			

			
				Deletion
					O(log n)
					O(log n)
					O(n)