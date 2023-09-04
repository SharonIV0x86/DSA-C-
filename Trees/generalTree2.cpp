#include "bits/stdc++.h"

struct node {
    int value;
    n* left;
    n* right;
    node(int val){
        value = val;
        left = NULL;
        right = NULL;
    }

}typedef n;


using namespace std;
int main(){
    n* rootNode = new node(10);
    rootNode->left = new node(20);
    rootNode->right = new node(30);

    rootNode->left->left = new node(40);
    rootNode->left->right = new node(50);
}