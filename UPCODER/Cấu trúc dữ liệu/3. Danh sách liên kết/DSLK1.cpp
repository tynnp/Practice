#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    Node *next;
    Node(char c): data(c), next(nullptr) {}
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}
    
    ~LinkedList() {
        Node *cur = head;
        while (cur != nullptr) {
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    
    void push_back(char c) {
        Node *node = new Node(c);
        
        if (head == nullptr) {
            head = node;
            return;
        }
        
        Node *last = head;
        while (last->next != nullptr) 
            last = last->next;
        last->next = node;
    }
    
    void print() {
        Node *tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
    
    void solve() {
        if (head == nullptr) return;
        
        Node *prev = head;
        Node *cur = head->next;
        
        while (cur != nullptr) {
            if (prev->data > cur->data) {
                Node *tmp = cur;
                prev->next = cur->next;
                cur = cur->next;
                delete tmp;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
    }
};

int main() {
    char tmp;
    LinkedList a;
    
    while (cin >> tmp) 
        a.push_back(tmp);
    
    a.solve();
    a.print();
    return 0;
}