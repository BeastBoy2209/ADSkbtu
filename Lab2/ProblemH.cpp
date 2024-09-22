#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;

    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
};

Node* insert(Node* head, Node* node, int p) {
    if (p == 0) {
        node->next = head;
        head = node;
        return head;
    }
    Node* cur = head;
    int cnt = 0;
    while (cur) {
        if (cnt + 1 == p) {
            node->next = cur->next;
            cur->next = node;
            break;
        }
        cur = cur->next;
        cnt++;
    }
    return head;
}

Node* remove(Node* head, int p) {
    if (head == nullptr) return nullptr;
    if (p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* cur = head;
    Node* prev = nullptr;
    int cnt = 0;
    while (cur) {
        if (cnt == p) {
            prev->next = cur->next;
            delete cur;
            break;
        }
        prev = cur;
        cur = cur->next;
        cnt++;
    }
    return head;
}

Node* replace(Node* head, int p1, int p2) {
    if (p1 == p2) return head;
    Node* cur = head;
    Node* temp = nullptr;
    int cnt = 0;

    while (cur) {
        if (cnt == p1) {
            temp = cur;
            if (cnt == 0) {
                head = head->next;
            } else {
                Node* prev = head;
                for (int i = 0; i < cnt - 1; ++i) {
                    prev = prev->next;
                }
                prev->next = cur->next;
            }
            break;
        }
        cur = cur->next;
        cnt++;
    }

    head = insert(head, temp, p2);
    return head;
}

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << -1 << endl;
        return;
    }
    Node* cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || x <= 0) return head;
    Node* cur = head;
    Node* tail = nullptr;
    int cnt = 0;

    while (cur) {
        tail = cur;
        cur = cur->next;
        cnt++;
    }

    x = x % cnt; // Handle cases where x >= cnt
    if (x == 0) return head;

    cur = head;
    for (int i = 0; i < x - 1; ++i) {
        cur = cur->next;
    }

    Node* new_head = cur->next;
    cur->next = nullptr;
    tail->next = head;
    return new_head;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || x <= 0) return head;
    Node* cur = head;
    Node* tail = nullptr;
    int cnt = 0;

    while (cur) {
        tail = cur;
        cur = cur->next;
        cnt++;
    }

    x = x % cnt; // Handle cases where x >= cnt
    if (x == 0) return head;

    int stop = cnt - x;
    cur = head;
    for (int i = 0; i < stop - 1; ++i) {
        cur = cur->next;
    }

    Node* new_head = cur->next;
    cur->next = nullptr;
    tail->next = head;
    return new_head;
}

int main() {
    Node* head = nullptr;
    while (true) {
        int command;
        cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (command == 3) {
            print(head);
        } else if (command == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5) {
            head = reverse(head);
        } else if (command == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
    return 0;
}