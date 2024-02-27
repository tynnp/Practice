#include <iostream>
#include <iomanip>
using namespace std;

struct GiangVien {
    string ten;
    int namSinh;
    string hocVi;
    double heSo;

    friend istream &operator >> (istream &in, GiangVien &gv) {
        in >> gv.ten >> gv.namSinh >> gv.hocVi >> gv.heSo;
        return in;
    }

    friend ostream &operator << (ostream &out, GiangVien gv) {
        out << gv.ten << endl;
        out << gv.namSinh << endl;
        out << gv.hocVi << endl;
        out << fixed << setprecision(1) << gv.heSo;
        return out;
    }

    double tinhLuong() {
        if (hocVi == "CN") return heSo*3600;
        else if (hocVi == "Ths" || hocVi == "ThS") return heSo*4500;
        else if (hocVi == "TS") return heSo*6000;
    }

    double operator + (GiangVien other) {
        return tinhLuong() + other.tinhLuong();
    }

    bool operator < (GiangVien other) {
        return tinhLuong() < other.tinhLuong();
    }
};

int main() {
    GiangVien a, b;
    cin >> a >> b;
    cout << a.tinhLuong() << endl;
    cout << b.tinhLuong() << endl;
    cout << (a < b ? b : a);
    return 0;
}