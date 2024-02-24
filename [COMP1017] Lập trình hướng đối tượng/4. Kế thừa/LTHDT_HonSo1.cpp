#include <iostream>
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
};

class HonSo : public PhanSo {
private:
    int phanNguyen;
public:
    void nhap() {
        cin >> phanNguyen;
        PhanSo::nhap();
        return;
    }

    void xuat() {
        cout << phanNguyen << " ";
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
};

int main() {
    HonSo a, b, res;
    a.nhap();
    b.nhap();
    res = a.congHonSo(b);
    res.xuat();
    return 0;
}