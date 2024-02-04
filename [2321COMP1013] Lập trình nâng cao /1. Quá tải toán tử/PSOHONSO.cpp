#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    friend istream& operator >> (istream& in, PhanSo& other) {
        in >> other.tu >> other.mau;
        return in;
    }

    friend ostream& operator << (ostream& out, PhanSo other) {
        int ucln = __gcd(other.tu, other.mau);
        other.tu /= ucln;
        other.mau /= ucln;
        out << other.tu << "/" << other.mau;
        return out;
    }

    bool operator != (PhanSo other) {
        return this->tu*other.mau != this->mau*other.tu;
    }
};

struct HonSo {
    PhanSo phanSo;
    int phanNguyen;

    friend istream& operator >> (istream& in, HonSo& other) {
        in >> other.phanNguyen >> other.phanSo;
        return in;
    }

    friend ostream& operator << (ostream& out, HonSo other) {
        if (other.phanNguyen != 0)
            out << other.phanNguyen << " ";
        out << other.phanSo;
        return out;
    }

    HonSo chuyenDoi(string str = "true") {
        PhanSo tmp;
        HonSo res;
        tmp.tu = this->phanNguyen*this->phanSo.mau + this->phanSo.tu;
        tmp.mau = this->phanSo.mau;
        
        int ucln = __gcd(tmp.tu, tmp.mau);
        tmp.tu /= ucln;
        tmp.mau /= ucln;
        
        if (str == "false") {
            res.phanNguyen = 0;
            res.phanSo = tmp;
        } else {
            res.phanSo.mau = tmp.mau;
            res.phanSo.tu = tmp.tu % tmp.mau;
            res.phanNguyen = tmp.tu / tmp.mau;
        }

        return res;
    }

    bool operator != (HonSo other) {
        HonSo a = this->chuyenDoi("false");
        HonSo b = other.chuyenDoi("false");
        return a.phanSo != b.phanSo;
    }

    int tongCacThanhPhan() {
        return this->phanNguyen + this->phanSo.tu + this->phanSo.mau;
    }

    bool operator > (HonSo other) {
        return this->tongCacThanhPhan() > other.tongCacThanhPhan();
    }
};

int main() {
    HonSo a, b; cin >> a >> b;
    string str; cin >> str;

    a = a.chuyenDoi(str);
    b = b.chuyenDoi(str); 

    cout << (a != b ? "TRUE" : "FALSE") << endl;
    cout << (a > b ? "TRUE" : "FALSE") << endl;
    cout << a << endl << b << endl;

    return 0;
}