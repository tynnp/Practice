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

    bool operator < (PhanSo other) {
        return (double) this->tu/this->mau < (double) other.tu/other.mau;
    }
};

template <typename T>
T max3So(T a, T b, T c) {
    T max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    return max;
}

int main() {
    char kt; cin >> kt;

    if (kt == 'a') {
        int a, b, c; 
        cin >> a >> b >> c;
        cout << max3So(a, b, c);

    } else if (kt == 'b') {
        double a, b, c;
        cin >> a >> b >> c;
        cout << max3So(a, b, c);

    } else if (kt == 'c') {
        PhanSo a, b, c;
        cin >> a >> b >> c;
        cout << max3So(a, b, c);
    }

    return 0;
}