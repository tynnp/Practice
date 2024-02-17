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
        res.tu = this->tu*other.mau + this->mau*other.tu;
        res.mau = this->mau * other.mau;
        return res;
    }
};

template <typename T>
struct Array {
    int size;
    T values[100];

    void input() {
        this->size = 0;
        T n;
        while (cin >> n) 
            this->values[this->size++] = n;
    }

    T tinhTong() {
        T res = this->values[0];
        for (int i = 1; i < this->size; i++)
            res = res + this->values[i];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c; cin >> c;

    if (c == 'a') {
        Array<int> array;
        array.input();
        cout << array.tinhTong();

    } else if (c == 'b') {
        Array<PhanSo> array;
        array.input();
        cout << array.tinhTong();
    }

    return 0;
}