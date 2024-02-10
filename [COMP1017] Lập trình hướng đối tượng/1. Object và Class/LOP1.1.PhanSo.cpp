#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;
public:
    PhanSo() {}

    PhanSo(int tu, int mau): tu(tu), mau(mau) {}

    PhanSo(const PhanSo &p) {
        this->tu = p.tu;
        this->mau = p.mau;
    } 

    ~PhanSo() {}

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        int ucln = __gcd(p.tu, p.mau);
        p.tu /= ucln;
        p.mau /= ucln;

        if (p.mau < 0)
            p.tu = -p.tu,
            p.mau = -p.mau;

        out << p.tu << "/" << p.mau;
        return out;
    }
};

int main() {
    PhanSo p;
    cin >> p;
    cout << p;
    return 0;
}