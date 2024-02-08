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

    bool find(int n) {
        Node* tmp = this->head;

        while (tmp != nullptr) {
            if (tmp->data == n) return true;
            tmp = tmp->next; 
        }
        return false;
    }

    bool check() {
        Node* ptr1 = this->head;
        
        while (ptr1 != nullptr) {
            Node* ptr2 = ptr1->next;
            while (ptr2 != nullptr) {
                if(this->find(ptr1->data + ptr2->data)) 
                    return true;
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
        return false;
    }
};

int main() {
    int n; cin >> n;
    Linkedlist list;

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        list.add(tmp);
    }

    cout << (list.check() ? "YES" : "NO");
    return 0;
}
