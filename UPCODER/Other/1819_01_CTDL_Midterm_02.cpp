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

    bool check(int n) {
        Node *tmp = head;

        while (tmp != nullptr) {
            if (tmp->data == n) return false;
            tmp = tmp->next;
        }

        return true;
    }

    void add(int n) {
        if (!check(n)) return;
        Node *node = new Node(n);
        if (head == nullptr) head = node;
        else {
            Node *tmp = head;
            while (tmp->next != nullptr) 
                tmp = tmp->next;
            tmp->next = node;
        }
    }

    void print() {
        Node *tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main() {
    int n;
    LinkedList list;
    while (cin >> n) list.add(n);
    list.print();
    return 0;
}