#include <iostream>
using namespace std;

template <typename kdl>
kdl max3so(kdl a, kdl b) {
    return a > b ? a : b;
}

int uocChung(int a, int b) {
    if (b == 0) return a;
    return uocChung(b, a % b);
}

struct PhanSo {
    int tu;
    int mau;
    friend istream& operator >> (istream& in, PhanSo& ps) {
        in >> ps.tu >> ps.mau;
        return in;
    }
    friend ostream& operator << (ostream& out, PhanSo ps) {
        PhanSo res; int uoc = uocChung(ps.tu, ps.mau);
        res.tu = ps.tu / uoc;
        res.mau = ps.mau / uoc;
        out << res.tu << "/" << res.mau;
        return out;
    }
};

bool operator > (PhanSo ps1, PhanSo ps2) {
    double kq1 = (double) ps1.tu/ps1.mau;
    double kq2 = (double) ps2.tu/ps2.mau;
    return kq1 > kq2;
}
 
int main() {
    char kt; cin >> kt;
    switch (kt) {
        case 'a':
            int a1, b1, c1; cin >> a1 >> b1 >> c1;
            cout << max3so(a1, max3so(c1, b1));
            break;
        case 'b':
            double a2, b2, c2; cin >> a2 >> b2 >> c2;
            cout << max3so(a2, max3so(c2, b2));
            break;
        case 'c':
            PhanSo a3, b3, c3; cin >> a3 >> b3 >> c3;
            cout << max3so(a3, max3so(c3, b3));
            break;
    }
    return 0;
}