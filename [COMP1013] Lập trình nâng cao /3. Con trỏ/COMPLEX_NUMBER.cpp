#include <iostream>
#include <iomanip>
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
        out << "{";
        if (sp.thuc != 0) out << sp.thuc;

        if (sp.ao != 0) {
            if (sp.ao > 0 && sp.thuc != 0) out << "+";
            if (sp.ao < 0) out << "-";
            if (abs(sp.ao) != 1) 
                out << abs(sp.ao);
            out << "i";
        } 
        out << "}";
        return out;
    }

    SoPhuc operator + (SoPhuc sp) {
        SoPhuc res;
        res.thuc = this->thuc + sp.thuc;
        res.ao = this->ao + sp.ao;
        return res;
    }

    SoPhuc operator - (SoPhuc sp) {
        SoPhuc res;
        res.thuc = this->thuc - sp.thuc;
        res.ao = this->ao - sp.ao;
        return res;
    }

    double modun() {
        return sqrt(this->thuc*this->thuc + this->ao*this->ao);
    }
};

struct DaySoPhuc {
    int size;
    SoPhuc *values;

    friend istream& operator >> (istream &in, DaySoPhuc &arr) {
        arr.size = 0;
        arr.values = new SoPhuc[100];
        while (in >> arr.values[arr.size]) arr.size++;
        return in;
    }

    friend ostream& operator << (ostream &out, DaySoPhuc arr) {
        for (int i = 0; i < arr.size; i++)
            out << *(arr.values + i) << " ";
        return out;
    }

    SoPhuc tinhTong() {
        SoPhuc res = *(this->values);
        for (int i = 1; i < this->size; i++)
            res = res + *(this->values + i);
        return res;
    }

    SoPhuc tinhHieu() {
        SoPhuc res = *(this->values);
        for (int i = 1; i < this->size; i++)
            res = res - *(this->values + i);
        return res;
    }

    void tinhModun() {
        cout << fixed << setprecision(2);
        for (int i = 0; i < this->size; i++)
            cout << this->values[i].modun() << " ";
        return;
    }
};

int main() {
    DaySoPhuc daySoPhuc; 
    cin >> daySoPhuc;

    cout << daySoPhuc << endl;
    daySoPhuc.tinhModun(); cout << endl;

    cout << daySoPhuc.tinhTong();
    return 0;
}