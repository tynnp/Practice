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

    SoPhuc operator * (SoPhuc other) {
        SoPhuc res;
        res.thuc = this->thuc*other.thuc - this->ao*other.ao;
        res.ao = this->thuc*other.ao + this->ao*other.thuc;
        return res;
    }

    bool operator > (SoPhuc other) {
        if (this->thuc > other.thuc) return true;
        else if (this->thuc == other.thuc) 
            return this->ao > other.ao;
        return false;
    }
};

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("input.txt");
    ofile.open("output.txt");

    int n;
    ifile >> n;
    SoPhuc arr[n], max, tong, tich;
    for (SoPhuc &x : arr) ifile >> x;

    max = tong = tich = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        tong = tong + arr[i];
        tich = tich * arr[i];
    }

    ofile << max << endl;
    ofile << tong << endl;
    ofile << tich << endl;

    ifile.close();
    ofile.close();
    return 0;
}