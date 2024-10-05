#include<iostream>
using namespace std;

struct Node{
    int key;
    Node* l;
    Node* r;
    Node(int value){
        this -> key = value;
        this -> r = NULL;
        this -> l = NULL;
    }
};

void insertBST(Node* &root, int value){
    if(root == NULL){
        root = new Node(value);
        return;
    }
    if(root -> key < value){
        insertBST(root -> r, value);
    } else {
        insertBST(root ->l, value);
    }
}

int gotoLR(Node* &root, string &s){  
    if(root == NULL){
        return -123123;  
    }
    if(s.empty()){
        return 1;
    }
    char direction = s[0];
    s.erase(0, 1);

    if(direction == 'L'){
        return gotoLR(root -> l, s);
    } else if(direction == 'R'){
        return gotoLR(root -> r, s);
    } else {
        return -123123;
    }
}


// void printBST(Node* &root){
//     if(root ==NULL){
//         return;
//     }
//     printBST(root -> l);
//     cout << root ->key << " ";
//     printBST(root ->r);
// }

int main(){
    int n, m;
    cin >> n >> m;
    Node* root = NULL;
    for(int i =0; i<n; i++){
        int val;
        cin >> val;
        insertBST(root ,val);
    }
    for(int i=0; i<m; i++){
        string path;
        cin >> path;
        if(gotoLR(root, path)==1){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}