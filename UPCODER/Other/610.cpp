#include <iostream>
using namespace std;

struct MatHang {
    string tenMatHang;
    int donGia;
    int soLuongTon;

    friend istream &operator >> (istream &in, MatHang &mt) {
        string str;
        getline(in, mt.tenMatHang, '-');

        in >> mt.donGia;
        in.ignore();

        in >> mt.soLuongTon;
        in.ignore();
        
        return in;
    }

    friend ostream &operator << (ostream &out, MatHang mt) {
        out << "Ten: " << mt.tenMatHang << endl;
        out << "DonGia: " << mt.donGia << "d" << endl;
        out << "SoLuongTon: " << mt.soLuongTon << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    MatHang arr[n];
    for (auto &x : arr) cin >> x;
    for (auto x : arr) cout << x;

    return 0;
}