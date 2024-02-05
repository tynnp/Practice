
// Đúng 11/12 testcase, sai testcase 10

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    void rutGon() {
        int ucln = __gcd(this->tu, this->mau);
        this->tu /= ucln;
        this->mau /= ucln;
        return;
    }

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        p.rutGon();
        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        if (p.tu < 0 || p.mau < 0) out << "-";
        out << abs(p.tu) << "/" << (p.mau);
        return out;
    }
};

struct SoPhuc {
    int thuc;
    int ao;

    friend istream& operator >> (istream &in, SoPhuc &sp) {
        in >> sp.thuc >> sp.ao;
        return in;
    }

    friend ostream& operator << (ostream &out, SoPhuc sp) {
        if (sp.thuc != 0) out << sp.thuc;

        if (sp.ao != 0) {
            if (sp.ao > 0 && sp.thuc != 0) out << "+";
            if (sp.ao < 0) out << "-";
            if (abs(sp.ao) != 1) 
                out << abs(sp.ao);
            out << "i";
        } 
        
        return out;
    }

    SoPhuc operator + (SoPhuc sp) {
        SoPhuc res;
        res.thuc = this->thuc + sp.thuc;
        res.ao = this->ao + sp.ao;
        return res;
    }

    SoPhuc operator + (int x) {
        SoPhuc res;
        res.thuc = this->thuc + x;
        res.ao = this->ao;
        return res;
    }

    SoPhuc operator + (PhanSo p) {
        SoPhuc res;
        res.thuc = this->thuc + p.tu;
        res.ao = this->ao + p.mau;
        return res;
    }
};

int main() {
    SoPhuc x; cin >> x;
    char c; cin >> c;
    cout << x << endl;

    int i; SoPhuc z; PhanSo p;
    if (c == 'i') {
        cin >> i;
        cout << i << endl;
        cout << x + i;
    } else if (c == 'z') {
        cin >> z;
        cout << z << endl;
        cout << x + z;
    } else if (c == 'p') {
        cin >> p;
        cout << p << endl;
        cout << x + p;
    }

    return 0;
}