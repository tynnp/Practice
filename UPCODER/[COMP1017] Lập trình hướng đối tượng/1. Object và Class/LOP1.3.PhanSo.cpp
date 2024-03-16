#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'
using namespace std;

class PhanSo {
private:
    int tu, mau;
public: 
    PhanSo() {
        this->tu = 0;
        this->mau = 0;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    PhanSo(int n) {
        this->tu = n;
        this->mau = 1;
    }

    PhanSo(const PhanSo &p) {
        this->tu = p.tu;
        this->mau = p.mau;
    }

    ~PhanSo() {}

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        if (p.mau < 0) 
            p.tu = -p.tu, 
            p.mau = -p.mau;
        return in;
    }

    PhanSo nghichDao() {
        PhanSo res;
        res.tu = this->mau;
        res.mau = this->tu;
        return res;
    }

    void rutGon() {
        int ucln = __gcd(this->tu, this->mau);
        this->tu /= ucln;
        this->mau /= ucln;
        return;
    }

    void xuat() {
        cout << this->tu << "/" << this->mau;
        return;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        p.rutGon();
        out << p.tu << "/" << p.mau;
        return out;
    }

    int getTu() {
        this->rutGon();
        return this->tu;
    }

    int getMau() {
        this->rutGon();
        return this->mau;
    }

    void setTu(int tu) {
        this->tu = tu;
        return;
    }

    void setMau(int mau) {
        this->mau = mau;
        if (this->mau < 0) 
            this->mau = -this->mau,
            this->tu = -this->tu;
        return;
    }

    PhanSo operator + (PhanSo other) {
        PhanSo res;
        res.tu = this->tu*other.mau + this->mau*other.tu;
        res.mau = this->mau * other.mau;
        return res;
    }

    PhanSo operator - (PhanSo other) {
        PhanSo res;
        res.tu = this->tu*other.mau - this->mau*other.tu;
        res.mau = this->mau * other.mau;
        return res;
    }

    PhanSo operator * (PhanSo other) {
        PhanSo res;
        res.tu = this->tu * other.tu;
        res.mau = this->mau * other.mau;
        return res;
    }

    PhanSo operator / (PhanSo other) {
        PhanSo res;
        res.tu = this->tu * other.mau;
        res.mau = this->mau * other.tu;
        return res;
    }

    bool operator < (PhanSo other) {
        return (double) this->tu/this->mau < (double) other.tu/other.mau;
    }

    bool operator > (PhanSo other) {
        return (double) this->tu/this->mau > (double) other.tu/other.mau;
    }

    bool operator == (PhanSo other) {
        return this->tu*other.mau == this->mau*other.tu;
    }

    bool operator <= (PhanSo other) {
        return *this < other || *this == other;
    }

    bool operator >= (PhanSo other) {
        return *this > other || *this == other;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    PhanSo f1; cin >> f1;
    f1.xuat(); cout << endl;
    cout << f1.getTu() << endl;
    cout << f1.getMau() << endl;
    cout << f1.nghichDao() << endl;
    f1.rutGon(); cout << f1 << endl;
    cout << f1 + f1.nghichDao();
    return 0;
}