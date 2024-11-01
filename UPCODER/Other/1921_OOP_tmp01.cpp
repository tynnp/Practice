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
};

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    PhanSo psA(a, b);
    PhanSo psB(x, y);

    psA.output();
    psB.output();
    cout << psA.getTu() + psB.getMau() << endl;
    cout << psA.getGiaTri() << ' ' << psB.getGiaTri() << endl;
    (psA.psRutGon()).output();
    (psB.psNghichDao()).output();

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