#include <iostream>
#include <sstream>
using namespace std;

template<class DataType>
class List;

template<class DataType>
class Node {
friend List<DataType>;
private:
    DataType data;
    Node* next;
public:
    Node(DataType data): data(data), next(nullptr) {}
};

template<class DataType>
class List {
private:
    Node<DataType>* head;
public:
    List(): head(nullptr) {}
    ~List();
    int size();
    bool empty();
    DataType back();
    DataType front();
    void push_back(DataType x);
    void push_front(DataType x);
    void pop_back();
    void pop_front();
    void insert_after(DataType x, DataType c);
    void insert_before(DataType x, DataType c);
    void remove(DataType x);
};

int main() {
    char x, c;
    string line;
    getline(cin, line);
    stringstream ss(line);
    List<char> listChar;

    while (ss >> c)
        listChar.push_back(c);

    int q, t;
    cin >> q;

    while (q--) {
        cin >> t;

        if (t == 1) {
            cin >> c;
            listChar.push_front(c);
        }

        if (t == 2) {
            cin >> c;
            listChar.push_back(c);
        }

        if (t == 3) {
            listChar.pop_front();
        }

        if (t == 4) {
            listChar.pop_back();
        }

        if (t == 5) {
            cin >> x >> c;
            listChar.insert_after(x, c);
        }

        if (t == 6) {
            cin >> x >> c;
            listChar.insert_before(x, c);
        }

        if (t == 7) {
            cin >> c;
            listChar.remove(c);
        }
    }

    while (!listChar.empty()) {
        cout << listChar.front() << " ";
        listChar.pop_front();
    }

    return 0;
}

template<class DataType>
List<DataType>::~List() {
    while (head)
        pop_front();
}

template<class DataType>
int List<DataType>::size() {
    int size = 0;
    Node<DataType>* cur = head;

    while (cur) {
        size++;
        cur = cur->next;
    }

    return size;
}

template<class DataType>
bool List<DataType>::empty() {
    return head == nullptr;
}

template<class DataType>
DataType List<DataType>::back() {
    Node<DataType>* cur = head;

    while (cur->next)
        cur = cur->next;

    return cur->data;
}

template<class DataType>
DataType List<DataType>::front() {
    return head->data;
}

template<class DataType>
void List<DataType>::push_back(DataType x) {
    Node<DataType>* node = new Node<DataType>(x);
    
    if (empty()) {
        head = node;
        return;
    }

    Node<DataType>* cur = head;
    while (cur->next)
        cur = cur->next;
    cur->next = node;
}

template<class DataType>
void List<DataType>::push_front(DataType x) {
    Node<DataType>* node = new Node<DataType>(x);
    node->next = head;
    head = node;
}

template<class DataType>
void List<DataType>::pop_back() {
    if (empty())
        return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node<DataType>* cur = head;
    while (cur->next->next) 
        cur = cur->next;
    delete cur->next;
    cur->next = nullptr;
}

template<class DataType>
void List<DataType>::pop_front() {
    if (empty())
        return;

    Node<DataType>* tmp = head;
    head = head->next;
    delete tmp;
}

template<class DataType>
void List<DataType>::insert_after(DataType x, DataType c) {
    if (empty())
        return;

    Node<DataType>* cur = head;
    while (cur) {
        if (cur->data == x) {
            Node<DataType>* node = new Node<DataType>(c);
            node->next = cur->next;
            cur->next = node;
            return;
        }

        cur = cur->next;
    }
}

template<class DataType>
void List<DataType>::insert_before(DataType x, DataType c) {
    if (empty())
        return;

    if (head->data == x) {
        push_front(c);
        return;
    }

    Node<DataType>* cur = head;
    while (cur->next) {
        if (cur->next->data == x) {
            Node<DataType>* node = new Node<DataType>(c);
            node->next = cur->next;
            cur->next = node;
            return;
        }

        cur = cur->next;
    }
}

template<class DataType>
void List<DataType>::remove(DataType x) {
    if (empty()) 
        return;

    if (head->data == x) {
        pop_front();
        return;
    }

    Node<DataType>* cur = head;
    while (cur->next) {
        if (cur->next->data == x) {
            Node<DataType>* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
            return;
        }
        
        cur = cur->next;
    }
}
