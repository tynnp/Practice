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
void soSanh() {
    T a, b;
    cin >> a >> b;
    cout << (a == b ? "true" : "false");
    return;
}

int main() {
    char kt; 
    cin >> kt;

    switch (kt) {
        case 'a': soSanh<int>(); break;
        case 'b': soSanh<double>(); break;
        case 'c': soSanh<double>(); break;
    }

    return 0;
}