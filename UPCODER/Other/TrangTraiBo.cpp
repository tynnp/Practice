#include <iostream>
using namespace std;

struct ConBo {
    string maBo;
    string loaiBo;
    int namSinh;
    int canNang;

    friend istream &operator >> (istream &in, ConBo &cb) {
        in >> cb.maBo >> cb.loaiBo >> cb.namSinh >> cb.canNang;
        return in;
    }

    friend ostream &operator << (ostream &out, ConBo cb) {
        out << cb.maBo << " " << cb.loaiBo << " " << cb.namSinh << " " << cb.canNang;
        return out;   
    }

    bool boSua() {
        return maBo.find("BS") != string::npos;
    }
};

struct Node {
    ConBo data;
    Node *next;
    
    Node(ConBo data) {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(ConBo data) {
        Node *node = new Node(data);
        if (head == nullptr) head = node;
        else {
            Node *tmp = head;
            while (tmp->next != nullptr) 
                tmp = tmp->next;
            tmp->next = node;
        }
    }

    void print() {
        Node *tmp = head;
        bool checkCout = false;

        while (tmp != nullptr) {
            cout << tmp->data << endl;
            checkCout = true;
            tmp = tmp->next;
        }

        if (!checkCout) cout << 0 << endl;
    }

    int soLuongBoSua() {
        int cnt = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            if (tmp->data.boSua()) cnt++;
            tmp = tmp->next;
        }

        return cnt;
    }

    void printKoBe() {
        Node *tmp = head;
        bool checkCout = false;
        bool checkEndl = false;

        while (tmp != nullptr) {
            if (!tmp->data.boSua() && tmp->data.canNang > 20) {
                if (checkEndl) cout << endl;
                cout << tmp->data.maBo;
                checkEndl = true;
                checkCout = true;
            }
            tmp = tmp->next;
        }

        if (!checkCout) cout << 0;
        cout << endl;
    }

    void printTuoiCao() {
        Node *tmp = head;
        bool checkEndl = false;
        bool checkCout = false;
        int namSinh = tmp->data.namSinh;

        while (tmp != nullptr) {
            if (tmp->data.namSinh < namSinh)
                namSinh = tmp->data.namSinh;
            tmp = tmp->next;
        }

        tmp = head;
        while (tmp != nullptr) {
            if (tmp->data.namSinh == namSinh) {
                if (checkEndl) cout << endl;
                cout << tmp->data.maBo;
                checkEndl = true;
                checkCout = true;
            }
            tmp = tmp->next;
        }

        if (!checkCout) cout << 0;
        cout << endl;
    }
};

int main() {
    int n;
    LinkedList list;
    cin >> n;
    
    while (n--) {
        ConBo tmp;
        cin >> tmp;
        list.add(tmp);
    }

    list.print();
    cout << list.soLuongBoSua() << endl;
    list.printKoBe();
    list.printTuoiCao();

    return 0;
} 