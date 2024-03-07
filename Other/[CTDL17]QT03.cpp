#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c): data(c), next(nullptr) {} 
};

struct LinkedList {
    Node* head;
    LinkedList(): head(nullptr) {}

    void add(char c) {
        Node* node = new Node(c);
        Node* tmp = this->head;
        if (tmp == nullptr) 
            this->head = node;
        else {
            while (tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = node;
        }
        return;
    }

    void full() {
        if (this->head->data != 'A') {
            Node* dau = new Node('A');
            this->head = dau;
        }

        Node* tmp = this->head;
        while (tmp->next != nullptr) 
            tmp = tmp->next;
        
        if (tmp->data != 'Z') {
            Node* cuoi = new Node('Z');
            tmp->next = cuoi;
        }

        while (tmp != nullptr && tmp->next != nullptr) {
            if (tmp->data != tmp->next->data-1) {
                Node* node = new Node(tmp->data+1);
                node->next = tmp->next;
                tmp->next = node;
            }
            tmp = tmp->next;
        }
    }

    void print() {
        Node* tmp = this->head;
        while (tmp != nullptr) {
            cout << tmp->data;
            tmp = tmp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n;
    char c;
    cin >> n;

    while (n--) {
        cin >> c;
        list.add(c);
    }

    list.print();
    list.full();
    list.print();
    return 0;
}