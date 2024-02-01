#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

struct PhanSo {
    int tu;
    int mau;

    PhanSo operator + (PhanSo p)  {
        PhanSo res;
        res.tu = this->tu*p.mau + p.tu*this->mau;
        res.mau = this->mau * p.mau;
        return res;
    }

    bool operator == (PhanSo p)  {
        double value1 = (double) this->tu / this->mau;
        double value2 = (double) p.tu / p.mau;
        return value1 == value2;
    }

    bool operator != (PhanSo p)  {
        double value1 = (double) this->tu / this->mau;
        double value2 = (double) p.tu / p.mau;
        return value1 != value2;
    }
};

istream& operator >> (istream& in, PhanSo& p) {
    in >> p.tu >> p.mau;
    return in;
}

ostream& operator << (ostream& out, PhanSo p) {
    int ucln = gcd(p.tu, p.mau);
    p.tu /= ucln;
    p.mau /= ucln;
    out << p.tu << "/" << p.mau;
}

int main() {
    PhanSo phanSo1, phanSo2;
    cin >> phanSo1 >> phanSo2;
    cout << phanSo1 + phanSo2;
    return 0;
}