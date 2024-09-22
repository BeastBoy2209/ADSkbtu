#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* nxt = nullptr;
    Node(int x) : value(x), nxt(nullptr) {}
    Node(int x, Node* next) : value(x), nxt(next) {}
};

struct LL {
    Node *head = nullptr;

    bool LL_empty() {
        return head == nullptr;
    }

    void insert_tail(int value) {
        Node *new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node *cur = head;
            while (cur->nxt != nullptr) {
                cur = cur->nxt;
            }
            cur->nxt = new_node;
        }
    }

    void remove_every_second() {
        if (head == nullptr || head->nxt == nullptr) return;
        
        Node *cur = head;
        Node *prev = nullptr;

        int pos = 0;
        while (cur != nullptr) {
            if (pos % 2 == 1) {
                prev->nxt = cur->nxt;
                delete cur;
                cur = prev->nxt; 
            } else {
                prev = cur;
                cur = cur->nxt;
            }
            pos++;
        }
    }

    void output() {
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur->value;
            if (cur->nxt != nullptr) cout << " ";
            cur = cur->nxt;
        }
        cout << endl;
    }
};

int main() {
    int N;
    cin >> N;
    LL list;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        list.insert_tail(value);
    }

    list.remove_every_second();
    list.output();

    return 0;
}