#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

struct Ngay {
    int ngay, thang, nam;

    friend ostream &operator << (ostream &out, Ngay n) {
        out << setw(2) << setfill('0') << n.ngay << "/";
        out << setw(2) << setfill('0') << n.thang << "/";
        out << setw(4) << setfill('0') << n.nam;
        return out;
    }

    bool operator < (Ngay other) {
        if (nam < other.nam) return true;
        if (nam == other.nam && thang < other.thang) return true;
        if (nam == other.nam && thang == other.thang && ngay < other.ngay) return true;
        return false;
    }
};

struct HopSua {
    string nhanHieu;
    double trongLuong;
    Ngay hanSuDung;

    friend istream &operator >> (istream &in, HopSua &hs) {
        string str;
        getline(in, str);
        size_t pos1 = str.find(',');
        size_t pos2 = str.find(',', pos1 + 1);

        hs.nhanHieu = str.substr(0, pos1);
        hs.trongLuong = stod(str.substr(pos1 + 2, pos2 - pos1 - 2));
        string stringNgay = str.substr(pos2 + 2);

        hs.hanSuDung.ngay = stoi(stringNgay.substr(0, 2));
        hs.hanSuDung.thang = stoi(stringNgay.substr(3, 2));
        hs.hanSuDung.nam = stoi(stringNgay.substr(6, 4));
        return in;
    }

    friend ostream &operator << (ostream &out, HopSua hs) {
        out << fixed <<setprecision(1);
        out << hs.nhanHieu << ", " << hs.trongLuong << ", " << hs.hanSuDung;
        return out;
    }
};

struct Node {
    HopSua data;
    Node *next;
    Node(HopSua data): data(data), next(nullptr) {}
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(HopSua n) {
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
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }

    void sapXep() {
        Node *current, *index;
        HopSua tmp;
        if (head == nullptr) return;
        else {
            for (current = head; current->next != nullptr; current = current->next) {
                for (index = current->next; index != nullptr; index = index->next) {
                    if (index->data.hanSuDung < current->data.hanSuDung) {
                        tmp = current->data;
                        current->data = index->data;
                        index->data = tmp;
                    }
                }
            }
        }
    }

    void dong1() {
        Node *tmp = head;
        int cnt(0);
        while (tmp != nullptr) {
            if (tmp->data.hanSuDung.nam < 2003) cnt++;
            tmp = tmp->next;
        }
        cout << cnt << endl;
    }

    void dong2() {
        Node *tmp = head->next;
        HopSua res = head->data;
        while (tmp != nullptr) {
            if (res.hanSuDung < tmp->data.hanSuDung)
                res = tmp->data;
            tmp = tmp->next;
        }
        cout << res << endl;
    }

    void dong3() {
        this->sapXep();
        Node *tmp = head;
        bool check = false;
        while (tmp != nullptr) {
            if (check) cout << ", ";
            cout << tmp->data.nhanHieu;
            check = true;
            tmp = tmp->next;
        }
    }
};

int main() {
    int n;
    LinkedList list;
    cin >> n;
    cin.ignore();

    while (n--) {
        HopSua tmp;
        cin >> tmp;
        list.add(tmp);
    }
    
    list.dong1();
    list.dong2();
    list.dong3();

    return 0;
}