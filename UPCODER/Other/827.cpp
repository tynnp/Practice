#include <iostream>
using namespace std;

struct Phong {
    string maPhong;
    string tenPhong;
    double donGia;
    int soLuongPhong;
    int tinhTrangPhong;

    friend istream &operator >> (istream &in, Phong &p) {
        in >> p.maPhong >> p.tenPhong >> p.donGia >> p.soLuongPhong >> p.tinhTrangPhong;
        return in;
    }

    friend ostream &operator << (ostream &out, Phong p) {
        out << "Ma Phong: " << p.maPhong << endl;
        out << "Ten Phong: " << p.tenPhong << endl;
        out << "Don Gia: " << p.donGia << endl;
        out << "So Luong Giuong: " << p.soLuongPhong << endl;
        out << "Tinh Trang: " << p.tinhTrangPhong;
        return out;
    }
};

struct Node {
    Phong data;
    Node *next;
    Node(Phong data): data(data), next(nullptr) {}
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(Phong p) {
        Node *node = new Node(p);
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
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    } 

    void phongTrong() {
        Node *tmp = head;
        while (tmp != nullptr) {
            if (tmp->data.tinhTrangPhong == 0)
                cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }

    void tongSoPhong() {
        Node *tmp = head;
        int res(0);
        while (tmp != nullptr) {
            res += tmp->data.soLuongPhong;
            tmp = tmp->next;
        }
        cout << res << endl;
    }

    void sapXep() {
        Node *current, *index;
        Phong tmp;
        if (head == nullptr) return;
        else {
            for (current = head; current->next != nullptr; current = current->next) {
                for (index = current->next; index != nullptr; index = index->next) {
                        if (current->data.donGia > index->data.donGia) {
                            tmp = current->data;
                            current->data = index->data;
                            index->data = tmp;
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
        Phong tmp;
        cin >> tmp;
        list.add(tmp);
    }

    list.phongTrong();
    list.tongSoPhong();
    list.sapXep(); 
    list.print();

    return 0;
}