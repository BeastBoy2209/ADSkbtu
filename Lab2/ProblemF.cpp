#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
    Node() {}
};

void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_node;
}

void insertAt(Node** head_ref, int position, int new_data) {
    Node* new_node = new Node(new_data);
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        new_node->next = current->next;
        current->next = new_node;
    } else {
        current->next = new_node;
    }
}

void print(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    Node *head = nullptr;
    int val;

    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(&head, val);  
    }

    int new_data, position;
    cin >> new_data >> position;

    insertAt(&head, position, new_data);
    print(head);

    return 0;
}