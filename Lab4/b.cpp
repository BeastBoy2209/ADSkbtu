#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int key;
    Node* l;
    Node* r;
    Node(int value){
        this -> key = value;
        this -> l = NULL;
        this -> r = NULL;
    }
};

void insertBST(Node* &root, int value){
    if(root == NULL){
        root = new Node(value);
        return;
    }
    if(root -> key > value){
        insertBST(root -> l, value);
    } 
    else if(root -> key < value){
        insertBST(root -> r, value);
    }
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->l) + countNodes(root->r);
}

int SubTreeCount(Node* root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->key == value) {
        return countNodes(root);
    } 
    else if (value < root->key) {
        return SubTreeCount(root->l, value);
    } 
    else {
        return SubTreeCount(root->r, value);
    }
}

int main(){
    int n, k;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        insertBST(root, x);
    }
    cin >> k;
    cout << SubTreeCount(root, k) << endl;
}