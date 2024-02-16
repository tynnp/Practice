#include <iostream>
using namespace std;

struct HinhChuNhat {
    double dai;
    double rong;

    friend istream& operator >> (istream &in, HinhChuNhat &hcn) {
        in >> hcn.dai >> hcn.rong;
        return in;
    }

    friend ostream& operator << (ostream &out, HinhChuNhat hcn) {
        out << "[HCN] " << hcn.dai << ", " << hcn.rong;
        return out;
    }

    double chuVi() {
        return (this->dai + this->rong) * 2;
    }

    bool operator < (HinhChuNhat hcn) {
        return this->chuVi() < hcn.chuVi();
    }

    double operator + (double x) {
        return this->chuVi() + x;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    HinhChuNhat a, b;
    cin >> a >> b; 
    cout << a << endl << b << endl;
    cout << (a < b ? "true" : "false");
    return 0;
}