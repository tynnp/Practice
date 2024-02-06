#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;

        int ucln = __gcd(p.tu, p.mau);
        p.tu /= ucln;
        p.mau /= ucln;

        if (p.mau < 0)
            p.tu = -p.tu,
            p.mau = -p.mau;

        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    bool operator == (PhanSo other) {
        return this->tu*other.mau == this->mau*other.tu;
    }
};

template <typename T>
string soSanh(T a, T b) {
    if (a == b) return "true";
    else return "false";
}

int main() {
    char kt; cin >> kt;

    if (kt == 'a') {
        int a, b; cin >> a >> b;
        cout << soSanh(a, b);

    } else if (kt == 'b') {
        double a, b; cin >> a >> b;
        cout <<soSanh(a, b);

    } else if (kt == 'c') {
        PhanSo a, b; cin >> a >> b;
        cout << soSanh(a, b);
    }

    return 0;
}