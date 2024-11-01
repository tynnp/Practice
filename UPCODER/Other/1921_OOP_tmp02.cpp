// Chua xong

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    int getTu();
    int getMau();

    PhanSo();
    PhanSo(int tu, int mau);
    PhanSo(const PhanSo &other);

    double getGiaTri();
    PhanSo psRutGon();
    PhanSo psNghichDao();
    void output();

    friend istream &operator >> (istream &in, PhanSo &phanSo);
    friend ostream &operator << (ostream &out, PhanSo phanSo);

    PhanSo operator + (PhanSo other);
    PhanSo operator - (PhanSo other);
    PhanSo operator * (PhanSo other);
    PhanSo operator / (PhanSo other);
};

int main() {
    int n, m;
    cin >> n >> m;

    PhanSo arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    PhanSo lonNhat(arr[0]), nhoNhat(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i].getGiaTri() <= nhoNhat.getGiaTri())
            nhoNhat = arr[i];
        
        if (arr[i].getGiaTri() >= lonNhat.getGiaTri())
            lonNhat = arr[i];
    }

    if (m == 0) {
        PhanSo tong = arr[0];
        for (int i = 1; i < n; i++)
            tong = tong + arr[i];
        cout << tong << (lonNhat * nhoNhat);
    }

    else {
        PhanSo hieu = arr[0];
        for (int i = 1; i < n; i++) 
            hieu = hieu - arr[i];
        cout << hieu << (lonNhat / nhoNhat);
    }

    return 0;
}

int PhanSo::getTu() {
    return tu;
}

int PhanSo::getMau() {
    return mau;
}

PhanSo::PhanSo() {
    tu = 0;
    mau = 1;
}

PhanSo::PhanSo(int tu, int mau) {
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }

    this->tu = tu;
    this->mau = mau;
}

PhanSo::PhanSo(const PhanSo &other) {
    tu = other.tu;
    mau = other.mau;
}

double PhanSo::getGiaTri() {
    return (double) tu / mau;
}

PhanSo PhanSo::psRutGon() {
    int ucln = __gcd(tu, mau);
    PhanSo res;
    res.tu = tu / ucln;
    res.mau = mau / ucln;

    if (res.mau < 0) {
        res.tu = -res.tu;
        res.mau = -res.mau;
    }

    return res;
}

PhanSo PhanSo::psNghichDao() {
    return PhanSo(mau, tu).psRutGon();
}

void PhanSo::output() {
    cout << fixed << setprecision(3) << tu << '/' << mau << endl;
}

istream &operator >> (istream &in, PhanSo &phanSo) {
    in >> phanSo.tu >> phanSo.mau;

    if (phanSo.mau < 0) {
        phanSo.tu = -phanSo.tu;
        phanSo.mau = -phanSo.mau;
    }

    return in;
}

ostream &operator << (ostream &out, PhanSo phanSo) {
    out << phanSo.tu << '/' << phanSo.mau << endl;
    return out;
} 

PhanSo PhanSo::operator + (PhanSo other) {
    PhanSo res;
    res.tu = tu * other.mau + mau * other.tu;
    res.mau = mau * other.mau;
    return res.psRutGon();
}

PhanSo PhanSo::operator - (PhanSo other) {
    PhanSo res;
    res.tu = tu * other.mau - mau * other.tu;
    res.mau = mau * other.mau;
    return res.psRutGon();
}

PhanSo PhanSo::operator * (PhanSo other) {
    PhanSo res;
    res.tu = tu * other.tu;
    res.mau = mau * other.mau;
    return res.psRutGon();
}

PhanSo PhanSo::operator / (PhanSo other) {
    PhanSo res;
    res.tu = tu * other.mau;
    res.mau = mau * other.tu;
    return res.psRutGon();
}