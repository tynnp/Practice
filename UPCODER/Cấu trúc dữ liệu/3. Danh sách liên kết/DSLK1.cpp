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

    void check() {
        Node* tmp = this->head;
        while (tmp != nullptr && tmp->next != nullptr) {
            if (tmp->data > tmp->next->data)
                tmp->next = tmp->next->next;
            else tmp = tmp->next;
        }
    }

    void print() {
        Node* tmp = this->head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main() {
    LinkedList list;
    char c;
    while (cin >> c) list.add(c);
    list.check();
    list.print();
    return 0;
}