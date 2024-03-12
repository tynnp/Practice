#include <iostream>
using namespace std;

struct TacGia {
    int n;
    string danhSach[5];

    friend istream &operator >> (istream &in, TacGia &tg) {
        in >> tg.n;
        in.ignore();
        for (int i = 0; i < tg.n; i++)
            getline(in, tg.danhSach[i]);
        return in;
    }

    bool check(string tg) {
        for (int i = 0; i < n; i++)
            if (danhSach[i] == tg) return true;
        return false;
    }
};

struct Sach {
    string tenSach;
    TacGia tacGia;
    string nhaXuatBan;
    int namXuatBan;

    friend istream &operator >> (istream &in, Sach &s) {
        in >> s.tenSach >> s.tacGia;
        getline(in, s.nhaXuatBan);
        in >> s.namXuatBan;
        return in;
    }

    friend ostream &operator << (ostream &out, Sach s) {
        out << s.tenSach << "-" << s.tacGia.n << " tac gia-" << s.nhaXuatBan << "-" << s.namXuatBan;
        return out;
    }

    bool checkTacGia(string tg) {
        return tacGia.check(tg);
    }

    bool checkNhaXuatBanVaNam(string nxb, int nam) {
        return nhaXuatBan == nxb && namXuatBan == nam;
    }
};

struct Node {
    Sach data;
    Node *next;
    Node(Sach s): data(s), next(nullptr) {}
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(Sach s) {
        Node *node = new Node(s);
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

    int cntTacGia(string tg) {
        int res = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            if (tmp->data.checkTacGia(tg)) res++;
            tmp = tmp->next;
        }

        return res;
    }

    void print2(string nxb, int nam) {
        int cnt = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            if (tmp->data.checkNhaXuatBanVaNam(nxb, nam)) cnt++;
            tmp = tmp->next;
        }

        cout << cnt << endl;

        tmp = head;
        while (tmp != nullptr) {
            if (tmp->data.checkNhaXuatBanVaNam(nxb, nam))
                cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }
};

int main() {
    int nam, n;
    string nxb, tg;
    LinkedList list;

    cin >> nam;
    cin.ignore();
    getline(cin, nxb);
    getline(cin, tg);
    cin >> n;

    while (n--) {
        Sach tmp;
        cin >> tmp;
        list.add(tmp);
    }

    list.print();
    cout << list.cntTacGia(tg) << endl;
    list.print2(nxb, nam);

    return 0;
}