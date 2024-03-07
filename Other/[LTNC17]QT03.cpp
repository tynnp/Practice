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

    LinkedList() {
        head = nullptr;
    }

    void add(int n) {
        Node *newNode = new Node(n);
        if (head == nullptr) head = newNode;
        else {
            Node *tmp = head;
            while (tmp->next != nullptr)   
                tmp = tmp->next;
            tmp->next = newNode;
        }
    }

    void erase(int n) {
        Node *tmp = head;

        while (head->data == n) {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
        }

        while (tmp->next != nullptr) {
            if (tmp->next->data == n) {
                Node *toDelete = tmp->next;
                tmp->next = tmp->next->next;
                delete toDelete;
            } else 
                tmp = tmp->next;
        }
    }

    int size() {
        int cnt = 0;
        Node *tmp = head;
        while (tmp != nullptr) 
            cnt++, tmp = tmp->next;
        return cnt;
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
    int n, k, tmp;
    LinkedList list;
    cin >> n >> k;

    while (n--) {
        cin >> tmp;
        list.add(tmp);
    }

    list.erase(k);
    cout << list.size() << endl;
    list.print();

    return 0;
}