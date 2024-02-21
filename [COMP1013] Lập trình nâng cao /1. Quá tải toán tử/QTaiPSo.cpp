#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu;
    int mau;
};

istream& operator >> (istream& in, PhanSo& p);
ostream& operator << (ostream& out, PhanSo p);
PhanSo operator + (PhanSo p1, PhanSo p2);
bool operator == (PhanSo p1, PhanSo p2);
bool operator != (PhanSo p1, PhanSo p2);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    PhanSo a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}

istream& operator >> (istream& in, PhanSo& p) {
    in >> p.tu >> p.mau;
    return in;
}

ostream& operator << (ostream& out, PhanSo p) {
    int ucln = __gcd(p.tu, p.mau);
    p.tu /= ucln;
    p.mau /= ucln;
    out << p.tu << "/" << p.mau;
    return out;
}

PhanSo operator + (PhanSo p1, PhanSo p2) {
    PhanSo res;
    res.tu = p1.tu*p2.mau + p1.mau*p2.tu;
    res.mau = p1.mau * p2.mau;
    return res;
}

bool operator == (PhanSo p1, PhanSo p2) {
    return p1.tu*p2.mau == p1.mau*p2.tu;
}

bool operator != (PhanSo p1, PhanSo p2) {
    return !(p1 == p2);
}