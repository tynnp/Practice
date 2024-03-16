#include <iostream>
using namespace std;

struct Ngay {
    int ngay, thang, nam;

    friend istream &operator >> (istream &in, Ngay &n) {
        string str;
        getline(in, str);

        if (str.length() > 8) {
            n.ngay = stoi(str.substr(0, 2));
            n.thang = stoi(str.substr(3, 2));
            n.nam = stoi(str.substr(6, 4));
        } else {
            n.ngay = stoi(str.substr(0, 2));
            n.thang = stoi(str.substr(2, 2));
            n.nam = stoi(str.substr(4, 4));
        }

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

struct CauThu {
    string maCauThu;
    string tenCauThu;
    Ngay ngaySinh;

    friend istream &operator >> (istream &in, CauThu &ct) {
        getline(in, ct.maCauThu);
        getline(in, ct.tenCauThu);
        in >> ct.ngaySinh;
    }

    friend ostream &operator << (ostream &out, CauThu ct) {
        out << ct.maCauThu << endl;
        out << ct.tenCauThu << endl;
        out << ct.ngaySinh;
        return out;
    }
};

int main() {
    CauThu a;
    cin >> a;
    cout << a;
    return 0;
}