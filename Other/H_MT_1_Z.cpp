#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct SoPhuc {
    int thuc;
    int ao;

    friend istream& operator >> (istream &in, SoPhuc &sp) {
        in >> sp.thuc >> sp.ao;
        return in;
    }

    friend ostream& operator << (ostream &out, SoPhuc sp) {
        if (sp.thuc != 0) out << sp.thuc;
        if (sp.ao != 0) {
            if (sp.ao > 0 && sp.thuc != 0) out << " + ";
            if (sp.ao < 0) out << " - ";
            if (abs(sp.ao) != 1) 
                out << abs(sp.ao);
            out << "*i";
        } 
        return out;
    }

    SoPhuc operator + (SoPhuc other) {
        SoPhuc res;
        res.thuc = this->thuc + other.thuc;
        res.ao = this->ao + other.ao;
        return res;
    }

    SoPhuc operator - (SoPhuc other) {
        SoPhuc res;
        res.thuc = this->thuc - other.thuc;
        res.ao = this->ao - other.ao;
        return res;
    }

    SoPhuc operator * (SoPhuc other) {
        SoPhuc res;
        res.thuc = thuc*other.thuc - ao*other.ao; 
        res.ao = ao*other.thuc + thuc*other.ao;
        return res;
    }

    bool operator > (SoPhuc other) {
        if (thuc > other.thuc) return true; 
        else if (thuc == other.thuc && ao > other.ao) return true;
        return false;
    }

};

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    int n = 0;
    SoPhuc arr[n];
    while (ifile >> arr[n]) n++;

    SoPhuc tong = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        tong = tong + arr[i];
    }

    ofile << max << endl << tong;
    ifile.close();
    ofile.close();
    return 0;
}