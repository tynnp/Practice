#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

struct Ngay {
    int ngay, thang, nam;

    friend istream &operator >> (istream &in, Ngay &n) {
        string tmp;
        in.ignore();
        getline(in, tmp);
        n.ngay = stoi(tmp.substr(0, 2));
        n.thang = stoi(tmp.substr(3, 2));
        n.nam = stoi(tmp.substr(6, 4));
        return in;
    }

    friend ostream &operator << (ostream &out, Ngay n) {
        if (n.ngay < 10) out << 0;
        out << n.ngay << "/";
        if (n.thang < 10) out << 0;
        out << n.thang << "/";
        out << n.nam;
        return out; 
    }
};

struct SoTietKiem {
    string maSo;
    string loaiTietKiem;
    string hoTenKhachHang;
    long long CMND;
    Ngay ngay;
    double soTienGui;

    friend istream &operator >> (istream &in, SoTietKiem &s) {
        in >> s.maSo;
        in.ignore();
        getline(in, s.loaiTietKiem);
        getline(in, s.hoTenKhachHang);
        in >> s.CMND >> s.ngay >> s.soTienGui;
        return in;
    }

    friend ostream &operator << (ostream &out, SoTietKiem s) {
        out << fixed << setprecision(0);
        out << s.maSo << "-" << s.loaiTietKiem << "-" << s.hoTenKhachHang;
        out << "-" << s.CMND << "-" << s.ngay << "-" << s.soTienGui;
        return out;
    }
};

struct Node {
    SoTietKiem data;
    Node *next;
    Node(SoTietKiem data): data(data), next(nullptr) {}
};

struct LinkedList {
    Node *head;
    LinkedList(): head(nullptr) {}

    void add(SoTietKiem s) {
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

    double tongSoTien() {
        double res = 0;
        Node *tmp = head;

        while (tmp != nullptr) {
            res += tmp->data.soTienGui;
            tmp = tmp->next;
        }

        return res;
    }

    SoTietKiem find(long long n) {
        Node *tmp = head;
        while (tmp != nullptr) {
            if (tmp->data.CMND == n) 
                return tmp->data;
            tmp = tmp->next;
        }
    }
};

int main() {
    LinkedList list;
    long long cccd, n;
    cin >> cccd >> n;

    while (n--) {
        SoTietKiem tmp;
        cin >> tmp;
        list.add(tmp);
    }

    list.print();
    cout << fixed << setprecision(0);
    cout << list.tongSoTien() << endl;
    cout << list.find(cccd);
    return 0;
}