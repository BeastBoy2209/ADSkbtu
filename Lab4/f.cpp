#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node *l, *r;
    Node(int key) {
        this->key = key;
        this->l = NULL;
        this->r = NULL;
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

    void preorder(Node *cur) {
        if(!cur) {
            return;
        }
        cout << cur->key << " ";
        preorder(cur->l);
        preorder(cur->r);
    }

    int solve() {
        int cnt = 0;
        queue <Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *cur = q.front();
            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
            if(cur->l && cur->r) {
                cnt++;
            }
            q.pop();
        }
        return cnt;
    }
};

int main() {
    int n;
    cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree->root = tree->insert(tree->root, x);
    }
    cout << tree->solve() << endl;

    return 0;
}