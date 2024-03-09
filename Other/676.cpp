#include <iostream>
#include <iomanip>
using namespace std;

struct HocSinh {
    string tenHocSinh;
    int diemToan;
    int diemVan;
    double diemTrungBinh;

    bool checkGioi() {
        return diemVan >= 8 && diemToan >= 8;
    }

    friend istream &operator >> (istream &in, HocSinh &hs) {
        in.ignore();
        getline(in, hs.tenHocSinh);
        in >> hs.diemToan >> hs.diemVan >> hs.diemTrungBinh;
        return in;
    }

    friend ostream &operator << (ostream &out, HocSinh hs) {
        out << fixed << setprecision(1);
        out << hs.tenHocSinh << " - Toan: " << hs.diemToan;
        out << " - Van: " << hs.diemVan << " - DiemTB: " << hs.diemTrungBinh;
        return out;
    }
};

int main() {
    int n, cnt = 0;
    cin >> n;

    HocSinh list[n];
    for (HocSinh &x : list) cin >> x;

    for (HocSinh x : list) {
        cout << x << endl;
        if (x.checkGioi()) cnt++;
    }

    cout << "So luong HSG: " << cnt;
    return 0;
}