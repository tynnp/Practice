#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int n) {
        data = n;
        next = nullptr;
    }
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(int n) {
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
        Node *tmp = head->next;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }

    int size() {
        int res = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            res += 1;
            tmp = tmp->next;
        }

        return res;
    }

    int sizeChan() {
        int res = 0;
        Node *tmp = head->next;

        while (tmp != nullptr) {
            if (tmp->data % 2 == 0) res++;
            tmp = tmp->next;
        }

        return res;
    }
};

int main() {
    int n;
    LinkedList list;

    while (cin >> n) list.add(n);

    if (list.size() == 0) cout << "NO";
    else cout << list.size();
    cout << endl;

    if (list.size() < 2) cout << "NO";
    else list.print();
    cout << endl;

    if (list.sizeChan() == 0) cout << "NO";
    else cout << list.sizeChan();

    return 0;
}