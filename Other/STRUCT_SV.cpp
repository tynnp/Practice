#include <iostream>
#include <iomanip>
using namespace std;

struct SinhVien {
    long long maSinhVien;
    string hoTen;
    double diemTrungBinh;

    friend istream &operator >> (istream &in, SinhVien &sv) {
        in >> sv.maSinhVien;
        in.ignore();
        getline(in, sv.hoTen);
        in >> sv.diemTrungBinh;
        return in;
    }

    friend ostream &operator << (ostream &out, SinhVien sv) {
        out << sv.maSinhVien << endl;
        out << sv.hoTen << endl;
        out << fixed << setprecision(1);
        out << sv.diemTrungBinh;
        return out;
    }
};

int main() {
    int n;
    cin >> n;

    SinhVien arr[n];
    for (SinhVien &x : arr) cin >> x;

    for (SinhVien x : arr) 
        if (x.diemTrungBinh >= 7) 
            cout << x << endl;
    
    return 0;
}