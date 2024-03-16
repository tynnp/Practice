#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    friend istream& operator >> (istream& in, PhanSo& p);
    friend ostream& operator << (ostream& out, PhanSo p);
    bool operator == (PhanSo p);
    bool operator != (PhanSo p);
    PhanSo operator + (PhanSo p);
};

struct MangPhanSo {
    int size;
    PhanSo* values;

    friend istream& operator >> (istream& in, MangPhanSo& arr);
    friend ostream& operator << (ostream& out, MangPhanSo arr);
    PhanSo operator [] (int index);
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    MangPhanSo arr; cin >> arr;
    PhanSo res = arr.values[0];
    for (int i = 1; i < arr.size; i++)
        res = res + arr.values[i];
    cout << res;
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
    out << p.tu << '/' << p.mau;
    return out;
}

bool PhanSo::operator == (PhanSo p) {
    return this->tu*p.mau == this->mau*p.tu;
}

bool PhanSo::operator != (PhanSo p) {
    return !(*this == p);
}

PhanSo PhanSo::operator + (PhanSo p) {
    PhanSo res;
    res.tu = this->tu*p.mau + this->mau*p.tu;
    res.mau = this->mau * p.mau;
    return res;
}

istream& operator >> (istream& in, MangPhanSo& arr) {
    arr.values = new PhanSo[100];
    arr.size = 0;
    while (in >> arr.values[arr.size]) arr.size++;
    return in;
}

ostream& operator << (ostream& out, MangPhanSo arr) {
    for (int i = 0; i < arr.size; i++)
        out << arr.values[arr.size] << " ";
    return out;
}

PhanSo MangPhanSo::operator [] (int index) {
    if (index >= 0 && index < this->size)
        return this->values[index];
}