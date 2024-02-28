#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    bool operator == (PhanSo other) {
        return tu*other.mau == mau*other.tu;
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
        case 'c': soSanh<PhanSo>(); break;
    }

    return 0;
}