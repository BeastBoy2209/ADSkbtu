    #include <iostream>
    using namespace std;

    struct Node {
        string value;
        Node* next;

        Node() {}

        Node(string value) {
            this->value = value;
            this->next = NULL;
        }
    };

    class LinkedList {
    public:
        Node* head;

        LinkedList() {
            head = NULL;
        }

        // Add a new node to the front of the list
        void add_front(string value) {
            Node* newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            cout << "ok" << endl;
        }

        // Add a new node to the back of the list
        void add_back(string value) {
            Node* newNode = new Node(value);
            if (head == NULL) {
                head = newNode;
            } else {
                Node* cur = head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cur->next = newNode;
            }
            cout << "ok" << endl;
        }

        // Remove the front node
        void erase_front() {
            if (head == NULL) {
                cout << "error" << endl;
            } else {
                cout << head->value << endl;
                head = head->next;
            }
        }

        // Remove the back node
        void erase_back() {
            if (head == NULL) {
                cout << "error" << endl;
            } else if (head->next == NULL) {
                cout << head->value << endl;
                head = NULL;
            } else {
                Node* cur = head;
                Node* prev = NULL;
                while (cur->next != NULL) {
                    prev = cur;
                    cur = cur->next;
                }
                cout << cur->value << endl;
                prev->next = NULL;
            }
        }

        // Get the front node value
        void front() {
            if (head == NULL) {
                cout << "error" << endl;
            } else {
                cout << head->value << endl;
            }
        }

        // Get the back node value
        void back() {
            if (head == NULL) {
                cout << "error" << endl;
            } else {
                Node* cur = head;
                while (cur->next != NULL) {
                    cur = cur->next;
                }
                cout << cur->value << endl;
            }
        }

        // Clear the list
        void clear() {
            head = NULL;
            cout << "ok" << endl;
        }
    };

    int main() {
        LinkedList list;
        while (true) {
            string command;
            cin >> command;
            
            if (command == "add_front") {
                string value;
                cin >> value;
                list.add_front(value);
            } else if (command == "add_back") {
                string value;
                cin >> value;
                list.add_back(value);
            } else if (command == "erase_front") {
                list.erase_front();
            } else if (command == "erase_back") {
                list.erase_back();
            } else if (command == "front") {
                list.front();
            } else if (command == "back") {
                list.back();
            } else if (command == "clear") {
                list.clear();
            } else if (command == "exit") {
                cout << "goodbye" << endl;
                break;
            }
        }
        return 0;
    }