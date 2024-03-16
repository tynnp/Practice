#include <iostream>
#include <iomanip>
using namespace std;

struct Ngay {
    int ngay, thang, nam;

    friend istream &operator >> (istream &in, Ngay &d) {
        in >> d.ngay >> d.thang >> d.nam;
        return in;
    }

    friend ostream &operator << (ostream &out, Ngay d) {
        out << d.ngay << "/" << d.thang << "/" << d.nam;
        return out;
    }
};

struct HopSua {
    string nhanHieu;
    double trongLuong;
    Ngay hanSuDung;

    friend istream &operator >> (istream &in, HopSua &t) {
        in >> t.nhanHieu >> t.trongLuong >> t.hanSuDung;
        return in;
    }

    friend ostream &operator << (ostream &out, HopSua t) {
        out << fixed << setprecision(1);
        out << t.nhanHieu << endl;
        out << t.trongLuong << endl;
        out << t.hanSuDung << endl;
        return out;
    }
};

int main() {
    HopSua a;
    cin >> a;
    cout << a;
    return 0;
}