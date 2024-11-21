#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class LinkedList;

class Node {
friend LinkedList;

private:
    int data;
    Node* next;

public:
    Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
private: 
    Node* head;
    Node* tail;

public:
    LinkedList();
    void addTail(int data);
    void display();
    bool duplicate(int data);
    void sortList(bool comp = true);
    LinkedList unionList(LinkedList &other);
    LinkedList differenceList(LinkedList &other);
    LinkedList splitAndSort();
    LinkedList mergeSum(LinkedList &other);
};

int main() {
    LinkedList L1, L2;

    int x;
    string line;

    getline(cin, line);
    stringstream ss(line);
    while (ss >> x)
        L1.addTail(x);

    getline(cin, line);
    ss = stringstream(line);
    while (ss >> x) 
        L2.addTail(x);
    
    LinkedList L3;
    L3 = L1.unionList(L2);
    L3.sortList();
    L3.display();
    cout << endl;

    LinkedList L4;
    L4 = L1.differenceList(L2);
    L4 = L4.splitAndSort();
    L4.display();
    cout << endl;

    LinkedList L5;
    L5 = L1.mergeSum(L2);
    L5.display();

    return 0;
}

LinkedList::LinkedList() {
    head = tail = nullptr;
}

void LinkedList::addTail(int data) {
    Node* node = new Node(data);

    if (head == nullptr) {
        head = tail = node;
        return;
    }

    tail->next = node;
    tail = node;
}

void LinkedList::display() {
    Node* cur = head;

    while (cur->next != nullptr) {
        cout << cur->data << ' ';
        cur = cur->next;
    }

    cout << cur->data;
}

bool LinkedList::duplicate(int data) {
    Node* cur = head;

    while (cur != nullptr) {
        if (cur->data == data)
            return true;
        cur = cur->next;
    }

    return false;
}

void LinkedList::sortList(bool comp) {
    Node* cur = head;

    while (cur != nullptr && cur->next != nullptr) {
        Node* cur2 = cur->next;

        while (cur2 != nullptr) {
            if (cur->data < cur2->data == comp) 
                swap(cur->data, cur2->data);
            cur2 = cur2->next;
        }

        cur = cur->next;
    }
}

LinkedList LinkedList::unionList(LinkedList &other) {
    LinkedList result;
    bool check[1001] = {false};
    Node* cur = head;

    while (cur != nullptr) {
        result.addTail(cur->data);
        check[cur->data] = true;
        cur = cur->next;
    }

    cur = other.head;

    while (cur != nullptr) {
        if (!check[cur->data]) {
            result.addTail(cur->data);
            check[cur->data] = true;
        }

        cur = cur->next;
    }

    return result;
}

LinkedList LinkedList::differenceList(LinkedList &other) {
    LinkedList result;

    for (Node* i = head; i != nullptr; i = i->next) {
        bool flag = false;

        for (Node* j = other.head; j != nullptr; j = j->next) 
            if (i->data == j->data)
                flag = true;

        if (!flag)
            result.addTail(i->data);
    }

    return result;
}

LinkedList LinkedList::splitAndSort() {
    int size = 0;
    Node* cur = head;

    while (cur != nullptr) {
        size++;
        cur = cur->next;
    }

    LinkedList listUp;
    LinkedList listDown;
    LinkedList result;

    int idx = 0;
    size >>= 1;
    cur = head;

    while (cur != nullptr) {
        if (idx == size) 
            break;
        
        idx++;
        listUp.addTail(cur->data);
        cur = cur->next;
    }

    while (cur != nullptr) {
        listDown.addTail(cur->data);
        cur = cur->next;
    }

    listUp.sortList();
    listDown.sortList(false);
    cur = listUp.head;

    while (cur != nullptr) {
        result.addTail(cur->data);
        cur = cur->next;
    }

    cur = listDown.head;
    while (cur != nullptr) {
        result.addTail(cur->data);
        cur = cur->next;
    }

    return result;
}

LinkedList LinkedList::mergeSum(LinkedList &other) {
    Node* cur = head;
    Node* cur2 = other.head;
    LinkedList result;

    while (cur != nullptr && cur2 != nullptr) {
        result.addTail(cur->data + cur2->data);
        cur = cur->next;
        cur2 = cur2->next;
    }

    while (cur != nullptr) {
        result.addTail(cur->data);
        cur = cur->next;
    }

    while (cur2 != nullptr) {
        result.addTail(cur2->data);
        cur2 = cur2->next;
    }

    return result;
}
