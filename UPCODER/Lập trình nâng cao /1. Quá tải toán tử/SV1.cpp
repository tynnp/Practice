#include <iostream>
using namespace std;

struct SinhVien {
    string hoVaTen;
    double diem[3];

    friend istream& operator >> (istream &in, SinhVien &sinhVien) {
        getline(in, sinhVien.hoVaTen);
        for (double &x : sinhVien.diem) in >> x;
        return in;
    }

    friend ostream& operator << (ostream &out, SinhVien sinhVien) {
        out << sinhVien.hoVaTen;
        // for (double x : sinhVien.diem) out << x << " ";
        // out << sinhVien.diemTrungBinh();
        return out;
    }

    double diemTrungBinh() {
        double res = 0;
        double a = this->diem[0];
        double b = this->diem[1];
        double c = this->diem[2];
        res = (a + b + c) / 3;
        return res;
    }

    bool operator < (SinhVien sinhVien) {
        return this->diemTrungBinh() < sinhVien.diemTrungBinh();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SinhVien sinhVien[100];
    int n = 0;
    while (cin >> sinhVien[n]) {
        cin.ignore();
        n++;
    }

    SinhVien max = sinhVien[0];
    for (int i = 1; i < n; i++) 
        if (max < sinhVien[i]) max = sinhVien[i];

    cout << max;
    return 0;
}