#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct Diem {
    int x, y;

    friend istream& operator >> (istream &in, Diem &diem) {
        in >> diem.x >> diem.y;
        return in;
    }

    friend ostream& operator << (ostream &out, Diem diem) {
        out << "(" << diem.x << ", " << diem.y << ")";
        return out;
    }

    double operator - (Diem other) {
        return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2));
    }
};

struct HCN {
    Diem a, b, c, d;

    friend istream& operator >> (istream &in, HCN &hcn) {
        in >> hcn.a >> hcn.b >> hcn.c >> hcn.d;
        return in;
    }

    friend ostream& operator << (ostream &out, HCN hcn) {
        out << hcn.a << hcn.b << hcn.c << hcn.d;
        return out;
    }

    double dienTich() {
        double ab = this->a - this->b;
        double bc = this->b - this->c;
        return ab * bc;
    }

    double operator + (HCN other) {
        return this->dienTich() + other.dienTich();
    }

    bool operator < (HCN other) {
        return this->dienTich() < other.dienTich();
    }

    bool operator > (HCN other) {
        return this->dienTich() > other.dienTich();
    }
};

struct TGV {
    Diem a, b, c;

    friend istream& operator >> (istream &in, TGV &tgv) {
        in >> tgv.a >> tgv.b >> tgv.c;
        return in;
    }

    friend ostream& operator << (ostream &out, TGV tgv) {
        out << tgv.a << tgv.b << tgv.c;
        return out;
    }

    double dienTich() {
        double ab = this->a - this->b;
        double bc = this->b - this->c;
        double ca = this->c - this->a;
        double p = (ab + bc + ca)/2;
        return sqrt(p * (p - ab) * (p - bc) * (p - ca));
    }

    double operator + (TGV other) {
        return this->dienTich() + other.dienTich();
    }

    bool operator < (TGV other) {
        return this->dienTich() < other.dienTich();
    }

    bool operator > (TGV other) {
        return this->dienTich() > other.dienTich();
    }
};

struct HT {
    Diem toaDo;
    double banKinh;

    friend istream& operator >> (istream &in, HT &ht) {
        in >> ht.toaDo >> ht.banKinh;
        return in;
    }

    friend ostream& operator << (ostream &out, HT ht) {
        out << "(" << ht.toaDo.x << ", " << ht.toaDo.y << ", " << ht.banKinh << ")";
        return out;
    }

    double dienTich() {
        return this->banKinh * this->banKinh * 3.14;
    }

    double operator + (HT other) {
        return this->dienTich() + other.dienTich();
    }

    bool operator < (HT other) {
        return this->dienTich() < other.dienTich();
    }

    bool operator > (HT other) {
        return this->dienTich() > other.dienTich();
    }
};

int main() {
    ifstream ifile; ifile.open("HINH.inp");
    ofstream ofile; ofile.open("HINH.out");
    
    HCN hcn1, hcn2; ifile >> hcn1 >> hcn2;
    TGV tgv1, tgv2; ifile >> tgv1 >> tgv2;
    HT ht1, ht2; ifile >> ht1 >> ht2;

    ofile << hcn1 << " " << hcn2 << endl;
    ofile << tgv1 << " " << tgv2 << endl;
    ofile << ht1 << " " << ht2 << endl;

    ofile << hcn1 + hcn2 << endl;
    ofile << tgv1 + tgv2 << endl;
    ofile << ht1 + ht1 << endl;

    if (hcn1 > hcn2) ofile << "1 > 2" << endl;
    else if (hcn1 < hcn2) ofile << "1 < 2" << endl;
    else ofile << "1 = 2" << endl;

    if (tgv1 > tgv2) ofile << "1 > 2" << endl;
    else if (tgv1 < tgv2) ofile << "1 < 2" << endl;
    else ofile << "1 = 2" << endl;

    if (ht1 > ht2) ofile << "1 > 2" << endl;
    else if (ht1 < ht2) ofile << "1 < 2" << endl;
    else ofile << "1 = 2" << endl;
 
    ifile.close();
    ofile.close();
    return 0;
}