#include <iostream>
using namespace std;

struct Node {
    string s;
    Node* next;

    Node(string s) {
        this->s = s;
        this->next = nullptr;
    }
};

Node* cyclicShift(Node* head, int k, int n) {
    k = k % n;
    if (k == 0 || head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* cur = head;
    Node* tail = nullptr;

    while (cur->next != nullptr) {
        cur = cur->next;
    }
    tail = cur;
    while (k--) {
        Node* tmp = head->next;
        tail->next = head;
        head->next = nullptr;
        tail = head;
        head = tmp;
    }
    return head;  
}
void answer(Node* head) {
    Node* cur = head;
    while (cur != nullptr) {
        cout << cur->s << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    Node* head = nullptr;
    Node* cur = nullptr;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (i == 0) {
            head = new Node(s);  
            cur = head;
        } else {
            cur->next = new Node(s);  
            cur = cur->next;
        }
    }

    head = cyclicShift(head, k, n);
    answer(head);
    return 0;
}