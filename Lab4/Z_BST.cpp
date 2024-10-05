// BST - binary search tree
#include<iostream>
#include<vector>
using namespace std;

struct Node {
    int key;
    Node *l;
    Node *r;
    Node(int value){
        this->key = value;
        this->l = NULL;
        this->r = NULL;
    }
};

void insert(Node* &root, int key){
    if(root == NULL){
        root = new Node(key);
        return;
    }
    if(root ->key > key) {
        insert(root -> l, key);
    } else {
        insert(root -> r, key);
    }
};

void printBST(Node* root) {
    if(root == NULL) {
        return;
    }
    printBST(root->l);
    cout << root->key << " ";
    printBST(root->r);
}


int main(){
    int n, l;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i<n ; i++){
        int x;
        cin >> x;
        insert(root, x);
    }

    printBST(root);
}