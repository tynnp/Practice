#include <bits/stdc++.h>
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
        while (head != nullptr) {
            Node *del = head;
            head = head->next;
            delete del;
        }
    }
    
    void push_back(int n) {
        Node *node = new Node(n);
        
        if (head == nullptr) {
            head = node;
            return;
        }
        
        Node *last = head;
        while (last->next != nullptr) 
            last = last->next;
        last->next = node;
    }  
    
    int max_element() {
        int res = head->data;
        Node *tmp = head->next;
        
        while (tmp != nullptr) {
            if (tmp->data > res) res = tmp->data;
            tmp = tmp->next;
        }
        
        return res;
    }
    
    int min_element() {
        int res = head->data;
        Node *tmp = head->next;
        
        while (tmp != nullptr) {
            if (tmp->data < res) res = tmp->data;
            tmp = tmp->next;
        }
        
        return res;
    }
    
    void print_index_max() {
        int val = this->max_element();
        int index = 1;
        Node *tmp = head;
        
        while (tmp != nullptr) {
            if (tmp->data == val) 
                cout << index << " ";
            tmp = tmp->next;
            index = index + 1;
        }
        
        cout << endl;
    }
    
    void print_index_min() {
        int val = this->min_element();
        int index = 1;
        Node *tmp = head;
        
        while (tmp != nullptr) {
            if (tmp->data == val)
                cout << index << " ";
            tmp = tmp->next;
            index = index + 1;
        }
        
        cout << endl;
    }
};

int main() {
    int n, element;
    LinkedList list;
    
    cin >> n;
    while (n--) {
        cin >> element;
        list.push_back(element);
    }
    
    cout << list.max_element() << endl;
    list.print_index_max();
    cout << list.min_element() << endl;
    list.print_index_min();
    
    return 0;
}