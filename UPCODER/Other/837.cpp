#include <iostream>
using namespace std;

struct HocSinh {
    string tenHocSinh;
    int diemTrungBinh;

    friend istream &operator >> (istream &in, HocSinh &hs) {
        in >> hs.tenHocSinh >> hs.diemTrungBinh;
        return in;
    }

    friend ostream &operator << (ostream &out, HocSinh hs) {
        out << hs.tenHocSinh << " " << hs.diemTrungBinh;
        return out;
    }
};

struct LopHoc {
    string tenLop;
    int siSo;
    HocSinh list[50];

    friend istream &operator >> (istream &in, LopHoc &lop) {
        in >> lop.tenLop >> lop.siSo;
        for (int i = 0; i < lop.siSo; i++)
            in >> lop.list[i];
        return in;
    }

    friend ostream &operator << (ostream &out, LopHoc lop) {
        out << lop.tenLop << endl;
        for (int i = 0; i < lop.siSo; i++)
            out << lop.list[i] << endl;
        return out;
    }

    HocSinh diemCaoNhat() {
        HocSinh res = list[0];
        for (int i = 0; i < siSo; i++)
            if (res.diemTrungBinh < list[i].diemTrungBinh)
                res = list[i];
        return res;
    }
};

struct Node {
    LopHoc data;
    Node *next;
    Node (LopHoc data): data(data), next(nullptr) {}
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(LopHoc lop) {
        Node *node = new Node(lop);
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

    void printLopDongNhat() {
        Node *tmp = head;
        LopHoc res = head->data;

        while (tmp != nullptr) {
            if (res.siSo < tmp->data.siSo)
                res = tmp->data;
            tmp = tmp->next;
        }

        cout << res.tenLop << endl;
    }

    void printHocSinhCaoDiemNhat() {
        Node *tmp = head;
        HocSinh res = head->data.diemCaoNhat();

        while (tmp != nullptr) {
            if (res.diemTrungBinh < tmp->data.diemCaoNhat().diemTrungBinh) 
                res = tmp->data.diemCaoNhat();
            tmp = tmp->next;
        }

        cout << res.tenHocSinh << endl;
    }
};

int main() {
    LinkedList danhSach;
    int n;
    cin >> n;

    while (n--) {
        LopHoc tmp;
        cin >> tmp;
        danhSach.add(tmp);
    }

    danhSach.print();
    danhSach.printLopDongNhat();
    danhSach.printHocSinhCaoDiemNhat();

    return 0;
}