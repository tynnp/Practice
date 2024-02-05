#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu;
    int mau;

    void rutGon() {
        int ucln = __gcd(this->tu, this->mau);
        this->tu /= ucln;
        this->mau /= ucln;
        if (this->mau < 0) 
            this->tu = -this->tu,
            this->mau = -this->mau;
        return;
    }

    double giaTri() {
        return (double) this->tu/this->mau;
    }

    friend istream& operator >> (istream &in, PhanSo &p) {
        in >> p.tu >> p.mau;
        p.rutGon();
        return in;
    }

    friend ostream& operator << (ostream &out, PhanSo p) {
        out << p.tu << "/" << p.mau;
        return out;
    }

    bool operator > (PhanSo other) {
        return this->giaTri() > other.giaTri();
    }

    bool operator< (PhanSo other) {
        return this->giaTri() < other.giaTri();
    }
};

int main() {
    int size; cin >> size;
    PhanSo arr[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    for (int i = 1; i < size; i++) {
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}