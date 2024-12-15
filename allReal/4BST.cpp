#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int value){
        this -> key = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void insert(Node* &root, int value){
    if(root == NULL){
        root = new Node(value);
        return;
    }
    if(root -> key > value){
        insert(root -> right, value);
    } else { 
        insert(root -> left, value);
    }
}

void print(Node* &root){
    if(root == NULL){
        return;
    }
    print(root -> left);
    cout << root -> key << " ";
    print(root ->right);
}

int main(){
    int n; cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        insert(root, x);
    }

    print(root);
}