#include<iostream>
using namespace std;
 
// Structure to represent a node in the binary tree
struct bintree_node{
    bintree_node *left;
    bintree_node *right;
    int data;
};

// Class for Binary Search Tree
class bst{
    bintree_node *root;
    public:
    bst(){
        root=NULL;
    }
    
    // Function to check if the tree is empty
    int isempty() {
        return(root==NULL);
    }
    
    // Function to insert a new element in the tree
    void insert(int item);
    
    // Function to display the binary tree
    void displayBinTree();
    
    // Function to recursively print the binary tree
    void printBinTree(bintree_node *);
};

// Function to insert a new element in the tree
void bst::insert(int item){
    // Create a new node
    bintree_node *p=new bintree_node;
    bintree_node *parent;
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    parent=NULL;
    
    // If the tree is empty, make the new node as the root
    if(isempty())
        root=p;
    else{
        bintree_node *ptr;
        ptr=root; // Traversing from the root node
        
        // Finding the appropriate position to insert the new element
        while(ptr!=NULL){
            parent=ptr;
            if(item>ptr->data)        
                ptr=ptr->right;
            else
                ptr=ptr->left;
        }   
        
        // Inserting the new element at the appropriate position
        if(item<parent->data)
            parent->left=p;
        else
            parent->right=p;
    }
}

// Function to display the binary tree
void bst::displayBinTree(){
    printBinTree(root);
}

// Function to recursively print the binary tree
void bst::printBinTree(bintree_node *ptr){
    // Base case: If the current node is NULL, return
    if(ptr!=NULL){
        // Recursive call to print the left subtree
        printBinTree(ptr->left);
        
        // Print the data of the current node
        cout<<" "<<ptr->data<<" "; 
        
        // Recursive call to print the right subtree
        printBinTree(ptr->right);
    }
}

int main(){
    bst b;
    
    // Inserting elements into the binary tree
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30); 
    
    cout<<"Binary tree created: "<<endl;
    
    // Displaying the binary tree
    b.displayBinTree(); 
    
    return 0;
}
