#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    Node* l;
    Node* r;
    Node(int key) {
        this->key = key;
        this->l = NULL;
        this->r = NULL;
    }
};

struct BST {
    Node *root;
    vector<int> levels;

    BST() {
        this->root = NULL;
    }

    Node* insert(Node* node, int value, int level) {
        if(!node) {
            if(level >= levels.size()) {
                levels.push_back(value);
            } else {
                levels[level] += value;
            }
            return new Node(value);
        }
        if(value < node->key) {
            node->l = insert(node->l, value, ++level);
        } else if(value > node->key) {
            node->r = insert(node->r, value, ++level);
        }
        return node;
    }

    void insert(int value) {
        int level = 0;
        root = insert(root, value, level);
    }

    void solve() {
        cout << levels.size() << "\n";
        for(int i = 0; i < levels.size(); i++) {
            cout << levels[i] << " ";
        }
    }
};

int main() {
    int n;
    cin >> n;
    BST *tree = new BST();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree->insert(x);
    }
    tree->solve();
}