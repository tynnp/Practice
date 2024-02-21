#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;

    bool operator < (PhanSo other) {
        return tu*other.mau < mau*other.tu;
    }
};

istream &operator >> (istream &in, PhanSo& p) {
    in >> p.tu >> p.mau;
    return in;
}

ostream &operator << (ostream &out, PhanSo p) {
    out << p.tu << "/" << p.mau;
    return out;
}

template <typename T>
void max3So() {
    T a, b, c;
    cin >> a >> b >> c;
    T max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    cout << max;
}

int main() {
    char kt; cin >> kt;

    switch(kt) {
        case 'a': max3So<int>(); break;
        case 'b': max3So<double>(); break;
        case 'c': max3So<PhanSo>(); break;
    }

    return 0;
}