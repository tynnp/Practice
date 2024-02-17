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

    bool operator < (PhanSo other) {
        return (double) this->tu/this->mau < (double) other.tu/other.mau;
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

    T min() {
        T min = this->values[0];
        for (int i = 1; i < this->size; i++)
            if (this->values[i] < min)
                min = this->values[i];
        return min;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char c; 
    Array<int> arrInt;
    Array<double> arrDouble;
    Array<PhanSo> arrPhanSo;

    while (cin >> c) {
        if (c == 'a') arrInt.input();
        else if (c == 'b') arrDouble.input();
        else if (c == 'c') arrPhanSo.input();
    }

    if (arrInt.size > 0) cout << arrInt.min() << endl;
    else cout << "khong co" << endl;

    if (arrDouble.size > 0) cout << arrDouble.min() << endl;
    else cout << "khong co" << endl;

    if (arrPhanSo.size > 0) cout << arrPhanSo.min() << endl;
    else cout << "khong co" << endl;

    return 0;
}