#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node* l;
    Node* r;
    Node(int value) {
        this->key = value;
        this->l =NULL;
        this->r = NULL;
    }
};

struct BST {
    Node *root;
    BST() {
        this->root = NULL;
    }
    Node* insert(Node *cur, int value) {
        if(!cur) {
            return new Node(value);
        }
        return cur;
    }

    void insert(Node *cur, int x, int y, int z) {
        if(!cur) {
            return;
        }
        if(cur->key == x) {
            if(z == 0) {
                cur->l = new Node(y);
                return;
            } else {
                cur->r = new Node(y);
                return;
            }
        }
        insert(cur->l, x, y, z);
        insert(cur->r, x, y, z);
    }

    int solve(Node *cur, int max) {
        queue<Node*> q;
        q.push(cur);
        while(!q.empty()) {
            int size = q.size();
            if(max < size) {
                max = size;
            }
            for(int i = 0; i < size; i++) {
                if(q.front()->l) q.push(q.front()->l);
                if(q.front()->r) q.push(q.front()->r);
                q.pop();
            }
        }
        return max;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void insert(int x, int y, int z) {
        insert(root, x, y, z);
    }

    int solve(int max) {
        return solve(root, max);
    }
};

int main() {
    int n; cin >> n;
    BST *tree = new BST();
    for(int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(i == 0) {
            tree->insert(x);
        }
        tree->insert(x, y, z);
    }
    cout << tree->solve(-1) << "\n";
}