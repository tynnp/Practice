#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct PhanSo {
    int tu, mau;
};

istream &operator >> (istream &in, PhanSo &p) {
    in >> p.tu >> p.mau;
    return in;
}

ostream &operator << (ostream &out, PhanSo p) {
    int ucln = __gcd(p.tu, p.mau);
    p.tu /= ucln;
    p.mau /= ucln;

    if (p.mau < 0) 
        p.tu *= -1,
        p.mau *= -1;

    if (p.tu % p.mau == 0) out << p.tu;
    else out << p.tu << "/" << p.mau;
    return out;
}

bool operator == (PhanSo a, PhanSo b) {
    return a.tu*b.mau == b.tu*a.mau;
}

bool operator != (PhanSo a, PhanSo b) {
    return !(a == b);
}

bool operator > (PhanSo a, PhanSo b) {
    return (double) a.tu/a.mau > (double) b.tu/b.mau;
} 

bool operator < (PhanSo a, PhanSo b) {
    return (double) a.tu/a.mau < (double) b.tu/b.mau;
}

PhanSo operator + (PhanSo a, PhanSo b) {
    PhanSo res;
    res.tu = a.tu*b.mau + b.tu*a.mau;
    res.mau = a.mau * b.mau;
    return res;
}

template <typename T>
struct Array {
    int size;
    T values[100];

    T &operator [] (int index) {
        return values[index];
    }
};

template <typename T> 
istream &operator >> (istream &in, Array<T> &arr) {
    in >> arr.size;
    for (int i = 0; i < arr.size; i++)
        in >> arr[i];
    return in;
}

template <typename T> 
ostream &operator << (ostream &out, Array<T> arr) {
    for (int i = 0; i < arr.size; i++)
        out << arr[i] << " ";
    return out;
}

template <typename T> 
bool operator == (Array<T> a, Array<T> b) {
    if (a.size != b.size) return false;
    for (int i = 0; i < a.size; i++)
        if (a[i] != b[i]) return false;
    return true;
}

template <typename T> 
bool operator != (Array<T> a, Array<T> b) {
    return !(a == b);
}

template <typename T>
bool operator > (Array<T> a, Array<T> b) {
    T tongA = a[0];
    T tongB = b[0];

    for (int i = 1; i < a.size; i++)
        tongA = tongA + a[i];

    for (int i = 1; i < b.size; i++)
        tongB = tongB + b[i];

    return tongA > tongB;
}

template <typename T> 
bool operator < (Array<T> a, Array<T> b) {
    T tongA = a[0];
    T tongB = b[0];

    for (int i = 1; i < a.size; i++)
        tongA = tongA + a[i];

    for (int i = 1; i < b.size; i++)
        tongB = tongB + b[i];

    return tongA < tongB;
}

template <typename T>
void run() {
    Array<T> a, b;
    cin >> a >> b;
    cout << fixed << setprecision(1);
    cout << a << endl;
    cout << b << endl;
    cout << (a == b ? "GIONG NHAU" : "KHAC NHAU") << endl;
    if (a > b) cout << "LON HON";
    else if (a < b) cout << "NHO HON";
    else cout << "BANG NHAU";
}

int main() {
    char kt;
    cin >> kt;

    switch (kt) {
        case 'a': run<int>(); break;
        case 'b': run<double>(); break;
        case 'c': run<PhanSo>(); break;
    }

    return 0;
}