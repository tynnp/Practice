#include <iostream>
#include <iomanip>
using namespace std;

struct NhanVien {
    string maNhanVien;
    string tenNhanVien;
    double luongNhanVien;

    friend istream &operator >> (istream &in, NhanVien &nv) {
        in >> nv.maNhanVien;
        in.ignore();
        getline(in, nv.tenNhanVien);
        in >> nv.luongNhanVien;
        return in;
    }

    friend ostream &operator << (ostream &out, NhanVien nv) {
        out << nv.maNhanVien << endl;
        out << nv.tenNhanVien << endl;
        out << fixed << setprecision(0) << nv.luongNhanVien << endl;
        return out;
    }
};

struct Node {
    NhanVien data;
    Node *next;

    Node(NhanVien data) {
        this->data = data;
        next = nullptr;
    }
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(NhanVien n) {
        Node *node = new Node(n);
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
        while (tmp != nullptr) {
            cout << tmp->data;
            tmp = tmp->next;
        }
    }

    NhanVien luongCaoNhat() {
        NhanVien res = head->data;
        Node *tmp = head->next;

        while (tmp != nullptr) {
            if (tmp->data.luongNhanVien > res.luongNhanVien)
                res = tmp->data;
            tmp = tmp->next;
        }

        return res;
    }

    double tongLuong() {
        double res = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            res += tmp->data.luongNhanVien;
            tmp = tmp->next;
        }

        return res;
    }

    void sapXepTang() {
        Node *current, *index;
        NhanVien temp;

        if (head == nullptr) return;
        else {
            for (current = head; current->next != nullptr; current = current->next) {
                for (index = current->next; index != nullptr; index = index->next) {
                    if (current->data.luongNhanVien > index->data.luongNhanVien) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                }
            }
        }
    }
};

int main() {
    int n;
    LinkedList list;
    cin >> n;

    while (n--) {
        NhanVien tmp;
        cin >> tmp;
        list.add(tmp);
    }

    list.print();
    cout << list.luongCaoNhat().tenNhanVien << endl;
    cout << list.tongLuong() << endl;
    list.sapXepTang();
    list.print();

    return 0;
}