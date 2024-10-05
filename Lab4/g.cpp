#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node *l, *r;
    Node(int key) {
        this->key = key;
        this->l = this->r = nullptr;
    }
};

struct BST {
    Node *root;

    Node* insert(Node *cur, int key) {
        if(!cur) {
            return new Node(key);
        }
        if(cur->key < key) {
            cur->r = insert(cur->r, key);
        } else if(cur->key > key) {
            cur->l = insert(cur->l, key);
        }
        return cur;
    }

    void inorder(Node *cur) {
        if(!cur) {
            return;
        }
        inorder(cur->l);
        cout << cur->key << " ";
        inorder(cur->r);
    }

    int maxDepth(Node *node) {
        if(!node) {
            return 0;
        }
        int leftDepth = maxDepth(node->l);
        int rightDepth = maxDepth(node->r);
        return max(leftDepth, rightDepth) + 1;
    }

    int maxDistance() {
        queue <Node*> q;
        int result = -1;
        q.push(root);
        while(!q.empty()) {
            Node *cur = q.front();
            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
            int distance = maxDepth(q.front()->l) + maxDepth(q.front()->r) + 1;
            result = max(result, distance);
            q.pop();
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    BST *bst = new BST();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst->root = bst->insert(bst->root, x);
    }
    cout << bst->maxDistance() << endl;
    return 0;
}