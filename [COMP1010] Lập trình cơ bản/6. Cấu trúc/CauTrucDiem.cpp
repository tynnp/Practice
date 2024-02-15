#include <iostream>
#include <cmath>
#include <iomanip>
#define endl '\n'
using namespace std;

struct Diem {
    int x, y; 

    void nhap() {
        cin >> x >> y;
    }

    void xuat() {
        cout << "(" << x << "," << y << ")";
        return;
    }

    double tinhDoDai(Diem other) {
        return (double) sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }
};

double chuVi(Diem a, Diem b, Diem c) {
    double AB = a.tinhDoDai(b);
    double BC = b.tinhDoDai(c);
    double CA = c.tinhDoDai(a);
    return AB + BC + CA;
}

double dienTich(Diem a, Diem b, Diem c) {
    double AB = a.tinhDoDai(b);
    double BC = b.tinhDoDai(c);
    double CA = c.tinhDoDai(a);
    double p = (AB + BC + CA)/2;
    return sqrt(p * (p-AB) * (p-BC) * (p-CA));
}

bool thangHang(Diem a, Diem b, Diem c) {
    return dienTich(a, b, c) <= 0.00001;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Diem a, b, c;
    a.nhap();
    b.nhap();
    c.nhap();

    a.xuat(); cout << " ";
    b.xuat(); cout << " ";
    c.xuat(); cout << endl;

    cout << fixed << setprecision(3);
    cout << a.tinhDoDai(b) << endl;
    cout << c.tinhDoDai(a) << endl;
    cout << b.tinhDoDai(c) << endl;

    if (thangHang(a, b, c)) cout << -1;
    else {
        cout << dienTich(a, b, c) << " ";
        cout << chuVi(a, b, c);
    }

    return 0;
}