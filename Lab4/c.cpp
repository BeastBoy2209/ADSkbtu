#include<iostream>
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
    private:
        Node *root;

        Node* _insert(Node *cur, int value) {
            if (!cur) {
                return new Node(value);
            }
            if (value > cur->key) {
                cur->r = _insert(cur->r, value);
            } else if (value < cur->key) {
                cur->l = _insert(cur->l, value);
            }
            return cur;
        }

        Node* _search(Node *cur, int target) {
            if (!cur) {
                return NULL;
            }
            if (cur->key == target) {
                return cur;
            } else if (cur->key > target) {
                return _search(cur->l, target);
            } else {
                return _search(cur->r, target);
            }
        }

        void _preorder(Node *node) {
            if (!node) {
                return;
            }
            cout << node->key << " ";
            _preorder(node->l);
            _preorder(node->r);
        }

    public:
        BST() {
            this->root = NULL;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        Node* search(int target) {
            return _search(root, target);
        }

        void preorder(Node *node) {
            _preorder(node);
        }
};

int main() {
    int n, target;
    cin >> n;
    BST *tree = new BST();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree->insert(x);
    }
    cin >> target;
    Node *targetNode = tree->search(target);
    tree->preorder(targetNode);
}