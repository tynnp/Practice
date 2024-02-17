#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct SoPhuc {
    int thuc, ao;

    friend istream& operator >> (istream &in, SoPhuc &sp) {
        in >> sp.thuc >> sp.ao;
        return in;
    } 

    friend ostream& operator << (ostream &out, SoPhuc sp) {
        out << "{";
        if (sp.thuc != 0) out << sp.thuc;

        if (sp.ao != 0) {
            out << (sp.ao < 0 ? "-" : "+");
            if (abs(sp.ao) != 1) out << abs(sp.ao);
            out << "i";
        }
        out << "}";

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

    double modun() {
        return sqrt(this->thuc*this->thuc + this->ao*this->ao);
    }
};

struct Array {
    int size;
    SoPhuc* values;

    friend istream& operator >> (istream &in, Array &arr) {
        arr.size = 0;
        arr.values = new SoPhuc[10001];
        SoPhuc tmp;
        while (cin >> tmp)
            arr.values[arr.size++] = tmp; 
        return in;
    }

    SoPhuc tongSoPhuc() {
        SoPhuc res = this->values[0];
        for (int i = 1; i < this->size; i++) 
            res = res + this->values[i];
        return res;
    }

    friend ostream& operator << (ostream &out, Array arr) {
        for (int i = 0; i < arr.size; i++) 
            out << arr.values[i] << " "; out << endl;

        out << fixed << setprecision(2);
        for (int i = 0; i < arr.size; i++)
            out << arr.values[i].modun() << " "; out << endl;

        out << arr.tongSoPhuc();
        return out;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Array arr;
    cin >> arr;
    cout << arr;
    return 0;
}