#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;

        if (p.mau < 0) 
            p.tu = -p.tu, p.mau = -p.mau;

        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        int ucln = __gcd(p.tu, p.mau);
        p.tu /= ucln, p.mau /= ucln;

        out << p.tu << "/" << p.mau;
        return out;
    }

    PhanSo operator + (PhanSo other) {
        PhanSo res;
        res.tu = tu*other.mau + mau*other.tu;
        res.mau = mau * other.mau;
        return res;
    }
};

template <typename T>
struct Array {
    int size;
    T values[100];

    void input() {
        size = 0;
        T n;
        while (cin >> n) 
            values[size++] = n;
    }

    T tinhTong() {
        T res = values[0];
        for (int i = 1; i < size; i++)
            res = res + values[i];
        return res;
    }
};

template<typename T>
T tongDaySo() {
    Array<T> arr;
    arr.input();
    return arr.tinhTong();
}

int main() {
    char c; 
    cin >> c;

    switch (c) {
        case 'a': cout << tongDaySo<int>(); break;
        case 'b': cout << tongDaySo<PhanSo>(); break;
    }

    return 0;
}