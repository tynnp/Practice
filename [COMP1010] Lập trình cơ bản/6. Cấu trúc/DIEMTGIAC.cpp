#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

struct Diem {
    int x, y;

    void nhap() {
        cin >> x >> y;
        return;
    }

    void xuat() {
        cout << "(" << x << "," << y << ")";
        return;
    }

    double khoangCach(Diem other) {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    bool trungNhau(Diem other) {
        return x == other.x && y == other.y;
    }
};

struct TamGiac {
    Diem A, B, C;

    friend istream& operator >> (istream& in, TamGiac& tamGiac) {
        tamGiac.A.nhap();
        tamGiac.B.nhap(); 
        tamGiac.C.nhap();
        return in;
    }

    friend ostream& operator << (ostream& out, TamGiac tamGiac) {
        tamGiac.A.xuat();
        tamGiac.B.xuat(); 
        tamGiac.C.xuat();
        return out;
    }

    double chuViTamGiac() {
        return A.khoangCach(B) + B.khoangCach(C) + C.khoangCach(A);
    }

    double soSanhChuVi(TamGiac other) {
        return chuViTamGiac() - other.chuViTamGiac();
    }

    bool trungNhau(TamGiac other) {
        if ((A.trungNhau(other.A) || A.trungNhau(other.B) || A.trungNhau(other.C)) &&
            (B.trungNhau(other.B) || B.trungNhau(other.C) || B.trungNhau(other.A)) &&
            (C.trungNhau(other.C) || C.trungNhau(other.A) || C.trungNhau(other.B))) return true;
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TamGiac TG1, TG2;
    cin >> TG1 >> TG2;
    cout << TG1 << endl;
    cout << TG2 << endl;
    cout << (TG1.soSanhChuVi(TG2) < 0 ? "TRUE\n" : "FALSE\n");
    cout << (TG1.trungNhau(TG2) ? "TRUE" : "FALSE");
    
    return 0;
}