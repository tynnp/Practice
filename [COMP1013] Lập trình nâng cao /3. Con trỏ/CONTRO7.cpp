#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

ofstream ofile;
ifstream ifile; 

int minVal(int a, int b) {
    return a < b ? a : b;
}

int maxVal(int a, int b) {
    return a > b ? a : b;
}

struct Node {
    int data;
    Node* next;
    Node(int n): data(n), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList(): head(nullptr) {
    }

    ~LinkedList() {
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

    void add(int n, int m) {
        this->add(n);
        this->add(m);
        return;
    }

    int size() {
        int size = 0;
        Node* tmp = this->head;
        while (tmp != nullptr)
            tmp = tmp->next,
            size += 1;
        return size;
    }

    int min() {
        int khoangCach = 999999;
        Node* tmp = this->head;
        
        while (tmp != nullptr && tmp->next != nullptr) {
            Node* next = tmp->next;
            while (next != nullptr) {
                if (abs(tmp->data - next->data) < khoangCach)
                    khoangCach = abs(tmp->data - next->data);
                next = next->next;
            }
            tmp = tmp->next;
        }

        return khoangCach;
    }

    void print(ofstream& file) {
        Node* tmp = this->head;

        while (tmp != nullptr && tmp->next != nullptr) {
            int min = minVal(tmp->data, tmp->next->data);
            int max = maxVal(tmp->data, tmp->next->data);
            ofile << "(" << min << ", " << max << ")" << " ";
            tmp = tmp->next->next;
        }
        file.close();
        return;
    }

    void check() {
        ofile.open("CONTRO.out");
        LinkedList res;
        Node* tmp = this->head;

        while (tmp != nullptr && tmp->next != nullptr) {
            Node* next = tmp->next;
            while (next != nullptr) {
                if (abs(tmp->data - next->data) == this->min())
                    res.add(tmp->data, next->data);
                next = next->next;
            }
            tmp = tmp->next;
        }

        ofile << res.size()/2 << " ";
        ofile << this->min() << endl;
        res.print(ofile);
        ofile.close();
        return;
    }
};

int main() {
    ifile.open("CONTRO.inp");
    LinkedList list;
    int n; ifile >> n;

    while (n--) {
        int tmp; ifile >> tmp;
        list.add(tmp);
    }

    list.check();
    ifile.close();
    return 0;
}