#include <bits/stdc++.h>
using namespace std;

struct LinkedList {
    struct Node {
        int data;
        Node *next;
        Node(int);
    };

    Node *head;

    LinkedList();
    ~LinkedList();
    bool empty();
    int size();
    void clear();
    void print();
    int front();
    int back();
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
    void insert(int, int);
    void erase(int);
    void remove(int);
    void sort();
    void reverse();
    int max_element();
    int min_element();
    int index_of(int);
    void index_of_max();  
    void index_of_min();  
};

int main() {
    int n, m, tmp;
    LinkedList list;
    LinkedList k;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        list.push_back(i);
        
    while (m--) {
        cin >> tmp;
        k.push_back(tmp);
    }
    
    while (!list.empty()) {
        m = k.front();
        k.push_back(m);
        k.pop_front();
        
        for (int i = 1; i < m; i++) {
            list.push_back(list.front());
            list.pop_front();
        }
        
        cout << list.front() << " ";
        list.pop_front();
    }
   
    return 0;
}

LinkedList::Node::Node(int n) {
    data = n;
    next = nullptr;
}

LinkedList::LinkedList() {
    head = nullptr;
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
}

void LinkedList::print() {
    Node *cur = head;

    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}

int LinkedList::front() {
    if (!this->empty())
        return head->data;
}

int LinkedList::back() {
    if (!this->empty()) {
        Node *last = head;
        while (last->next != nullptr)
            last = last->next;
        return last->data;
    }
}

void LinkedList::push_front(int n) {
    Node *node = new Node(n);
    node->next = head;
    head = node;
}

void LinkedList::push_back(int n) {
    if (this->empty()) {
        this->push_front(n);
        return;
    }

    Node *node = new Node(n);
    Node *last = head;

    while (last->next != nullptr)
        last = last->next;
    last->next = node;
}

void LinkedList::pop_front() {
    if (this->empty()) return;
    Node *cur = head;
    head = head->next;
    delete cur;
}

void LinkedList::pop_back() {
    if (this->empty()) return;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node *prev = nullptr;
    Node *cur = head;
    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }

    delete cur;
    prev->next = nullptr;
}

void LinkedList::insert(int pos, int n) {
    if (pos == 0) {
        push_front(n);
        return;
    }

    int index = 0;
    Node *cur = head;
    while (index != pos-1 && cur != nullptr) {
        index++;
        cur = cur->next;
    }

    if (cur == nullptr) return;
    Node *node = new Node(n);
    node->next = cur->next;
    cur->next = node;
}

void LinkedList::erase(int pos) {
    if (this->empty()) return;
    if (pos == 0) {
        pop_front();
        return;
    }

    int index = 0;
    Node *cur = head;
    Node *prev = nullptr;
    while (index != pos && cur != nullptr) {
        prev = cur;
        cur = cur->next;
        index++;
    }

    if (cur == nullptr) return;
    prev->next = cur->next;
    delete cur;
}

void LinkedList::remove(int n) {
    if (this->empty()) return;

    while (head != nullptr && head->data == n)
        pop_front();

    Node *prev = nullptr;
    Node *cur = head;
    while (cur != nullptr) {
        if (cur->data == n) {
            Node *tmp = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete tmp;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

void LinkedList::sort() {
    if (this->empty() || head->next == nullptr) return;
    for (Node *i = head; i != nullptr; i = i->next) 
        for (Node *j = i->next; j != nullptr; j = j->next) 
            if (i->data > j->data) 
                swap(i->data, j->data);
}

void LinkedList::reverse() {
    Node *prev = nullptr;
    Node *cur = head;
    Node *next = nullptr;

    while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    head = prev;
}

int LinkedList::max_element() {
    if (!this->empty()) {
        int max_val = head->data;
        Node *cur = head->next;

        while (cur != nullptr) {
            if (cur->data > max_val)
                max_val = cur->data;
            cur = cur->next;
        }

        return max_val;
    }
}

int LinkedList::min_element() {
    if (!this->empty()) {
        int min_val = head->data;
        Node *cur = head->next;

        while (cur != nullptr) {
            if (cur->data < min_val)
                min_val = cur->data;
            cur = cur->next;
        }

        return min_val;
    }
}

int LinkedList::index_of(int n) {
    int index = 0;
    Node *cur = head;

    while (cur != nullptr) {
        if (cur->data == n)
            return index;
        cur = cur->next;
        index++;
    }

    return -1;
}

void LinkedList::index_of_max() {
    if (this->empty()) return;
    int max_val = max_element();
    int index = 1;
    Node *cur = head;

    while (cur != nullptr) {
        if (cur->data == max_val) 
            cout << index << " ";
        cur = cur->next;
        index++;
    }
    
    cout << endl;
}

void LinkedList::index_of_min() {
    if (this->empty()) return;
    int min_val = min_element();
    int index = 1;
    Node *cur = head;

    while (cur != nullptr) {
        if (cur->data == min_val) 
            cout << index << " ";
        cur = cur->next;
        index++;
    }
    
    cout << endl;
}
