#include <iostream>
#include <iomanip>
using namespace std;

struct HCN {
    double dai, rong;

    friend istream& operator >> (istream &in, HCN &hcn) {
        in >> hcn.dai >> hcn.rong;
        return in;
    } 

    friend ostream& operator << (ostream &out, HCN hcn) {
        out << "[HCN] " << hcn.dai << "," << hcn.rong;
        return out;
    }

    double chuVi() {
        return (double) (this->dai + this->rong) * 2;
    }

    bool operator < (HCN other) {
        return this->chuVi() < other.chuVi();
    }

    double operator + (double n) {
        return this->chuVi() + n;
    }
};

bool operator == (HCN hcn, int n) {
    return true;
}

template <typename T>
struct Array {
    int size = 0;
    T values[1000];

    friend istream& operator >> (istream &in, Array &arr) {
        T n; 
        while (in >> n)
            arr.values[arr.size++] = n;
        return in;
    }

    T min() {
        T res = this->values[0];
        for (int i = 1; i < this->size; i++)
            if (this->values[i] < res)
                res = this->values[i];
        return res;
    }

    void sum() {
        double res = 0;
        for (int i = 0; i < this->size; i++)
            res = this->values[i] + res;
        
        T tmp;
        if (tmp == 9999) cout << fixed << setprecision(1) << res;
        else cout << (int) res;

        return;
    }

    friend ostream& operator << (ostream &out, Array arr) {
        out << arr.min() << endl;
        arr.sum();
        return out;
    }
};

int main() {
    char c; cin >> c;
    Array<int> arrInt;
    Array<HCN> arrHCN;

    if (c == 'N') {
        cin >> arrInt;
        cout << arrInt;

    } else if (c == 'H') {
        cin >> arrHCN;
        cout << arrHCN;
    }

    return 0;
}