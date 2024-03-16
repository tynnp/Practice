#include <iostream>
using namespace std;

struct HocSinh {
    string tenHocSinh;
    double diemTrungBinh;

    friend istream &operator >> (istream &in, HocSinh &hs) {
        in.ignore();
        getline(in, hs.tenHocSinh);
        in >> hs.diemTrungBinh;
        return in;
    }

    friend ostream &operator << (ostream &out, HocSinh hs) {
        out << hs.tenHocSinh;
        return out;
    }
};

struct LopHoc {
    string tenLop;
    int siSo;
    HocSinh list[50];

    friend istream &operator >> (istream &in, LopHoc &lh) {
        in >> lh.tenLop;
        in >> lh.siSo;
        for (int i = 0; i < lh.siSo; i++)
            in >> lh.list[i];
        return in; 
    }

    friend ostream &operator << (ostream &out, LopHoc lh) {
        out << lh.tenLop << endl;
        for (int i = 0; i < lh.siSo; i++)
            out << lh.list[i] << endl;
        return out;
    }

    HocSinh hocSinhMax() {
        HocSinh max = list[0];
        for (int i = 1; i < siSo; i++)
            if (max.diemTrungBinh < list[i].diemTrungBinh)
                max = list[i];
        return max;
    }
};

int main() {
    int n;
    cin >> n;

    LopHoc arr[n];
    for (LopHoc &x : arr) cin >> x;
    for (LopHoc x : arr) cout << x << endl;

    LopHoc siSoMax = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i].siSo > siSoMax.siSo)
            siSoMax = arr[i];
    cout << siSoMax.tenLop << endl;

    HocSinh hocSinhDiemLonNhat = arr[0].hocSinhMax();
    for (int i = 1; i < n; i++) {
        if (arr[i].hocSinhMax().diemTrungBinh > hocSinhDiemLonNhat.diemTrungBinh)
            hocSinhDiemLonNhat = arr[i].hocSinhMax();
    }

    cout << hocSinhDiemLonNhat;
    return 0;
}