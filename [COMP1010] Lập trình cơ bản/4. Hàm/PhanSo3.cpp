#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;

    void nhap() {
        cin >> tu >> mau;
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

    PhanSo res, arr[100];
    int a, b, n = 0;

    while (cin >> a >> b) 
        arr[n].tu = a, arr[n].mau = b,  
        n++;

    res = arr[0];
    for (int i = 1; i < n; i++)
        res.tu = res.tu*arr[i].mau + arr[i].tu*res.mau,
        res.mau = res.mau*arr[i].mau;

    res.rutGon();
    res.xuat();
    return 0;
}