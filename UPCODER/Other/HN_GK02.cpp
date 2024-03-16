#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

struct Diem {
    int tung, hoanh;

    friend istream &operator >> (istream &in, Diem &diem) {
        in >> diem.tung >> diem.hoanh;
        return in;
    }

    friend ostream &operator << (ostream &out, Diem diem) {
        out << "(" << diem.tung << ", " << diem.hoanh << ")";
        return out;
    }

    double operator + (Diem other) {
        return sqrt(pow(other.tung - tung, 2) + pow(other.hoanh - hoanh, 2));
    }

    bool operator == (Diem other) {
        return tung == other.tung && hoanh == other.hoanh;
    }
};

struct TamGiac {
    Diem A, B, C;

    friend istream &operator >> (istream &in, TamGiac &tamGiac) {
        in >> tamGiac.A >> tamGiac.B >> tamGiac.C;
        return in;
    }

    friend ostream &operator << (ostream &out, TamGiac &tamGiac) {
        out << tamGiac.A << "," << tamGiac.B << "," << tamGiac.C;
        return out;
    }

    double chuVi() {
        double AB = A + B;
        double BC = B + C;
        double CA = C + A;
        return AB + BC + CA;
    }

    double operator + (TamGiac other) {
        return chuVi() + other.chuVi();
    }

    bool operator > (TamGiac other) {
        return chuVi() > other.chuVi();
    }

    bool operator == (TamGiac other) {
        return ((A == other.A || A == other.B || A == other.C) && 
        (B == other.A || B == other.B || B == other.C) && 
        (C == other.A || C == other.B || C == other.C));
    }
};

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    int n = 0;
    TamGiac arr[100];
    while (ifile >> arr[n]) n++;

    double tongChuVi = arr[0].chuVi();
    TamGiac tamGiacLonNhat = arr[0];

    for (int i = 1; i < n; i++) {
        tongChuVi += arr[i].chuVi();
        if (arr[i] > tamGiacLonNhat)
            tamGiacLonNhat = arr[i];
    }

    ofile << tongChuVi << endl;
    ofile << tamGiacLonNhat << endl;

    ifile.close();
    ofile.close();
    return 0;
}