#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    void nhap() {
        cin >> tu >> mau;
        if (mau < 0) 
            tu = -tu, 
            mau = -mau;
        return;
    }

    void xuat() {
        cout << tu << "/" << mau;
        return;
    }

    void rutGon() {
        int ucln = __gcd(tu, mau);
        tu /= ucln;
        mau /= ucln;
        return;
    }
};



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size; cin >> size;
    PhanSo arr[size];
    for (PhanSo &x : arr) x.nhap();

    PhanSo res = arr[0];
    for (int i = 1; i < size; i++)
        if ((double) arr[i].tu/arr[i].mau < (double) res.tu/res.mau)
            res = arr[i];

    res.rutGon();
    res.xuat();
    return 0;
}