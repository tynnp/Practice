#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;

struct PhanSo {
    int tu, mau;

    PhanSo tong(PhanSo other) {
        PhanSo res;
        res.tu = tu*other.mau + mau*other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo hieu(PhanSo other) {
        PhanSo res;
        res.tu = tu*other.mau - mau*other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo tich(PhanSo other) {
        PhanSo res;
        res.tu = tu * other.tu;
        res.mau = mau * other.mau;
        return res;
    }

    PhanSo thuong(PhanSo other) {
        PhanSo res;
        res.tu = tu * other.mau;
        res.mau = mau * other.tu;
        return res;
    }
};

void xuat(PhanSo res) {
    int ucln = __gcd(res.tu, res.mau);
    res.tu /= ucln;
    res.mau /= ucln;

    if (res.mau < 0) 
        res.tu = -res.tu, res.mau = -res.mau;

    cout << res.tu;
    if (res.tu != 0) cout << "/" << res.mau;
    cout << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    PhanSo arr[2];
    bool check = false;

    for (int i = 0; i < 2; i++) {
        cin >> arr[i].tu >> arr[i].mau;
        if (arr[i].mau == 0) check = true;
    }

    if (check) cout << -1;
    else {
        xuat(arr[0].tong(arr[1]));
        xuat(arr[0].hieu(arr[1]));
        xuat(arr[0].tich(arr[1]));
        if (arr[1].tu != 0) xuat(arr[0].thuong(arr[1]));
    }

    return 0;
}