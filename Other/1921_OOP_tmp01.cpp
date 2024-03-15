
// Bài làm chưa hoàn thành 


#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

class PhanSo {
private:    
    int tu, mau;
public:
    ~PhanSo() {}

    PhanSo() {
        tu = 0;
        mau = 1;
    }

    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
        if (this->mau < 0)
            this->tu = -this->tu,
            this->mau = -this->mau;
    }

    PhanSo(const PhanSo &other) {
        this->tu = other.tu;
        this->mau = other.mau;
    }

    void setTu(int tu) {
        this->tu = tu;
    }

    int getTu() {
        return tu;
    }

    void setMau(int mau) {
        this->mau = mau;
        if (this->mau < 0)
            this->tu = -this->tu,
            this->mau = -this->mau;
    }

    int getMau() {
        return mau;
    }

    double getGiaTri() {
        return (double) tu/mau;
    }

    PhanSo psRutGon() {
        PhanSo res;
        int ucln = __gcd(tu, mau);
        res.tu = tu /= ucln;
        res.mau = mau /= ucln;
        return res;
    }

    PhanSo psNghichDao() {
        PhanSo res;
        res.tu = mau;
        res.mau = tu;

        if (res.mau < 0) 
            res.tu = -res.tu,
            res.mau = -res.mau;

        return res;
    }

    void output() {
        cout << tu << "/" << mau;
        cout << endl;
    }

    friend istream &operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        if (p.mau < 0)
            p.tu = -p.tu,
            p.mau = -p.mau;
        return in;
    }
};

int main() {
    PhanSo a, b;
    cin >> a >> b;
    a.output();
    b.output();
    cout << a.getTu() + b.getMau() << endl;
    cout << fixed << setprecision(3);
    cout << a.getGiaTri() << " " << b.getGiaTri() << endl;
    (a.psRutGon()).output();
    (b.psNghichDao().psRutGon()).output();
    return 0;
}   