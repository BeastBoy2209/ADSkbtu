#include<iostream>
#include<string>
using namespace std;

struct Node{
    int value;
    Node* nxt = NULL;
    
    Node(Node* next) : value(0), nxt(next) {}
    Node(int x) : value(x), nxt(nullptr) {}
    Node(int x, Node* next) : value(x), nxt(next) {}
};

struct LL{
    Node *head = NULL;
    Node *tail = NULL;
    LL(): head(nullptr), tail(nullptr){};

    Node* get_tail(){
        if(head == 0){
            return NULL;
        } else {
            Node *cur = head;
            while(cur -> nxt != nullptr){
                cur = cur -> nxt;
            }
            return cur;
        }
    }

    Node* get(int pos){
        Node *cur = head;
        if(head != nullptr){ 
            for(int i=0; i < pos; i++){
                if(cur != nullptr){
                    cur = cur -> nxt;
                } else { 
                    return NULL;
                }
            }
            return cur;
        }
        return NULL;
    }
    
    bool LL_empty() {
        return head == nullptr;
    }

    void insert_begin(int value){
        Node* new_node = new Node(value, head);
        head = new_node;
    }

    void insert_tail(int value){
        Node *tail = get_tail();
        Node *new_node = new Node(value, nullptr);
        if(tail == nullptr){
            head = new_node;
        }else {
            tail -> nxt = new_node;
        }
    }

    void insert(int pos, int value){
        Node *i = get(pos - 1);
        if(pos == 0){
            insert_begin(value);
            return;
        } if(i == nullptr) {
            insert_tail(value);
            return;
        }
        Node *new_node =new Node(value, i->nxt);
        i -> nxt = new_node;
    }
    
    void output(){
        cout << "[";
        Node *cur = head;
        while(cur != nullptr){
            cout << cur -> value;
            cur = cur -> nxt;
            if(cur != nullptr){
                cout << ",";
            } else {
                cout << "]";
            }
        }
    }
};

int main(){
    LL test;
    test.insert(0,11);
    test.insert(1,12);
    test.insert(2,21);
    test.output();
}