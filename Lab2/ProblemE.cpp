#include <iostream>
#include <map>
using namespace std;

struct Node {
    string val;
    Node *next;

    Node(string val) {
        this->val = val;
        this->next = nullptr;
    }
    Node() {}
};

void duplicate(Node* head) {
    Node *cur = head;
    Node *prev = nullptr;
    map<string, bool> seen;

    while (cur != nullptr) {
        if (seen[cur->val]) {
            prev->next = cur->next;
        } else {
            seen[cur->val] = true;
            prev = cur;
        }
        cur = cur->next;
    }
}

int getCount(Node* head) {
    Node *cur = head;
    int cnt = 0;
    while (cur != nullptr) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

void push(Node** head_ref, string new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->val << endl;
        cur = cur->next;
    }
}

int main() {
    int n;
    cin >> n;
    Node *head = nullptr;
    string val;

    for (int i = 0; i < n; i++) {
        cin >> val;
        push(&head, val);
    }

    duplicate(head);
    
    int count = getCount(head);
    if (count >= 500) {
        count++;
    }
    
    cout << "All in all: " << count << endl;
    cout << "Students:" << endl;

    print(head);

    return 0;
}