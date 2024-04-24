#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int n): data(n), next(nullptr) {}
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

    void add(int n) {
        Node *node = new Node(n);
        if (head == nullptr) head = node;
        else {
            Node *cur = head;
            while (cur->next != nullptr)
                cur = cur->next;
            cur->next = node;
        }
    }

    void print() {
        cout << "DSLK ban dau: ";
        Node *cur = head;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
};

int main() {
    LinkedList list;
    int tmp;

    while (cin >> tmp && tmp != -1)
        list.add(tmp);

    list.print();
    return 0;
}