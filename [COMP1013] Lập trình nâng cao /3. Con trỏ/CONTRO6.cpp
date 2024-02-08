#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n): data(n), next(nullptr) {}
};

struct Linkedlist {
    Node* head;
    Linkedlist(): head(nullptr) {}

    void add(int n) {
        Node* node = new Node(n);
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

    int size() {
        int size = 0;
        Node* tmp = this->head;
        while (tmp != nullptr) 
            size += 1,
            tmp = tmp->next;
        return size;
    }

    void print() {
        if (this->size() > 0)
            cout << this->size() << endl;
        else {
            cout << -1;
            return;
        }

        Node* tmp = this->head;
        while (tmp != nullptr) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        return;
    }

    void check() {
        Linkedlist res;
        Node* ptr1 = this->head;
        int index = 2;

        if (ptr1 == nullptr || ptr1->next == nullptr || ptr1->next->next ==nullptr) {
            cout << -1;
            return;
        }

        while (ptr1->next->next != nullptr) {
            Node* ptr2 = ptr1->next->next;
            Node* ptr3 = ptr1->next;

            if (ptr1->data*ptr2->data == ptr3->data)
                    res.add(index);

            ptr1 = ptr1->next;
            index += 1;
        }
        res.print();
        return;
    }

    ~Linkedlist() {
        Node* tmp = this->head;
        Node* next;

        while (tmp != nullptr) {
            next = tmp->next;
            delete tmp;
            tmp = next;
        }

        this->head = nullptr;
        return;
    }
};

int main() {
    int n; cin >> n;
    Linkedlist list;

    while (n--) {
        int tmp; cin >> tmp;
        list.add(tmp);
    }

    list.check();
    return 0;
}