#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void pushBack(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == nullptr) head = newNode;
    else {
        Node* tmp = head;
        while (tmp->next != nullptr) 
            tmp = tmp->next;
        tmp->next = newNode;
    }
}

void push(Node*& head, int n) {
    for (int i = 1; i <= n; i++) {
        int k; cin >> k; pushBack(head, k);
    }
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    } cout << endl;
}

void check(Node*& head) {
    Node* tmp = head;
    while (tmp != nullptr) {
        if (tmp->data % 2 != 0) {
            tmp->data += 1;
        }
        tmp = tmp->next;
    }
} 

void rdisplay(Node* head) {
    Node* prev = nullptr;
    Node* index = head;
    Node* next = nullptr;

    while (index != nullptr) {
        next = index->next;
        index->next = prev;
        prev = index;
        index = next;
    }
    
    while (prev != nullptr) {
        cout << prev->data << " ";
        prev = prev->next;
    }
}

int main() {
    int n; cin >> n;
    Node* list = NULL; 
    push(list, n);
    display(list);
    check(list);
    display(list);
    rdisplay(list);
    return 0;
}