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

    void push_back(int n) {
        Node *node = new Node(n);
        if (head == nullptr) head = node;
        else {
            Node *tmp = head;
            while (tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = node;
        }
    }

    void push_front(int n) {
        Node *node = new Node(n);
        node->next = head;
        head = node;
    }

    void print() {
        Node *tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }

    void daoNguoc() {
        LinkedList list;
        Node *tmp = head;

        while (tmp != nullptr) {
            list.push_front(tmp->data);
            tmp = tmp->next;
        }

        *this = list;
    }
};

int main() {
    int n;
    LinkedList arr;
    cin >> n;

    while (n--) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    arr.daoNguoc();
    arr.print();
    return 0;
}