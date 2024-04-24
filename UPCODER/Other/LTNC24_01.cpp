#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;
};

void rutGon(PhanSo &obj) {
    int ucln = __gcd(obj.tu, obj.mau);
    obj.tu /= ucln, obj.mau /= ucln;
    if (obj.mau < 0) obj.tu = -obj.tu, obj.mau = -obj.mau;
}

istream &operator >> (istream &in, PhanSo &obj) {
    in >> obj.tu >> obj.mau;
    rutGon(obj);
    return in;
}

ostream &operator << (ostream &out, PhanSo obj) {
    rutGon(obj);
    out << obj.tu << '/' << obj.mau;
    return out;
}

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu*b.mau + a.mau*b.tu;
    res.mau = a.mau * b.mau;
    rutGon(res);
    return res;
}

PhanSo operator - (PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu*b.mau - a.mau*b.tu;
    res.mau = a.mau * b.mau;
    rutGon(res);
    return res;
}

PhanSo operator * (PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu * b.tu;
    res.mau = a.mau * b.mau;
    rutGon(res);
    return res;
}

PhanSo operator / (PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu*b.mau;
    res.mau = a.mau*b.tu;
    rutGon(res);
    return res;
}

int main() {
    int size = 0;
    PhanSo arr[100];

    while (cin >> arr[size]) size++;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    PhanSo cong, tru, nhan, chia;
    cong = tru = nhan = chia = arr[0];

    for (int i = 1; i < size; i++)
        cong = cong + arr[i],
        tru = tru - arr[i],
        nhan = nhan * arr[i], 
        chia = chia / arr[i];

    cout << cong << endl;
    cout << tru << endl;
    cout << nhan << endl;
    cout << chia << endl;
    return 0;
}