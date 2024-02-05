#include <iostream>
#include <cmath>
using namespace std;

struct Diem {
    int x; 
    int y;

    friend istream& operator >> (istream &in, Diem &diem) {
        in >> diem.x >> diem.y;
        return in;
    }

    friend ostream& operator << (ostream &out, Diem diem) {
        out << "(" << diem.x << "," << diem.y << ")";
        return out;
    }

    double operator - (Diem diem) {
        return sqrt(pow(diem.x - this->x, 2) + pow(diem.y - this->y, 2));
    }

    bool operator == (Diem diem) {
        return this->x == diem.x && this->y == diem.y;
    }
};

struct DuongTron {
    Diem toaDo;
    double banKinh;

    double chuVi() {
        return 2*3.14*this->banKinh;
    }

    double dienTich() {
        return 3.14*this->banKinh*this->banKinh;
    }

    friend istream& operator >> (istream &in, DuongTron &duongTron) {
        in >> duongTron.toaDo >> duongTron.banKinh;
        return in;
    }

    friend ostream& operator << (ostream &out, DuongTron duongTron) {
        out << duongTron.toaDo << " " << duongTron.banKinh;
        return out;
    }

    bool operator == (DuongTron duongTron) {
        return this->chuVi() == duongTron.chuVi();
    }

    bool operator < (DuongTron duongTron) {
        return this->chuVi() < duongTron.chuVi();
    }

    double operator + (DuongTron duongTron) {
        return this->dienTich() + duongTron.dienTich();
    }
};

string viTriTuongDoi(DuongTron a, DuongTron b) {
    double khoangCachTam = a.toaDo - b.toaDo;
    if (khoangCachTam == 0) return "DT";
    if (abs(a.banKinh - b.banKinh) < khoangCachTam && khoangCachTam < a.banKinh + b.banKinh) return "C";
    if (abs(a.banKinh - b.banKinh) == khoangCachTam) return "TXT";
    if (abs(a.banKinh - b.banKinh) > khoangCachTam) return "DN";
    if (a.banKinh + b.banKinh == khoangCachTam) return "TXN";
    if (a.banKinh + b.banKinh < khoangCachTam) return "NN";
}

int main() {
    DuongTron a, b;
    cin >> a >> b;

    cout << a << endl;
    cout << b << endl;

    double dienTich = a + b;
    cout << roundf(dienTich * 1000) / 1000 << endl;

    if (a == b) cout << "1 = 2" << endl;
    else if (a < b) cout << "1 < 2" << endl;
    else cout << "1 > 2" << endl;

    cout << viTriTuongDoi(a, b);
    return 0;
}