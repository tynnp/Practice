#include <iostream>
#include <algorithm>
using namespace std;

class PhanSo {
protected:
    int tu, mau;
public:
    PhanSo() {}
    PhanSo(int tuSo, int mauSo): tu(tuSo), mau(mauSo) {}
    
    PhanSo(const PhanSo &other) {
        tu = other.tu;
        mau = other.mau;
    }

    void nhap() {
        cin >> tu >> mau;
        return;
    }

    void xuat() {
        cout << tu << "/" << mau;
        return;
    }

    int getTuSo() {
        return tu;
    }

    int getMauSo() {
        return mau;
    }

    PhanSo congPhanSo(PhanSo other) {
        PhanSo res;
        res.tu = tu*other.mau + mau*other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo rutGon() {
        PhanSo res;
        int ucln = __gcd(tu, mau);
        res.tu = tu / ucln;
        res.mau = mau / ucln;
        return res;
    }
};

class HonSo : public PhanSo {
private:
    int phanNguyen;
public:
    void nhap() {
        cin >> phanNguyen;
        PhanSo::nhap();
        if (phanNguyen < 0) tu = -tu;
        return;
    }

    void xuat() {
        cout << phanNguyen << " ";
        if (mau < 0) mau = -mau, tu = -tu;
        PhanSo::xuat();
        return;
    }

    int getPhanNguyen() {
        return phanNguyen;
    }

    HonSo congHonSo(HonSo other) {
        HonSo res;
        res.tu = tu*other.mau + mau*other.tu;
        res.mau = mau * other.mau;
        res.phanNguyen = phanNguyen + other.phanNguyen;
        return res;
    } 

    HonSo rutGon() {
        HonSo res;
        int ucln = __gcd(tu, mau);
        res.tu = tu / ucln;
        res.mau = mau / ucln;
        res.phanNguyen = phanNguyen;
        return res;
    }
};

int main() {
    HonSo a, b, res;
    a.nhap();
    b.nhap();
    res = (a.congHonSo(b)).rutGon();
    res.xuat();
    return 0;
}