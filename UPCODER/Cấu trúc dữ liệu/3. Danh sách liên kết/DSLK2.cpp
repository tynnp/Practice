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
        while (head != nullptr) {
            Node *del = head;
            head = head->next;
            delete del;
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
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur->data;
            cur = cur->next;
        } 
        cout << endl;
    }
    
    void solve() {
        if (head->data != 'A') {
            Node *node = new Node('A');
            node->next = head;
            head = node;
        }
        
        Node *cur = head;
        while (cur->next != nullptr) {
            if (cur->data != cur->next->data - 1) {
                Node *node = new Node(cur->data + 1);
                node->next = cur->next;
                cur->next = node;
            }
            cur = cur->next;
        }
        
        Node *last = cur;
        while (last->data != 'Z') {
            Node *node = new Node(last->data + 1);
            last->next = node;
            last = last->next;
        }
    }
};

int main() {
    int n;
    char c;
    LinkedList a;
    
    cin >> n;
    while (n--) {
        cin >> c;
        a.push_back(c);
    }
    
    a.print();
    a.solve();
    a.print();
    return 0;
}