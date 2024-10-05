#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

struct Node {
    int key;
    Node* l;
    Node* r;
    Node(int value) {
        this->key = value;
        this->l = NULL;
        this->r = NULL;
    }
};
Node* root = NULL;

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (root->key < value) {
        root->r = insert(root->r, value);
    } else if (root->key > value) {
        root->l = insert(root->l, value);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) {
        return;
    }
    inorder(root->l);
    v.push_back(root->key);
    inorder(root->r);
}

void preorder(Node* root) {
    if (!root) {
        return;
    }
    cout << root->key << " ";
    preorder(root->l);
    preorder(root->r);
}

Node* solve(int l, int r) {
    if (r < l) {
        return NULL;
    }
    int mid = l + (r - l) / 2;
    Node* root = new Node(v[mid]);
    root->l = solve(l, mid - 1);
    root->r = solve(mid + 1, r);
    return root;
}

int main() {
    int n;
    cin >> n;
    int size = pow(2, n) - 1;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    inorder(root);
    root = solve(0, size - 1);
    preorder(root);
}