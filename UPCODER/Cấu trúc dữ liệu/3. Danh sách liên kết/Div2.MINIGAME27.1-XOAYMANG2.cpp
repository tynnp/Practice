#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int);
    };

    Node *head;
    Node *tail;

    LinkedList();
    ~LinkedList();
    bool empty();
    int size();
    void clear();
    void print();
    void push_front(int);
    void push_back(int);
    void rotate_left(int);
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    LinkedList list;
    
    cin >> n >> k;
    k = k % n;  
    
    while (n--) {
        int tmp;
        cin >> tmp;
        list.push_back(tmp);
    }
    
    list.rotate_left(k);
    list.print();
    return 0;
}

LinkedList::Node::Node(int n) {
    data = n;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    clear();
}

bool LinkedList::empty() {
    return head == nullptr;
}

int LinkedList::size() {
    int res = 0;
    Node *tmp = head;

    while (tmp != nullptr) {
        res += 1;
        tmp = tmp->next;
    }

    return res;
}

void LinkedList::clear() {
    while (head != nullptr) {
        Node *cur = head;
        head = head->next;
        delete cur;
    }
    tail = nullptr;
}

void LinkedList::print() {
    Node *cur = head;
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void LinkedList::push_front(int n) {
    Node *node = new Node(n);
    node->next = head;
    head = node;
    if (tail == nullptr) {
        tail = node;
    }
}

void LinkedList::push_back(int n) {
    Node *node = new Node(n);
    if (this->empty()) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

void LinkedList::rotate_left(int k) {
    if (this->empty() || k == 0) return;

    Node *cur = head;
    int count = 1;
    
    while (count < k && cur != nullptr) {
        cur = cur->next;
        count++;
    }
    
    if (cur == nullptr || cur->next == nullptr) return;
    
    Node *new_head = cur->next; 
    cur->next = nullptr; 
    tail->next = head; 
    head = new_head; 
}