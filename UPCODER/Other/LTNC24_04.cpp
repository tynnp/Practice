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

bool operator < (PhanSo a, PhanSo b) {
    return (double) a.tu/a.mau < (double) b.tu/b.mau;
}

template<typename T> 
T soLonNhi(T a, T b, T c) {
    T arr[3];
    arr[0] = a, arr[1] = b, arr[2] = c;
    sort(arr, arr + 3);
    return arr[1];
}

template<typename T>
void run() {
    T a, b, c;
    cin >> a >> b >> c;
    cout << soLonNhi(a, b, c);
}

int main() {
    char kt;
    cin >> kt;
    
    switch (kt) {
        case 'N': run<int>(); break;
        case 'T': run<double>(); break;
        case 'P': run<PhanSo>(); break;
    }
    
    return 0;
}