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

    int size() {
        int res = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            res += 1;
            tmp = tmp->next;
        }

        return res;
    }

    void printMid() {
        Node *tmp = head;
        int index = 0;

        while (index != size()/2) {
            index += 1;
            tmp = tmp->next;
        }

        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
};

int main() {
    int n, tmp;
    LinkedList list;
    cin >> n;

    while (n--) {
        cin >> tmp;
        list.add(tmp);
    }

    list.printMid();
    return 0;
}