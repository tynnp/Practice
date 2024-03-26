#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;
};

istream &operator >> (istream &in, PhanSo &p) {
    in >> p.tu >> p.mau;
    return in;
}

ostream &operator << (ostream &out, PhanSo p) {
    int ucln = __gcd(p.tu, p.mau);
    p.tu /= ucln;
    p.mau /= ucln;

    if (p.mau < 0) 
        p.tu *= -1,
        p.mau *= -1;

    if (p.tu % p.mau == 0) out << p.tu;
    else out << p.tu << "/" << p.mau;
    return out;
}


int main() {
    PhanSo tmp;
    while (cin >> tmp)
        cout << tmp << endl;
    return 0;
}