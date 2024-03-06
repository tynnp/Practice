#include <iostream>
using namespace std;

struct HocSinh {
    string hoTen;
    double diemVan;
    double diemToan;
    
    friend istream &operator >> (istream &in, HocSinh &hs) {
        getline(in, hs.hoTen);
        in >> hs.diemVan >> hs.diemToan;
        return in;
    }
    
    double diemTrungBinh() {
        return (diemVan + diemToan)/ 2;
    }
    
    string xepLoai() {
        if (diemTrungBinh() >= 8) return "Gioi";
        else if (diemTrungBinh() >= 7) return "Kha";
        else if (diemTrungBinh() >= 5) return "Trung Binh";
        else return "Yeu";
    }
     
    friend ostream &operator << (ostream &out, HocSinh hs) {
        out << hs.hoTen << endl;
        out << hs.diemVan << " " << hs.diemToan << endl;
        out << hs.diemTrungBinh() << endl;
        out << hs.xepLoai() << endl;
        return out;
    }
};

int main() {
    HocSinh a;
    cin >> a;
    cout << a;
    return 0;
}
