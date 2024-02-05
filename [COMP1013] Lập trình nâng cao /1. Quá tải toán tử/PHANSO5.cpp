#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    void rutGon() {
        int ucln = __gcd(this->tu, this->mau);
        this->tu /= ucln;
        this->mau /= ucln;

        if (this->mau < 0) 
            this->tu = -this->tu,
            this->mau = -this->mau;

        return;
    }

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        p.rutGon();
        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    // Tiền tố
    PhanSo operator ++ () {
        this->tu += 1;
        return *this;
    }

    PhanSo operator -- () {
        this->tu -= 1;
        return *this;
    }

    // Hậu tố
    PhanSo operator ++ (int) {
        PhanSo tmp = *this;
        this->tu += 1;
        return tmp;
    }

    PhanSo operator -- (int) {
        PhanSo tmp = *this;
        this->tu -= 1;
        return tmp;
    }
};

int main() {
    PhanSo a; cin >> a;
    char c; cin >> c;

    cout << a << endl;
    if (c == '+') cout << ++a;
    else cout << --a;

    return 0;
}