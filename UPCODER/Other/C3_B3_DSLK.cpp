#include <iostream>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class Node {
friend class LinkedList;

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
    int getMinVal();
    void addTail(int data);
    void display();
    void sortAsc();
    void removeDuplicates();
    LinkedList createIntersectionList(LinkedList &other);
    LinkedList findCommonElements(LinkedList &other);
    LinkedList excludeMinValueList(LinkedList &other);
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
    L3 = L1.createIntersectionList(L2);
    L3.display();
    cout << endl;

    LinkedList L4;
    L4 = L1.findCommonElements(L2);
    L4.display();
    cout << endl;

    LinkedList L5;
    L5 = L1.excludeMinValueList(L2);
    L5.display();

    return 0;
}

LinkedList::LinkedList() {
    head = tail = nullptr;
}

int LinkedList::getMinVal() {
    int res = INT_MAX;

    for (Node* i = head; i != nullptr; i = i->next) 
        if (i->data < res)
            res = i->data;
    
    return res;
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

void LinkedList::sortAsc() {
    for (Node* i = head; i != nullptr; i = i->next)
        for (Node* j = i->next; j != nullptr; j = j->next)
            if (j->data < i->data)
                swap(j->data, i->data);
}

void LinkedList::removeDuplicates() {
    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (i->data == j->data) {
                Node* k = i;

                while (k->next != j)
                    k = k->next;
                k->next = j->next;

                Node* tmp = j;
                j = k;
                delete tmp;
            }
        }
    }
}

LinkedList LinkedList::createIntersectionList(LinkedList &other) {
    LinkedList result;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = other.head; j != nullptr; j = j->next) {
            if (i->data == j->data) {
                result.addTail(i->data);
                break;
            }
        }
    }

    result.removeDuplicates();
    result.sortAsc();
    return result;
}

LinkedList LinkedList::findCommonElements(LinkedList &other) {
    LinkedList result;
    bool check = false;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = other.head; j != nullptr; j = j->next) {
            if (i != nullptr && j != nullptr && i->data == j->data) {
                result.addTail(i->data);
                i = i->next;
                check = true;

            } else if (check)
                return result;
        }

        if (i == nullptr) 
            break;
    }

    return result;
}

LinkedList LinkedList::excludeMinValueList(LinkedList &other) {
    LinkedList result;
    int minVal = other.getMinVal();

    for (Node* i = head; i != nullptr; i = i->next) 
        if (i->data != minVal)
            result.addTail(i->data);

    return result;
}