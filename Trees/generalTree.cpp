#include <iostream>
using namespace std;
 
//declaration for new tree node
struct node { 
    int data; 
    struct node *left; 
    struct node *right; 
}; 
   
//allocates new node 
struct node* newNode(int data) { 
    // declare and allocate new node  
    struct node* node = new struct node(); 
   
    node->data = data;    // Assign data to this node
   
    // Initialize left and right children as NULL 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 
   //max nodes == 2 to the power level L!!!
   // max nodes in a tree of height H is 2 to the power H - 1.
   // for n nodes minimum possible height or minimum number of levels are LOG2 (N+1)
   //A binary tree with L leaves has at leat
int main() { 
    /*create root node*/
    struct node *rootNode = newNode(10);  
    
    // print the root element of the tree
    cout<<"General tree created is as follows:"<<endl;
    cout<<"\t\t\t "<<rootNode->data<<endl;

    // create left and right child nodes of rootNode
    rootNode->left = newNode(20); 
    rootNode->right = newNode(30); 

    // print the elements of the left and right child nodes
    cout<<"\t\t\t"<<rootNode->left->data<<"  "<<rootNode->right->data;
    cout<<endl;

    // create a left child node of rootNode's left child node
    rootNode->left->left  = newNode(40); 
    cout<<"\t\t\t/"<<endl;
    cout<<"\t\t      "<<rootNode->left->left->data;
    
    return 0; 
}
