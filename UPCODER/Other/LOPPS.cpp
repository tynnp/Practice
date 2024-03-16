#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu, mau;
public:
    friend istream &operator >> (istream &in, PhanSo &phanSo) {
        in >> phanSo.tu >> phanSo.mau;
        if (phanSo.mau < 0) 
            phanSo.mau = - phanSo.mau, 
            phanSo.tu = - phanSo.tu;
        return in;
    } 

    friend ostream &operator << (ostream &out, PhanSo phanSo) {
        out << phanSo.tu << "/" << phanSo.mau;
        return out;
    }

    int getTu() {
        return tu;
    }

    int getMau() {
        return mau;
    }

    void setTu(int tu) {
        this->tu = tu;
        return;
    }

    void setMau(int mau) {
        this->mau = mau;
        return;
    }

    PhanSo ngichDao() {
        PhanSo res;
        res.tu = mau;
        res.mau = tu;
        return res;
    }

    PhanSo rutGon() {
        PhanSo res;
        int ucln = __gcd(tu, mau);
        res.tu = tu / ucln;
        res.mau = mau / ucln;
        return res;
    }

    PhanSo operator + (PhanSo other) {
        PhanSo res;
        res.tu = tu*other.mau + mau*other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo operator - (PhanSo other) {
        PhanSo res;
        res.tu = tu*other.mau - mau*other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo operator * (PhanSo other) {
        PhanSo res;
        res.tu = tu * other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo operator / (PhanSo other) {
        PhanSo res;
        res.tu = tu * other.mau;
        res.mau = mau * other.tu;
        return res;
    }

    PhanSo operator + (int k) {
        PhanSo res;
        res.tu = tu + k;
        res.mau = mau + k;
        return res;
    }
};

int main() {
    PhanSo x;
    int k;
    cin >> x >> k;
    cout << x.getTu() << endl;
    cout << x.getMau() << endl;
    cout << x.ngichDao() << endl;
    cout << x.rutGon() << endl;
    cout << x + k << endl;
    cout << (x * (x+k)).rutGon();
    return 0;
}