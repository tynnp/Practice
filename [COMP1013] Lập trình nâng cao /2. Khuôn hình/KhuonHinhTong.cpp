#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        if (p.mau < 0) 
            p.tu = -p.tu,
            p.mau = -p.mau;
        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        int ucln = __gcd(p.tu, p.mau);
        p.tu /= ucln;
        p.mau /= ucln;
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
    int size = 0;
    T values[100];

    void input() {
        T n; cin >> n;
        this->values[this->size++] = n;
        return;
    }

    T sum() {
        T res = this->values[0];
        for (int i = 1; i < this->size; i++)
            res = res + this->values[i];
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c; 
    Array<int> arrInt;
    Array<PhanSo> arrPhanSo;

    while (cin >> c) {
        if (c == 'a') arrInt.input();
        else if (c == 'b') arrPhanSo.input();
    }

    if (arrInt.size != 0) cout << arrInt.sum() << endl;
    else cout << "khong co" << endl;

    if (arrPhanSo.size != 0) cout << arrPhanSo.sum() << endl;
    else cout << "khong co" << endl;

    return 0;
}